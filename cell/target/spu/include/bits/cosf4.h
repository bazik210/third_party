/* SCE CONFIDENTIAL
PlayStation(R)3 Programmer Tool Runtime Library 310.001
* Copyright (C) 2004 Sony Computer Entertainment Inc. 
* All Rights Reserved.
*/
#include "sincos_c.h"

//
//     Computes the cosine of each of the four slots by using a polynomial approximation
//
_FUNC_DEF(vec_float4, cosf4, (vec_float4 x))
{
    vec_float4 xl,xl2,xl3,res;
    vec_int4   q;

    // Range reduction using : xl = angle * TwoOverPi;
    //  
    xl = spu_mul(x, spu_splats(0.63661977236f));

    // Find the quadrant the angle falls in
    // using:  q = (int) (ceil(abs(xl))*sign(xl))
    //
    xl = spu_add(xl,spu_sel(spu_splats(0.5f),xl,spu_splats(0x80000000)));
    q = spu_convts(xl,0);

     
    // Compute an offset based on the quadrant that the angle falls in
    // 
    vec_int4 offset = spu_add(spu_splats(1),spu_and(q,spu_splats((int)0x3)));

    // Remainder in range [-pi/4..pi/4]
    //
    vec_float4 qf = spu_convtf(q,0);
    vec_float4 p1 = spu_nmsub(qf,spu_splats(_SINCOS_KC1),x);
    xl  = spu_nmsub(qf,spu_splats(_SINCOS_KC2),p1);
    
    // Compute x^2 and x^3
    //
    xl2 = spu_mul(xl,xl);
    xl3 = spu_mul(xl2,xl);
    

    // Compute both the sin and cos of the angles
    // using a polynomial expression:
    //   cx = 1.0f + xl2 * ((C0 * xl2 + C1) * xl2 + C2), and
    //   sx = xl + xl3 * ((S0 * xl2 + S1) * xl2 + S2)
    //
    vec_float4 ct1 = spu_madd(spu_splats(_SINCOS_CC0),xl2,spu_splats(_SINCOS_CC1));
    vec_float4 st1 = spu_madd(spu_splats(_SINCOS_SC0),xl2,spu_splats(_SINCOS_SC1));

    vec_float4 ct2 = spu_madd(ct1,xl2,spu_splats(_SINCOS_CC2));
    vec_float4 st2 = spu_madd(st1,xl2,spu_splats(_SINCOS_SC2));
    
    vec_float4 cx = spu_madd(ct2,xl2,spu_splats(1.0f));
    vec_float4 sx = spu_madd(st2,xl3,xl);

    // Use the cosine when the offset is odd and the sin
    // when the offset is even
    //
    vec_uchar16 mask1 = (vec_uchar16)spu_cmpeq(spu_and(offset,(int)0x1),spu_splats((int)0));
    res = spu_sel(cx,sx,mask1);

    // Flip the sign of the result when (offset mod 4) = 1 or 2
    //
    vec_uchar16 mask2 = (vec_uchar16)spu_cmpeq(spu_and(offset,(int)0x2),spu_splats((int)0));
    res = spu_sel((vec_float4)spu_xor(spu_splats(0x80000000),(vec_uint4)res),res,mask2);

    return res;
    
}
