#include <cstdio>
#include <string>

#include <set>


size_t log2( uint32_t v );
void maskEnum( const uint32_t val , const uint32_t mask );
void printUsage( const std::string &a );
void printArg( const int argc , char *argv[] );


int main( const int argc , char *argv[] )
{
	// input handling
	if( argc != 3 )
	{
		printUsage( argv[0] );
		exit( EXIT_FAILURE );
	}

	const uint32_t val = strtoul( argv[1] , NULL , 0 );
	const uint32_t mask = strtoul( argv[2] , NULL , 0 );
	maskEnum( val , mask );

//	system( "pause" );
	return 0;
}


void maskEnum( const uint32_t val , const uint32_t mask )
{
	// scan
	const uint32_t base = val & mask;
	std::set< uint32_t > my_set;
	my_set.emplace( base );

	uint32_t p = 1;
	const uint32_t inv_mask = ~mask;
	const size_t max_range = std::max( log2( val ) , log2( mask ) );
	for( size_t i = 0 ; i < max_range ; ++i )
	{
		if( p & inv_mask )  // encountered don't care bit
		{
			decltype( my_set ) tmp_set;
			for( const auto &j : my_set )
			{
				tmp_set.emplace( j + p );
				// printf("new: %d\n" , j+p);
			}

			for( const auto &j : tmp_set )
			{
				my_set.emplace( std::move( j ) );
			}
		}
		p <<= 1;
	}

	for( const auto &i : my_set )
	{
		printf( "%zu\n" , i );
	}

	return;
}


size_t log2( uint32_t v )
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


void printUsage( const std::string &a )
{
	fprintf( stderr , "\n" );
	fprintf( stderr , "Mask Enumerator\n\n" );
	fprintf( stderr , "Usage: %s value mask\n" , a.c_str() );
	fprintf( stderr , "Example1: %s  0 65535\n" , a.c_str() );
	fprintf( stderr , "Example1: %s  0 0xfffef\n" , a.c_str() );
//	fprintf( stderr , "Example2: %s 50 0b11011\n" , a.c_str() );
	return;
}


void printArg( const int argc , char *argv[] )
{
	printf( "argc: %d\n" , argc );

	for( auto i = 1 ; i < argc ; ++i )
	{
		printf( "argv[%d]: %s\n" , i , argv[i] );
	}
	return;
}
