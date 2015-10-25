//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NONE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NONE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-reduction

    Computes none value of its parameter.

  **/
  template<typename T> auto none(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-reduction

      Function object tied to simd::none

      @see simd::none
    **/
    const boost::dispatch::functor<tag::none_> none = {};
  }
} }
#endif

#include <boost/simd/function/definition/none.hpp>
#include <boost/simd/arch/common/scalar/function/none.hpp>
//#include <boost/simd/arch/common/function/simd/none.hpp>

#endif