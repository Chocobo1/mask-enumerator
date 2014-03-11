#ifndef mask_enum_HPP
#define mask_enum_HPP

#include <set>
#include <string>


class MaskEnum
{
		typedef std::set< uint32_t > MaskEnumSet;


	public:
		explicit MaskEnum( const uint32_t val , const uint32_t mask );
		const MaskEnum::MaskEnumSet *getOutput() const;


	private:
		size_t intLog2( uint32_t v ) const;

		MaskEnum::MaskEnumSet my_set;
};


#endif
