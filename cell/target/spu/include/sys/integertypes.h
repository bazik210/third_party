/*   SCE CONFIDENTIAL                                       */
/*   PlayStation(R)3 Programmer Tool Runtime Library 310.001 */
/*   Copyright (C) 2008 Sony Computer Entertainment Inc.    */
/*   All Rights Reserved.                                   */

#ifndef __SYS_SYS_INTEGERTYPES_H__
#define __SYS_SYS_INTEGERTYPES_H__

#include <sys/cdefs.h>

__C_STD_BEGIN typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef signed long long int64_t;
typedef unsigned long long uint64_t;
typedef signed int intptr_t;
typedef unsigned int uintptr_t;

__C_STD_END
#if defined(__STD_USING)
	using __CSTD int8_t;
using __CSTD uint8_t;
using __CSTD int16_t;
using __CSTD uint16_t;
using __CSTD int32_t;
using __CSTD uint32_t;
using __CSTD int64_t;
using __CSTD uint64_t;
using __CSTD intptr_t;
using __CSTD uintptr_t;

#endif /* defined(__STD_USING) */

#endif /* __SYS_SYS_INTEGERTYPES_H__ */
