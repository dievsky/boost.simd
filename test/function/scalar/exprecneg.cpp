//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/exprecneg.hpp>
#include <scalar_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/exp_1.hpp>

STF_CASE_TPL (" exprecneg",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::exprecneg;

  using r_t = decltype(exprecneg(T()));

  // return type conformity test
  STF_TYPE_IS(r_t,T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(exprecneg(bs::Inf<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(exprecneg(bs::Minf<T>()), bs::One<r_t>(), 0);
  STF_ULP_EQUAL(exprecneg(bs::Nan<T>()), bs::Nan<r_t>(), 0);
#endif
  STF_ULP_EQUAL(exprecneg(bs::Mone<T>()),bs::Exp_1<r_t>(), 0.5);
  STF_ULP_EQUAL(exprecneg(bs::One<T>()), bs::rec(bs::Exp_1<r_t>()), 0.5);
  STF_ULP_EQUAL(exprecneg(bs::Zero<T>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(exprecneg(bs::Mzero<T>()), bs::Inf<r_t>(), 0.5);
}
