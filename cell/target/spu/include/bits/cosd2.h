/* SCE CONFIDENTIAL
PlayStation(R)3 Programmer Tool Runtime Library 310.001
* Copyright (C) 2007 Sony Computer Entertainment Inc. 
* All Rights Reserved.
*/
#include "sincos_c.h"

//
//     Computes the cosine  of the each of two double slots.
//
_FUNC_DEF(vec_double2, cosd2, (vec_double2 x))
{
    vec_double2 xl,xl2,xl3,res;
    vec_double2 nan = (vec_double2)spu_splats(0x7ff8000000000000ull);
    vec_uchar16 copyEven = __extension__ (vec_uchar16)(vec_uint4){ 0x00010203, 0x00010203, 0x08090a0b, 0x08090a0b };
    vec_double2 tiny = (vec_double2)spu_splats(0x3e40000000000000ull);

    // Range reduction using : xl = angle * TwoOverPi;
    //  
    xl = spu_mul(x, spu_splats((double)0.63661977236758134307553505349005744L));

    // Find the quadrant the angle falls in
    // using:  q = (int) (ceil(abs(x))*sign(x))
    //
    xl = spu_add(xl,spu_sel(spu_splats((double)0.5L),xl,spu_splats(0x8000000000000000ull)));
    vec_float4 xf = spu_roundtf(xl);
    vec_int4 q = spu_convts(xf,0);
    q = spu_shuffle(q,q,copyEven);

     
    // Compute an offset based on the quadrant that the angle falls in
    // 
    vec_int4 offset = spu_add(spu_splats(1), spu_and(q,spu_splats(0x3)));

    // Remainder in range [-pi/4..pi/4]
    //
    vec_float4 qf = spu_convtf(q,0);
    vec_double2 qd = spu_extend(qf);
    vec_double2 p1 = spu_nmsub(qd,spu_splats((double)_SINCOS_KC1D),x);
    xl = spu_nmsub(qd,spu_splats((double)_SINCOS_KC2D),p1);

    // Check if |xl| is a really small number
    //
    vec_double2 absXl = (vec_double2)spu_andc((vec_ullong2)xl, spu_splats(0x8000000000000000ull));
    vec_ullong2 isTiny = (vec_ullong2)cmpgtd2(tiny,absXl);

    // Compute x^2 and x^3
    //
    xl2 = spu_mul(xl,xl);
    xl3 = spu_mul(xl2,xl);
    
    // Compute both the sin and cos of the angles
    // using a polynomial expression:
    //   cx = 1.0f + xl2 * ((((((c0 * xl2 + c1) * xl2 + c2) * xl2 + c3) * xl2 + c4) * xl2 + c5), and
    //   sx = xl + xl3 * (((((s0 * xl2 + s1) * xl2 + s2) * xl2 + s3) * xl2 + s4) * xl2 + s5)
    //

    vec_double2 ct0 = spu_mul(xl2,xl2);
    vec_double2 ct1 = spu_madd(spu_splats((double)_SINCOS_CC0D),xl2,spu_splats((double)_SINCOS_CC1D));
    vec_double2 ct2 = spu_madd(spu_splats((double)_SINCOS_CC2D),xl2,spu_splats((double)_SINCOS_CC3D));
    vec_double2 ct3 = spu_madd(spu_splats((double)_SINCOS_CC4D),xl2,spu_splats((double)_SINCOS_CC5D));
    vec_double2 st1 = spu_madd(spu_splats((double)_SINCOS_SC0D),xl2,spu_splats((double)_SINCOS_SC1D));
    vec_double2 st2 = spu_madd(spu_splats((double)_SINCOS_SC2D),xl2,spu_splats((double)_SINCOS_SC3D));
    vec_double2 st3 = spu_madd(spu_splats((double)_SINCOS_SC4D),xl2,spu_splats((double)_SINCOS_SC5D));
    vec_double2 ct4 = spu_madd(ct2,ct0,ct3);
    vec_double2 st4 = spu_madd(st2,ct0,st3);
    vec_double2 ct5 = spu_mul(ct0,ct0);
    
    vec_double2 ct6 = spu_madd(ct5,ct1,ct4);
    vec_double2 st6 = spu_madd(ct5,st1,st4);

    vec_double2 cx = spu_madd(ct6,xl2,spu_splats((double)1.0L));
    vec_double2 sx = spu_madd(st6,xl3,xl);

    // Small angle approximation: sin(tiny) = tiny, cos(tiny) = 1.0
    //
    sx = spu_sel(sx,xl,isTiny);
    cx = spu_sel(cx,spu_splats((double)1.0L),isTiny);

    // Use the cosine when the offset is odd and the sin
    // when the offset is even
    //
    vec_ullong2 mask1 = (vec_ullong2)spu_cmpeq(spu_and(offset,(int)0x1),spu_splats((int)0));
    res = spu_sel(cx,sx,mask1);

    // Flip the sign of the result when (offset mod 4) = 1 or 2
    //
    vec_ullong2 mask2 = (vec_ullong2)spu_cmpeq(spu_and(offset,(int)0x2),spu_splats((int)0));
    mask2 = spu_shuffle(mask2,mask2,copyEven);
    res = spu_sel((vec_double2)spu_xor(spu_splats(0x8000000000000000ull),(vec_ullong2)res),res,mask2);
    // if input = +/-Inf return NAN
    //
    res = spu_sel(res, nan, cmpinfd2(x));

    // if input = 0 or denorm return or 1.0 
    //
    vec_ullong2 zeroMask = cmpzerodenormd2(x);
    res = spu_sel(res,spu_splats((double)1.0L),zeroMask);
    return res;
}


