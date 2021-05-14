#ifndef SSE2NEON_H
#define SSE2NEON_H
#include <arm_neon.h>

static inline float64x2_t _mm_set1_pd(double a){
		return vdupq_n_f64(((float64_t) a));
}

static inline float64x2_t _mm_set_pd(double e1, double e0){
		float64_t result[2];
		result[1] = (float64_t) e1;
		result[0] = (float64_t) e0;
		return vld1q_f64(result);
} 

static inline float64x2_t _mm_loadu_pd(double const* mem_addr){
		return vld1q_f64((float64_t const *) mem_addr);
	
}
static inline float64x2_t _mm_unpacklo_pd(float64x2_t a, float64x2_t b){
		float64_t result[2];
		result[1] = (float64_t) vgetq_lane_f64(b,0);
		result[0] = (float64_t) vgetq_lane_f64(a,0);
		return vld1q_f64(result);
}
static inline float64x2_t _mm_unpackhi_pd(float64x2_t a, float64x2_t b){
		float64_t result[2];
		result[1] = (float64_t) vgetq_lane_f64(b,1);
		result[0] = (float64_t) vgetq_lane_f64(a,1);
		return vld1q_f64(result);
}

static inline float64x2_t _mm_add_pd(float64x2_t a, float64x2_t b){
		return vaddq_f64(a,b);
}

static inline float64x2_t _mm_mul_pd(float64x2_t a, float64x2_t b){
		return vmulq_f64(a,b);
}

static inline float64x2_t _mm_sub_pd(float64x2_t a, float64x2_t b){
		return vsubq_f64(a,b);
}


static inline float64x2_t _mm_xor_pd(float64x2_t a, float64x2_t b){
		return (float64x2_t) veorq_s64((int64x2_t)a, (int64x2_t) b);
}

static inline double _mm_cvtsd_f64(float64x2_t a){
		return (double) vgetq_lane_f64(a,0);
}


static inline void _mm_storeu_pd(double* mem_addr, float64x2_t a){
		vst1q_f64((float64_t*) mem_addr, a);
}

static inline int64x2_t _mm_cvtsi32_si128(int a){
		return vsetq_lane_s64((int64_t) a, vdupq_n_s64(0), 0);
}


static inline int64x2_t _mm_srli_epi16(int64x2_t a,  int imm8){
		return (int64x2_t) vshrq_n_s16((int16x8_t) a, imm8);
}

static inline int64x2_t _mm_setzero_si128(void){
		return vdupq_n_s64(0);
}


static inline int _mm_cvtsi128_si32(int64x2_t a){
		return (int) vgetq_lane_s32((int32x4_t) a, 0);
}

static inline int64x2_t _mm_cvtsi64_si128(int64_t a){
		return vsetq_lane_s64(a, vdupq_n_s64(0), 0);
} 


static inline int64x2_t _mm_add_epi64(int64x2_t a, int64x2_t b){
		return vaddq_s64(a,b);
}


static inline int64x2_t _mm_srli_si128(int64x2_t a, int imm8){
		if (imm8 > 0 && imm8 <= 15) {
			a = (int64x2_t) vextq_s8((int8x16_t) a, vdupq_n_s8(0), imm8);
		}else if (imm8 > 15){
			a = vdupq_n_s64(0);
		}
		return a;
}


static inline float64x2_t _mm_load1_pd(double const* mem_addr){
		return vdupq_n_f64(((float64_t) *mem_addr));
}

static inline float64x2_t _mm_sqrt_pd(float64x2_t a){
		return vsqrtq_f64(a);
}


static inline void _mm_storel_pd(double* mem_addr, float64x2_t a){
		*mem_addr = (double) vgetq_lane_f64(a, 0);
}


#endif
