#ifndef AVXNEON_H
#define AVXNEON_H
#include <arm_neon.h>



static inline float64x2x2_t _mm256_set_pd(double e3 , double e2, double e1, double e0){
	float64_t result[4];
	result[3] = (float64_t) e3;
	result[2] = (float64_t) e2;
	result[1] = (float64_t) e1;
	result[0] = (float64_t) e0;
	return vld1q_f64_x2(&result[0]);
}

static inline float64x2x2_t _mm256_mul_pd(float64x2x2_t a, float64x2x2_t b){
	a.val[0] = vmulq_f64(a.val[0], b.val[0]);
	a.val[1] = vmulq_f64(a.val[1], b.val[1]);
	return a;
}

static inline float64x2x2_t _mm256_add_pd(float64x2x2_t a, float64x2x2_t b){
	a.val[0] = vaddq_f64(a.val[0], b.val[0]);
	a.val[1] = vaddq_f64(a.val[1], b.val[1]);
	return a;
}

static inline float64x2x2_t _mm256_sub_pd(float64x2x2_t a, float64x2x2_t b){
	a.val[0] = vsubq_f64(a.val[0], b.val[0]);
	a.val[1] = vsubq_f64(a.val[1], b.val[1]);
	return a;
}

static inline float64x2x2_t _mm256_xor_pd(float64x2x2_t a, float64x2x2_t b){
	a.val[0] = (float64x2_t) veorq_s64((int64x2_t) a.val[0],(int64x2_t) b.val[0]);
    a.val[1] = (float64x2_t) veorq_s64((int64x2_t) a.val[1],(int64x2_t) b.val[1]);
    return a;
}


static inline float64x2x2_t _mm256_unpacklo_pd(float64x2x2_t a, float64x2x2_t b){
	a.val[0] = vzip1q_f64(a.val[0], b.val[0]);
	a.val[1] = vzip1q_f64(a.val[1], b.val[1]);
	return a;
}

static inline float64x2x2_t _mm256_unpackhi_pd(float64x2x2_t a, float64x2x2_t b){
	a.val[0] = vzip2q_f64(a.val[0], b.val[0]);
	a.val[1] = vzip2q_f64(a.val[1], b.val[1]);
	return a;
}




static inline float64x2_t _mm_permute_pd(float64x2_t a, int imm8){
	float64x2_t dest = a;
	if (0x01&imm8){
		dest = vsetq_lane_f64(vgetq_lane_f64(a,1), dest,0);
	}
	if ((0x02&imm8) == 0x00){
		dest = vsetq_lane_f64(vgetq_lane_f64(a,0), dest,1);
	}
	return dest;
}


static inline int64x2x2_t _mm256_loadu_si256(int64x2x2_t const* mem_addr){
	return vld1q_s64_x2((int64_t const *) mem_addr);
}

static inline int64x2x2_t _mm256_cmpgt_epi16(int64x2x2_t a, int64x2x2_t b){
	a.val[0] = (int64x2_t) vcgtq_s16((int16x8_t) a.val[0], (int16x8_t) b.val[0]);
	a.val[1] = (int64x2_t) vcgtq_s16((int16x8_t) a.val[1], (int16x8_t) b.val[1]);
	return a;
}

static inline int64x2x2_t  _mm256_cmpeq_epi16(int64x2x2_t a, int64x2x2_t b){
	a.val[0] = (int64x2_t) vceqq_s16((int16x8_t) a.val[0], (int16x8_t) b.val[0]);
	a.val[1] = (int64x2_t) vceqq_s16((int16x8_t) a.val[1], (int16x8_t) b.val[1]);
	return a;	
}

static inline int64x2_t _mm256_castsi256_si128(int64x2x2_t a){
	return a.val[0];
}

static inline void _mm256_storeu_si256(int64x2x2_t * mem_addr, int64x2x2_t a){
	vst1q_s64_x2((int64_t *) mem_addr, a);
}

static inline float64x2x2_t _mm256_set1_pd(double a){
	float64x2x2_t result;
	result.val[0] = result.val[1] = vdupq_n_f64((float64_t) a);
        return result;
}

static inline float64x2x2_t _mm256_loadu_pd(double const * mem_addr){
	return vld1q_f64_x2((float64_t const *) mem_addr);
}

static inline void _mm256_storeu_pd(double * mem_addr, float64x2x2_t a){
	vst1q_f64_x2((float64_t *) mem_addr, a);
}

static inline float64x2x2_t _mm256_setzero_pd(void){
	float64x2x2_t result;
	result.val[0] = result.val[1] = vdupq_n_f64(0.0);
	return result;
}

static inline float64x2x2_t _mm256_div_pd(float64x2x2_t a, float64x2x2_t b){
	a.val[0] = vdivq_f64(a.val[0], b.val[0]);
	a.val[1] = vdivq_f64(a.val[1], b.val[1]);
	return a;
}


static inline float64x2x2_t _mm256_hadd_pd(float64x2x2_t a, float64x2x2_t b){
	float64_t result[4];
	result[3] = vaddvq_f64(b.val[1]);
	result[2] = vaddvq_f64(a.val[1]);
	result[1] = vaddvq_f64(b.val[0]);
	result[0] = vaddvq_f64(a.val[0]);
	return vld1q_f64_x2(&result[0]);
}

static inline float64x2_t _mm256_extractf128_pd(float64x2x2_t a, const int imm8){
    return a.val[imm8 & 0x01];
}

static inline float64x2x2_t _mm256_hsub_pd(float64x2x2_t a, float64x2x2_t b){
	float64_t result[4];
	result[3] = vgetq_lane_f64(b.val[1],0) - vgetq_lane_f64(b.val[1],1);
	result[2] = vgetq_lane_f64(a.val[1],0) - vgetq_lane_f64(a.val[1],1);
	result[1] = vgetq_lane_f64(b.val[0],0) - vgetq_lane_f64(b.val[0],1);
	result[0] = vgetq_lane_f64(a.val[0],0) - vgetq_lane_f64(a.val[0],1);
	return vld1q_f64_x2(&result[0]);
}


static inline float64x2x2_t _mm256_shuffle_pd(float64x2x2_t a, float64x2x2_t b, const int imm8){
	float64_t result[4];
	result[3] = ((imm8 & 0x08) == 0) ? vgetq_lane_f64(b.val[1],0) : vgetq_lane_f64(b.val[1],1);
	result[2] = ((imm8 & 0x04) == 0) ? vgetq_lane_f64(a.val[1],0) : vgetq_lane_f64(a.val[1],1);
	result[1] = ((imm8 & 0x02) == 0) ? vgetq_lane_f64(b.val[0],0) : vgetq_lane_f64(b.val[0],1);
	result[0] = ((imm8 & 0x01) == 0) ? vgetq_lane_f64(a.val[0],0) : vgetq_lane_f64(a.val[0],1);
	return vld1q_f64_x2(&result[0]);
}


static inline float64x2x2_t  _mm256_permute2f128_pd(float64x2x2_t a, float64x2x2_t b, const int imm8){
	float64x2x2_t result;
	float64x2_t aux[4];
	aux[0x00] = a.val[0];
	aux[0x01] = a.val[1];
	aux[0x02] = b.val[0];
	aux[0x03] = b.val[1];
	if ((imm8&0x08)== 0x08){
		result.val[0] = vdupq_n_f64(0.0);
	}else{
		result.val[0] = aux[imm8&0x03];
	}
	int imm8_aux = (imm8 >> 4);
	if ((imm8_aux&0x08) == 0x08){
                result.val[1] = vdupq_n_f64(0.0);
        }else{
                result.val[1] = aux[imm8_aux&0x03];
        }
	return result;
}
static inline float64x2_t _mm256_castpd256_pd128(float64x2x2_t a){
	return a.val[0];
}



#endif
