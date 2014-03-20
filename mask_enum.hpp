/* Copyright (C) 2014 Mike Tzou
*  For conditions of distribution and use, see copyright notice in file "COPYING"
*/

#ifndef mask_enum_HPP
#define mask_enum_HPP

#include <string>
#include <stdint.h>


class MaskEnum
{
	public:
		explicit MaskEnum( const uint32_t val , const uint32_t mask );
		size_t numOfResults() const;
		uint32_t getNum();  // only valid in range of [ 0 , numOfResult() - 1 ]


	private:
		size_t intLog2( uint32_t v ) const;

		const uint32_t base;
		uint32_t bit_base[ 32 ];  // don't care bit value
		size_t range;  // index for bit_base

		size_t counter;
};


#endif
