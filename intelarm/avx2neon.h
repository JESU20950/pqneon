#ifndef AVX2NEON_H
#define AVX2NEON_H
#include <arm_neon.h>


static inline int64x2x2_t _mm256_broadcastq_epi64(int64x2_t a){
    int64x2x2_t result;
    result.val[0] = result.val[1] = vdupq_n_s64(vgetq_lane_s64(a,0));
    return result;
}

static inline int64x2x2_t _mm256_broadcastw_epi16(int64x2_t a){
    int64x2x2_t result;
    result.val[0] = result.val[1] = (int64x2_t) vdupq_n_s16(vgetq_lane_s16((int16x8_t) a,0));
    return result;
}

static inline int64x2x2_t  _mm256_and_si256(int64x2x2_t a, int64x2x2_t b){
	a.val[0] = vandq_s64(a.val[0], b.val[0]);
	a.val[1] = vandq_s64(a.val[1], b.val[1]);
	return a;
}


static inline int64x2x2_t _mm256_cvtepi16_epi64(int64x2_t a){
	int64_t result[4];
	result[3] = (int64_t) vgetq_lane_s16((int16x8_t) a, 3);
	result[2] = (int64_t) vgetq_lane_s16((int16x8_t) a, 2);
	result[1] = (int64_t) vgetq_lane_s16((int16x8_t) a, 1);
	result[0] = (int64_t) vgetq_lane_s16((int16x8_t) a, 0);
	return vld1q_s64_x2(&result[0]);
}




static inline int64x2x2_t _mm256_permute4x64_epi64(int64x2x2_t a, const int imm8){
    int64_t a_aux[4];
    vst1q_s64_x2(a_aux, a);
    const int id0 = imm8 & 0x03;
    const int id1 = (imm8 >> 2) & 0x03;
    const int id2 = (imm8 >> 4) & 0x03;
    const int id3 = (imm8 >> 6) & 0x03;
    a.val[0] = vsetq_lane_s64(a_aux[id0], a.val[0], 0);
    a.val[0] = vsetq_lane_s64(a_aux[id1], a.val[0], 1);
    a.val[1] = vsetq_lane_s64(a_aux[id2], a.val[1], 0);
    a.val[1] = vsetq_lane_s64(a_aux[id3], a.val[1], 1);
    return a;
}


static inline int64x2x2_t _mm256_or_si256(int64x2x2_t a, int64x2x2_t b){
	a.val[0] = vorrq_s64(a.val[0], b.val[0]);
	a.val[1] = vorrq_s64(a.val[1], b.val[1]);
	return a;
}

static inline int64x2x2_t _mm256_add_epi64(int64x2x2_t a, int64x2x2_t b){
	a.val[0] = vaddq_s64(a.val[0], b.val[0]);
	a.val[1] = vaddq_s64(a.val[1], b.val[1]);
	return a;
}


static inline int64x2_t _mm256_extracti128_si256(int64x2x2_t a, const int imm8){
        return a.val[imm8&0x01];	
}


static inline int64x2x2_t _mm256_broadcastd_epi32(int64x2_t a){
	int64x2x2_t result;
	result.val[0] = result.val[1] = (int64x2_t) vdupq_n_s32(vgetq_lane_s32((int32x4_t) a, 0));
    return result;
}


static inline int64x2x2_t  _mm256_xor_si256(int64x2x2_t a, int64x2x2_t b){
	a.val[0] = veorq_s64(a.val[0], b.val[0]);
	a.val[1] = veorq_s64(a.val[1], b.val[1]);
	return a;
}

static inline int64x2x2_t _mm256_slli_epi32(int64x2x2_t a, int imm8){
        a.val[0] = (int64x2_t) vshlq_n_s32((int32x4_t) a.val[0], imm8);
        a.val[1] = (int64x2_t) vshlq_n_s32((int32x4_t) a.val[1], imm8);
        return a;
}

static inline int64x2x2_t _mm256_srli_epi32(int64x2x2_t a, int imm8){
        a.val[0] = (int64x2_t) vshrq_n_s32((int32x4_t) a.val[0], imm8);
        a.val[1] = (int64x2_t) vshrq_n_s32((int32x4_t) a.val[1], imm8);
        return a;
    
}


static inline int64x2x2_t _mm256_add_epi32(int64x2x2_t a, int64x2x2_t b){
	a.val[0] = (int64x2_t) vaddq_s32((int32x4_t) a.val[0],(int32x4_t) b.val[0]);
	a.val[1] = (int64x2_t) vaddq_s32((int32x4_t) a.val[1],(int32x4_t) b.val[1]);
	return a;
}

static inline float64x2x2_t _mm256_permute4x64_pd(float64x2x2_t a, const int imm8){
    float64_t a_aux[4];
    vst1q_f64_x2(a_aux, a);
    const int id0 = imm8 & 0x03;
    const int id1 = (imm8 >> 2) & 0x03;
    const int id2 = (imm8 >> 4) & 0x03;
    const int id3 = (imm8 >> 6) & 0x03;
    a.val[0] = vsetq_lane_f64(a_aux[id0], a.val[0], 0);
    a.val[0] = vsetq_lane_f64(a_aux[id1], a.val[0], 1);
    a.val[1] = vsetq_lane_f64(a_aux[id2], a.val[1], 0);
    a.val[1] = vsetq_lane_f64(a_aux[id3], a.val[1], 1);
    return a;
	
}
static inline int64x2x2_t _mm256_cmpgt_epi64(int64x2x2_t a, int64x2x2_t b){
    a.val[0] = (int64x2_t) vcgtq_s64(a.val[0], b.val[0]);   
    a.val[1] = (int64x2_t) vcgtq_s64(a.val[1], b.val[1]);
    return a;
}

static inline int64x2x2_t _mm256_bsrli_epi128(int64x2x2_t a, const int imm8){
    	if (imm8 > 0 && imm8 <= 15) {
		a.val[0] = (int64x2_t) vextq_s8( (int8x16_t) a.val[0],vdupq_n_s8(0), imm8);
		a.val[1] = (int64x2_t) vextq_s8( (int8x16_t) a.val[1],vdupq_n_s8(0), imm8);
	}else if (imm8 > 15){
		a.val[0] = vdupq_n_s64(0);
		a.val[1] = vdupq_n_s64(0);
	}
	return a;
}

static inline int64x2x2_t _mm256_mullo_epi16(int64x2x2_t a, int64x2x2_t b){
	a.val[0] = (int64x2_t) vmulq_s8((int8x16_t) a.val[0], (int8x16_t) b.val[0]);
	a.val[1] = (int64x2_t) vmulq_s8((int8x16_t) a.val[1], (int8x16_t) b.val[1]);
	return a;
}
#endif
