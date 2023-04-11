/* SCE CONFIDENTIAL
PlayStation(R)3 Programmer Tool Runtime Library 310.001
 * Copyright (C) 2009 Sony Computer Entertainment Inc.
 * All Rights Reserved.
 */

#ifndef __CELL_SYNC2_SEMAPHORE_TYPES_H__
#define __CELL_SYNC2_SEMAPHORE_TYPES_H__

#include <stdint.h>
#include <stdbool.h>
#include <cell/sync2/types.h>

#define CELL_SYNC2_SEMAPHORE_SIZE	128
#define CELL_SYNC2_SEMAPHORE_ALIGN	128

typedef struct CellSync2Semaphore {
	uint8_t skip[CELL_SYNC2_SEMAPHORE_SIZE];
} __attribute__((aligned(CELL_SYNC2_SEMAPHORE_ALIGN))) CellSync2Semaphore;


#define CELL_SYNC2_SEMAPHORE_ATTRIBUTE_SIZE		128
#define CELL_SYNC2_SEMAPHORE_ATTRIBUTE_ALIGN	8

typedef struct CellSync2SemaphoreAttribute {
	uint32_t sdkVersion;
	uint16_t threadTypes;
	uint16_t maxWaiters;
	char name[CELL_SYNC2_NAME_MAX_LENGTH+1];
	uint8_t reserved[CELL_SYNC2_SEMAPHORE_ATTRIBUTE_SIZE
	             - sizeof(uint32_t)
	             - sizeof(uint16_t) * 2
	             - (CELL_SYNC2_NAME_MAX_LENGTH + 1)
	            ];
} __attribute__((aligned(CELL_SYNC2_SEMAPHORE_ATTRIBUTE_ALIGN))) CellSync2SemaphoreAttribute;

#endif /* __CELL_SYNC2_SEMAPHORE_TYPES_H__ */
