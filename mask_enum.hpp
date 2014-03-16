#ifndef mask_enum_HPP
#define mask_enum_HPP

#include <string>


class MaskEnum
{
	public:
		explicit MaskEnum( const uint32_t val , const uint32_t mask );
		uint32_t getOutput();
		bool haveMore() const;


	private:
		size_t intLog2( uint32_t v ) const;

		const uint32_t base;
		uint32_t bit_pos[ 32 ];  // don't care bit position
		size_t range;  // index for bit_pos

		size_t counter;
};


#endif
