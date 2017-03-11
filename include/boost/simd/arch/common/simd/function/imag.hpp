//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IMAG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IMAG_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/constant/zero.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  BOOST_DISPATCH_OVERLOAD(imag_
                         , (typename A0,typename X)
                         , bd::cpu_
                         , bs::pack_<bd::arithmetic_<A0>,X>
                         )
  {
    BOOST_FORCEINLINE A0 operator()( const A0& ) const BOOST_NOEXCEPT
    {
      return Zero<A0>();
    }
  };
} } }

#endif
