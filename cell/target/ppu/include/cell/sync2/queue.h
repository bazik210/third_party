/* SCE CONFIDENTIAL
PlayStation(R)3 Programmer Tool Runtime Library 310.001
 * Copyright (C) 2009 Sony Computer Entertainment Inc.
 * All Rights Reserved.
 */

#ifndef __CELL_SYNC2_QUEUE_H__
#define __CELL_SYNC2_QUEUE_H__

#include <stddef.h>
#include <stdint.h>
#include <cell/sync2/thread.h>
#include <cell/sync2/queue_types.h>
#include <cell/sync2/error.h>
#include <cell/sync2/version.h>

#ifdef __cplusplus
extern "C" {
#endif

int _cellSync2QueueAttributeInitialize(
		CellSync2QueueAttribute* attr,
		uint32_t sdkVersion
	);

static inline
int cellSync2QueueAttributeInitialize(
		CellSync2QueueAttribute* attr
	) {
	return _cellSync2QueueAttributeInitialize(attr, _CELL_SYNC2_INTERNAL_VERSION);
}

int cellSync2QueueEstimateBufferSize(
		const CellSync2QueueAttribute* attr,
		size_t* bufferSize
	);

int cellSync2QueueInitialize(
		CellSync2Queue* queue,
		void* buffer,
		const CellSync2QueueAttribute* attr
	);

int cellSync2QueueFinalize(
		CellSync2Queue* queue
	);

int cellSync2QueuePush(
		CellSync2Queue* queue,
		const void* data,
		const CellSync2ThreadConfig* config
	);

int cellSync2QueueTryPush(
		CellSync2Queue* queue,
		const void* const data[],
		unsigned int numData,
		const CellSync2ThreadConfig* config
	);

int cellSync2QueuePop(
		CellSync2Queue* queue,
		void* buffer,
		const CellSync2ThreadConfig* config
	);

int cellSync2QueueTryPop(
		CellSync2Queue* queue,
		void* buffer,
		const CellSync2ThreadConfig* config
	);

int cellSync2QueueGetSize(
		CellSync2Queue* queue,
		unsigned int* size
	);

int cellSync2QueueGetDepth(
		CellSync2Queue* queue,
		unsigned int* depth
	);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* __CELL_SYNC2_QUEUE_H__ */
