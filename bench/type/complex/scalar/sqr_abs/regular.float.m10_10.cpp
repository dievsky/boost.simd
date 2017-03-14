// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------


/// bench for functor sqr_abs in scalar mode for float type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/sqr_abs.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

template < class T > struct sqr_abs_bench
{
  BOOST_FORCEINLINE T operator()(const T & r, const T & i) const BOOST_NOEXCEPT
  {
    bs::complex<T> z{r, i};
    return bs::sqr_abs(z);
  }
};

DEFINE_SCALAR_BENCH(scalar_sqr_abs, sqr_abs_bench<float>());

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_sqr_abs, float>(-10, 10, -10, 10);
}
