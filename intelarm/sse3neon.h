#ifndef SSE3NEON_H
#define SSE3NEON_H
#include <arm_neon.h>

static inline int64x2_t _mm_hadd_epi16(int64x2_t a, int64x2_t b){
		return (int64x2_t) vpaddq_s16((int16x8_t) a, (int16x8_t) b);
}

#endif
