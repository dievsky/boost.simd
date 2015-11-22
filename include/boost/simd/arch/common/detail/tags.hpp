#ifndef BOOST_SIMD_ARCH_COMMON_DETAIL_TAGS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_DETAIL_TAGS_HPP_INCLUDED

namespace boost { namespace simd
{
  struct exp_;
  struct exp2_;
  struct exp10_;
  struct log_;
  struct log2_;
  struct log10_;
  namespace tag
  {
    typedef std::integral_constant<bool, false> not_simd_type;
    typedef std::integral_constant<bool, true>  simd_type;
    struct accu_tag{};

  }
} }

#endif
