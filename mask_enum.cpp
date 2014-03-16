#include "mask_enum.hpp"


MaskEnum::MaskEnum( const uint32_t val , const uint32_t mask ) : base( val & mask ) , range( 0 ) , counter( 0 )
{
	uint32_t p = 1;
	const uint32_t inv_mask = ~mask;
	const size_t max_i = std::max( intLog2( val ) , intLog2( mask ) );
	for( size_t i = 0 ; i <= max_i ; ++i )  // scan for don't care bits
	{
		if( p & inv_mask )  // encountered don't care bit
		{
			bit_pos[ range ] = i;
			++range;
		}
		p <<= 1;
	}

	return;
}


size_t MaskEnum::numOfResults() const
{
	return ( 1 << range );
}


uint32_t MaskEnum::getOutput()
{
	uint32_t result = base;
	for( size_t i = 0 ; i < range ; ++i )  // scan through each don't care bit
	{
		result += ( 1 << bit_pos[ i ] ) * ( ( counter >> i ) & 0b1 );
	}

	++counter;
	return result;
}


size_t MaskEnum::intLog2( uint32_t v ) const
{
	// from http://stackoverflow.com/questions/11376288/fast-computing-of-log2-for-64-bit-integers
	const size_t tab32[] =
	{
		0 ,  9,  1, 10, 13, 21,  2, 29,
		11, 14, 16, 18, 22, 25,  3, 30,
		8 , 12, 20, 28, 15, 17, 24,  7,
		19, 27, 23,  6, 26,  5,  4, 31
	};

	v |= ( v >> 1 );
	v |= ( v >> 2 );
	v |= ( v >> 4 );
	v |= ( v >> 8 );
	v |= ( v >> 16 );
	return tab32[( uint32_t )( v * 0x07C4ACDD ) >> 27];
}
