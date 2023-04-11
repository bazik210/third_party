/* SCE CONFIDENTIAL
PlayStation(R)3 Programmer Tool Runtime Library 310.001
* Copyright (C) 2004 Sony Computer Entertainment Inc. 
* All Rights Reserved.
*/
#define __calcQuot(xexp) n = xexp;					\
  vec_uchar16 negxexpmask = (vec_uchar16)spu_cmpgt(spu_splats(0), n);	\
  n = spu_sel(n, spu_add(n,2), negxexpmask);				\
									\
  quot = spu_add(spu_rlmaska(n,-2), spu_rlmaska(n,-4));			\
  quot = spu_add(quot, spu_rlmaska(quot, -4));				\
  quot = spu_add(quot, spu_rlmaska(quot, -8));				\
  quot = spu_add(quot, spu_rlmaska(quot,-16));				\
  vec_int4 r = spu_sub(spu_sub(n,quot), spu_sl(quot,1));		\
  quot = spu_add(							\
		 quot,							\
		 spu_rlmaska(						\
			     spu_add(					\
				     spu_add(r,5),			\
				     spu_sl (r,2)			\
				     ),					\
			     -4						\
			     )						\
		 );							\

#define _CBRTF_H_cbrt2 1.2599210498948731648             // 2^(1/3)
#define _CBRTF_H_sqr_cbrt2 1.5874010519681994748         // 2^(2/3)

_FUNC_DEF(vec_float4, cbrtf4, (vec_float4 x)) 
{
  vec_float4 zeros = spu_splats(0.0f);
  vec_uchar16 zeromask = (vec_uchar16)spu_cmpeq(x, zeros);
  vec_int4 xexp, n;
  vec_float4 sgnmask = (vec_float4)spu_splats(0x7FFFFFFF);
  vec_uchar16 negmask = (vec_uchar16)spu_cmpgt(spu_splats(0.0f), x);
  x = spu_and(x, sgnmask);

  x = frexpf4(x, &xexp);
  vec_float4 p = spu_madd(
			  spu_madd(x, spu_splats(-0.191502161678719066f), spu_splats(0.697570460207922770f)),
			  x,
			  spu_splats(0.492659620528969547f)
			  );
  vec_float4 p3 = spu_mul(p, spu_mul(p, p));
  vec_int4 quot; 
  __calcQuot(xexp);
  vec_int4 modval = spu_sub(spu_sub(xexp,quot), spu_sl(quot,1)); // mod = xexp - 3*quotient
  vec_float4 factor = spu_splats((float)(1.0/_CBRTF_H_sqr_cbrt2));
  factor = spu_sel(factor, spu_splats((float)(1.0/_CBRTF_H_cbrt2)), spu_cmpeq(modval,-1));
  factor = spu_sel(factor, spu_splats((float)(      1.0)), spu_cmpeq(modval, 0));
  factor = spu_sel(factor, spu_splats((float)(    _CBRTF_H_cbrt2)), spu_cmpeq(modval, 1));
  factor = spu_sel(factor, spu_splats((float)(_CBRTF_H_sqr_cbrt2)), spu_cmpeq(modval, 2));

  vec_float4 pre  = spu_mul(p, factor);
  vec_float4 numr = spu_madd(x , spu_splats(2.0f), p3);
  vec_float4 denr = spu_madd(p3, spu_splats(2.0f), x );
  vec_float4 res = spu_mul(pre, divf4(numr, denr));
  res = ldexpf4(res, quot);

  return spu_sel(spu_sel(res, spu_orc(res,sgnmask), negmask),
		 zeros,
		 zeromask);
}

/*
_FUNC_DEF(vec_float4, cbrtf4, (vec_float4 x))
{
  vec_uchar16 neg  = (vec_uchar16)spu_cmpgt(spu_splats(0.0f), x);
  vec_float4  sbit = (vec_float4)spu_splats((int)0x80000000);
  vec_float4 absx = spu_andc(x, sbit);
  vec_float4 res = exp2f4(spu_mul(spu_splats((float)0.3333333333333f), log2f4(absx)));
  res = spu_sel(res, spu_or(sbit, res), neg);
  return res;
}
*/
