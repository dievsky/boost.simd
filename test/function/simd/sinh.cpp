//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/sinh.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_positive.hpp>


namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : -T(i);
    b[i] = bs::sinh(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::sinh(aa1), bb, 0.5);
}

STF_CASE_TPL("Check sinh on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

STF_CASE_TPL (" sinh",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::sinh;
  using p_t = bs::pack<T>;

  using r_t = decltype(sinh(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sinh(bs::Inf<p_t>()), bs::Inf<r_t>(), 0);
  STF_ULP_EQUAL(sinh(bs::Minf<p_t>()), bs::Minf<r_t>(), 0);
  STF_ULP_EQUAL(sinh(bs::Nan<p_t>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(sinh(bs::Zero<p_t>()), bs::Zero<r_t>(), 0);
  STF_EQUAL(bs::is_negative(bs::sinh(bs::Mzero<p_t>() )), bs::True<p_t>());
  STF_EQUAL(bs::is_positive(bs::sinh(bs::Zero<p_t>() )), bs::True<p_t>());
  STF_ULP_EQUAL(sinh(bs::One<p_t>()),p_t(1.1752011936438014568823818506), 0.5);
  STF_ULP_EQUAL(sinh(bs::Mone<p_t>()), p_t(-1.1752011936438014568823818506), 0.5);
  STF_ULP_EQUAL(sinh(bs::Half<p_t>()), p_t(0.52109530549374736162242562641149), 0.5);
}
