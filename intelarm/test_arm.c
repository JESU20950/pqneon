#include "intelarm.h"
#include <stdio.h>

void print_float64x2x2_t(float64x2x2_t a){
	printf("%.17g,",(double) vgetq_lane_f64(a.val[1],1));
	printf("%.17g,", (double) vgetq_lane_f64(a.val[1],0));
	printf("%.17g,", (double) vgetq_lane_f64(a.val[0],1));
	printf("%.17g\n", (double) vgetq_lane_f64(a.val[0],0));
}
void print_float64x2_t(float64x2_t a){
        printf("%.17g,", vgetq_lane_f64(a,1));
        printf("%.17g\n", vgetq_lane_f64(a,0));
}
/*
void print_int64x2x2_t(int64x2x2_t a){
        printf("%#010lx,", vgetq_lane_s64(a.val[1],1));
        printf("%#010lx,", vgetq_lane_s64(a.val[1],0));
        printf("%#010lx,", vgetq_lane_s64(a.val[0],1));
        printf("%#010lx\n", vgetq_lane_s64(a.val[0],0));
}

void print_int64x2_t(int64x2_t a){
        printf("%#010lx,", vgetq_lane_s64(a,1));
        printf("%#010lx\n", vgetq_lane_s64(a,0));
}
*/

void print_int64x2x2_t(int64x2x2_t a){
        printf("%lld,", vgetq_lane_s64(a.val[1],1));
        printf("%lld,", vgetq_lane_s64(a.val[1],0));
        printf("%lld,", vgetq_lane_s64(a.val[0],1));
        printf("%lld\n", vgetq_lane_s64(a.val[0],0));
}

void print_int64x2_t(int64x2_t a){
        printf("%lld,", vgetq_lane_s64(a,1));
        printf("%lld\n", vgetq_lane_s64(a,0));
}
/*
void print_int16x8x2_t(int64x2x2_t a){
	for (int i = 1; i>=0; --i){
		printf("%#010x,", vgetq_lane_s16((int16x8_t)a.val[i],7));
		printf("%#010x,", vgetq_lane_s16((int16x8_t)a.val[i],6));
		printf("%#010x,", vgetq_lane_s16((int16x8_t)a.val[i],5));
		printf("%#010x,", vgetq_lane_s16((int16x8_t)a.val[i],4));
		printf("%#010x,", vgetq_lane_s16((int16x8_t)a.val[i],3));
		printf("%#010x,", vgetq_lane_s16((int16x8_t)a.val[i],2));
		printf("%#010x,", vgetq_lane_s16((int16x8_t)a.val[i],1));
		printf("%#010x,", vgetq_lane_s16((int16x8_t)a.val[i],0));
	}
	printf("\n");
}
void print_int32x4x2_t(int64x2x2_t a){
        for (int i = 1; i>=0; --i){
                printf("%#010x,", vgetq_lane_s32((int32x4_t)a.val[i],3));
                printf("%#010x,", vgetq_lane_s32((int32x4_t)a.val[i],2));
                printf("%#010x,", vgetq_lane_s32((int32x4_t)a.val[i],1));
                printf("%#010x,", vgetq_lane_s32((int32x4_t)a.val[i],0));
        }
        printf("\n");
}
*/

double random_double(){
	return (double) rand()/(double) rand();
}
int64x2x2_t random_int64x2x2_t(){
	int64_t result[4];
        result[0] = ((int64_t) rand() <<32) | rand();
        result[1] = ((int64_t) rand() <<32) | rand();
        result[2] = ((int64_t) rand() <<32) | rand();
        result[3] = ((int64_t) rand() <<32) | rand();
        return vld1q_s64_x2(&result[0]);
}
int64x2_t random_int64x2_t(){
	int64_t result[2];
        result[0] = ((int64_t) rand() <<32) | rand();
        result[1] = ((int64_t) rand() <<32) | rand();
        return vld1q_s64(&result[0]);
}

float64x2x2_t random_float64x2x2_t(){
	float64_t result[4];
        result[0] = random_double();
        result[1] = random_double();
        result[2] = random_double();
        result[3] = random_double();
        return vld1q_f64_x2(&result[0]);


}
float64x2_t random_float64x2_t(){
	float64_t result[2];
        result[0] = random_double();
        result[1] = random_double();
        return vld1q_f64(&result[0]);
}


//AVX2NEON TEST

void test_mm256_broadcastq_epi64(){
	printf("_mm256_broadcastq_epi64()\n");
        int64x2_t a = random_int64x2_t();
        print_int64x2_t(a);
        int64x2x2_t a2 = _mm256_broadcastq_epi64(a);
        print_int64x2x2_t(a2);

}
void test_mm256_broadcastw_epi16(){
	printf("_mm256_broadcastw_epi16()\n");
	int64x2_t a = random_int64x2_t();
	print_int64x2_t(a);
        int64x2x2_t a2 = _mm256_broadcastw_epi16(a);
	print_int64x2x2_t(a2);
}
void test_mm256_and_si256(){
        printf("_mm256_and_si256()\n");
	int64x2x2_t a = random_int64x2x2_t();
        print_int64x2x2_t(a);
        int64x2x2_t b = random_int64x2x2_t();
        print_int64x2x2_t(b);
        a = _mm256_and_si256(a,b);
        print_int64x2x2_t(a);
}
void test_mm256_cvtepi16_epi64(){
      	printf("_mm256_cvtepi16_epi64()\n");
        int64x2_t a = random_int64x2_t();
        print_int64x2_t(a);
        int64x2x2_t a2 = _mm256_cvtepi16_epi64(a);
        print_int64x2x2_t(a2);

}
void test_mm256_permute4x64_epi64(){
	printf("_mm256_permute4x64_epi64()\n");
	int64x2x2_t a = random_int64x2x2_t();
	print_int64x2x2_t(a);
	int imm8 = rand()%256;
	printf("%d\n", imm8);
	a = _mm256_permute4x64_epi64(a,imm8);
	print_int64x2x2_t(a);
}
void test_mm256_or_si256(){
	printf("_mm256_or_si256()\n");
        int64x2x2_t a = random_int64x2x2_t();
        print_int64x2x2_t(a);
	int64x2x2_t b = random_int64x2x2_t();
        print_int64x2x2_t(b);
        a = _mm256_or_si256(a,b);
        print_int64x2x2_t(a);
}
void test_mm256_add_epi64(){
		printf("_mm256_add_epi64()\n");
        int64x2x2_t a = random_int64x2x2_t();
        print_int64x2x2_t(a);
        int64x2x2_t b = random_int64x2x2_t();
        print_int64x2x2_t(b);
        a = _mm256_add_epi64(a,b);
        print_int64x2x2_t(a);
}
void test_mm256_extracti128_si256(){
	printf("_mm256_extracti128_si256()\n");
        int64x2x2_t a = random_int64x2x2_t();
        print_int64x2x2_t(a);
        int imm8 = rand()%2;
        printf("%d\n", imm8);
        int64x2_t a2 = _mm256_extracti128_si256(a,imm8);
        print_int64x2_t(a2);
}
void test_mm256_broadcastd_epi32(){
	printf("_mm256_broadcastd_epi32()\n");
	int64x2_t a = random_int64x2_t();
        print_int64x2_t(a);
        int64x2x2_t a2 = _mm256_broadcastd_epi32(a);
        print_int64x2x2_t(a2);
}
void test_mm256_xor_si256(){
	printf("_mm256_xor_si256()\n");
        int64x2x2_t a = random_int64x2x2_t();
        print_int64x2x2_t(a);
        int64x2x2_t b = random_int64x2x2_t();
        print_int64x2x2_t(b);
        a = _mm256_xor_si256(a,b);
        print_int64x2x2_t(a);
}
void test_mm256_slli_epi32(){
	printf("_mm256_slli_epi32()\n");
        int64x2x2_t a = random_int64x2x2_t();
	print_int64x2x2_t(a);
	int imm8 = rand()%32;
        printf("%d\n", imm8);
        a = _mm256_slli_epi32(a,imm8);
        print_int64x2x2_t(a);

}
void test_mm256_srli_epi32(){
	printf("_mm256_srli_epi32()\n");
        int64x2x2_t a = random_int64x2x2_t();
        print_int64x2x2_t(a);
        int imm8 = rand()%32;
	printf("%d\n", imm8);
        a = _mm256_srli_epi32(a,imm8);
        print_int64x2x2_t(a);
}
void test_mm256_add_epi32(){
		printf("_mm256_add_epi32()\n");
        int64x2x2_t a = random_int64x2x2_t();
        print_int64x2x2_t(a);
        int64x2x2_t b = random_int64x2x2_t();
        print_int64x2x2_t(b);
        a = _mm256_add_epi32(a,b);
        print_int64x2x2_t(a);
}
void test_mm256_permute4x64_pd(){
	printf("_mm256_permute4x64_pd()\n");
        float64x2x2_t a = random_float64x2x2_t();
        print_float64x2x2_t(a);
        int imm8 = rand()%256;
        printf("%d\n", imm8);
        a = _mm256_permute4x64_pd(a,imm8);
        print_float64x2x2_t(a);	
}
void test_mm256_cmpgt_epi64(){
	printf("_mm256_cmpgt_epi64()\n");
        int64x2x2_t a = random_int64x2x2_t();
        print_int64x2x2_t(a);
        int64x2x2_t b = random_int64x2x2_t();
        print_int64x2x2_t(b);
        a = _mm256_cmpgt_epi64(a,b);
        print_int64x2x2_t(a);
}
void test_mm256_bsrli_epi128(){
	printf("_mm256_bsrli_epi128()\n");
        int64x2x2_t a = random_int64x2x2_t();
        print_int64x2x2_t(a);
		print_int64x2x2_t(_mm256_bsrli_epi128(a, 0));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 1));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 2));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 3));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 4));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 5));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 6));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 7));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 8));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 9));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 10));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 11));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 12));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 13));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 14));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 15));
	print_int64x2x2_t(_mm256_bsrli_epi128(a, 16));
	
}


///////AVXNEON TEST

void test_mm256_set_pd(){
	 printf("_mm256_set_pd()\n");
	 double e3 = random_double();
	 printf("%.17g\n", e3);
	 double e2 = random_double();
	 printf("%.17g\n", e2);
	 double e1 = random_double();
	 printf("%.17g\n", e1);
	 double e0 = random_double();
	 printf("%.17g\n", e0);
	 float64x2x2_t a = _mm256_set_pd(e3 , e2, e1, e0);
	 print_float64x2x2_t(a);
}


void test_mm256_mul_pd(){
        printf("_mm256_mul_pd()\n");	
	float64x2x2_t a = random_float64x2x2_t();
        print_float64x2x2_t(a);
        float64x2x2_t b = random_float64x2x2_t();
        print_float64x2x2_t(b);
        a = _mm256_mul_pd(a,b);
        print_float64x2x2_t(a);
}
void test_mm256_add_pd(){
        printf("_mm256_add_pd()\n");
        float64x2x2_t a = random_float64x2x2_t();
        print_float64x2x2_t(a);
        float64x2x2_t b = random_float64x2x2_t();
        print_float64x2x2_t(b);
        a = _mm256_add_pd(a,b);
        print_float64x2x2_t(a);	
}
void test_mm256_sub_pd(){
	printf("_mm256_sub_pd()\n");
	float64x2x2_t a = random_float64x2x2_t();
        print_float64x2x2_t(a);
        float64x2x2_t b = random_float64x2x2_t();
        print_float64x2x2_t(b);
        a = _mm256_sub_pd(a,b);
        print_float64x2x2_t(a);
}
void test_mm256_xor_pd(){
	printf("_mm256_xor_pd()\n");
	float64x2x2_t a = random_float64x2x2_t();
        print_float64x2x2_t(a);
        float64x2x2_t b = random_float64x2x2_t();
        print_float64x2x2_t(b);
        a = _mm256_xor_pd(a,b);
        print_float64x2x2_t(a);
	
}
void test_mm256_unpacklo_pd(){
	printf("_mm256_unpacklo_pd()\n");
	float64x2x2_t a = random_float64x2x2_t();
        print_float64x2x2_t(a);
        float64x2x2_t b = random_float64x2x2_t();
        print_float64x2x2_t(b);
        a = _mm256_unpacklo_pd(a,b);
        print_float64x2x2_t(a);
}

void test_mm256_unpackhi_pd(){
	printf("_mm256_unpackhi_pd()\n");
	float64x2x2_t a = random_float64x2x2_t();
        print_float64x2x2_t(a);
        float64x2x2_t b = random_float64x2x2_t();
        print_float64x2x2_t(b);
        a = _mm256_unpackhi_pd(a,b);
        print_float64x2x2_t(a);
}

void test_mm_permute_pd(){
	printf("_mm_permute_pd()\n");
	float64x2_t a = random_float64x2_t();
        print_float64x2_t(a);
	int imm8 = rand()%4;
        printf("%x\n", imm8);
	a = _mm_permute_pd(a,imm8);
        print_float64x2_t(a);
}
void test_mm256_loadu_si256(){
	printf("_mm256_loadu_si256()\n");
	int64x2x2_t a = random_int64x2x2_t();
	print_int64x2x2_t(a);
	a = _mm256_loadu_si256(&a);
	print_int64x2x2_t(a);
}
void test_mm256_cmpgt_epi16(){
	printf("_mm256_cmpgt_epi16()\n");
	int64x2x2_t a = random_int64x2x2_t();
	print_int64x2x2_t(a);
	int64x2x2_t b = random_int64x2x2_t();
	print_int64x2x2_t(b);
	a = _mm256_cmpgt_epi16(a,b);
	print_int64x2x2_t(a);

}
void test_mm256_cmpeq_epi16(){
	printf("_mm256_cmpeq_epi16()\n");
	int64x2x2_t a = random_int64x2x2_t();
	print_int64x2x2_t(a);
	int64x2x2_t b = random_int64x2x2_t();
	print_int64x2x2_t(b);
	a = _mm256_cmpeq_epi16(a,b);
	print_int64x2x2_t(a);
}
void test_mm256_castsi256_si128(){
	printf("_mm256_castsi256_si128()\n");
	int64x2x2_t a = random_int64x2x2_t();
	print_int64x2x2_t(a);
	int64x2_t a2 = _mm256_castsi256_si128(a);
	print_int64x2_t(a2);
}
void test_mm256_storeu_si256(){
	printf("_mm256_storeu_si256()\n");
	int64x2x2_t a = random_int64x2x2_t();
	print_int64x2x2_t(a);
	int64x2x2_t a2;
	_mm256_storeu_si256(&a2, a);
	print_int64x2x2_t(a2);
}
void test_mm256_set1_pd(){
	printf("_mm256_set1_pd()\n");	
	double a = random_double();
	printf("%.17g\n", a);
	print_float64x2x2_t(_mm256_set1_pd(a));
}
void test_mm256_loadu_pd(){
	printf("_mm256_loadu_pd()\n");	
	double a[4]; 
	a[3] = random_double();
	printf("%.17g,", a[3]);
	a[2] = random_double();
	printf("%.17g,", a[2]);
	a[1] = random_double();
	printf("%.17g,", a[1]);
	a[0] = random_double();
	printf("%.17g\n", a[0]);
	print_float64x2x2_t(_mm256_loadu_pd(a));
}

void test_mm256_storeu_pd(){
	printf("_mm256_storeu_pd()\n");
	float64x2x2_t a = random_float64x2x2_t();
	print_float64x2x2_t(a);
	double a2[4];
	_mm256_storeu_pd(&a2[0], a);
	printf("%.17g,", a2[3]);
	printf("%.17g,", a2[2]);
	printf("%.17g,", a2[1]);
	printf("%.17g\n", a2[0]);
}
void test_mm256_setzero_pd(){
	printf("_mm256_setzero_pd()\n");
	float64x2x2_t a = _mm256_setzero_pd();
	print_float64x2x2_t(a);
}
void test_mm256_div_pd(){
	printf("_mm256_div_pd()\n");
	float64x2x2_t a = random_float64x2x2_t();
	print_float64x2x2_t(a);
	float64x2x2_t b = random_float64x2x2_t();
	print_float64x2x2_t(b);
	a = _mm256_div_pd(a, b);
	print_float64x2x2_t(a);
}
void test_mm256_hadd_pd(){
	printf("_mm256_hadd_pd()\n");
	float64x2x2_t a = random_float64x2x2_t();
	print_float64x2x2_t(a);
	float64x2x2_t b = random_float64x2x2_t();
	print_float64x2x2_t(b);
	a = _mm256_hadd_pd(a, b);
	print_float64x2x2_t(a);
}
void test_mm256_extractf128_pd(){
	printf("_mm256_extractf128_pd()\n");
	float64x2x2_t a = random_float64x2x2_t();
	print_float64x2x2_t(a);
	int imm8 = rand()%2;
	printf("%d\n", imm8);
	float64x2_t a2 = _mm256_extractf128_pd(a,imm8);
	print_float64x2_t(a2);
}
void test_mm256_hsub_pd(){
	printf("_mm256_hsub_pd()\n");
	float64x2x2_t a = random_float64x2x2_t();
	print_float64x2x2_t(a);
	float64x2x2_t b = random_float64x2x2_t();
	print_float64x2x2_t(b);
	a = _mm256_hsub_pd(a, b);
	print_float64x2x2_t(a);
}
void test_mm256_shuffle_pd(){
	printf("_mm256_shuffle_pd()\n");
	float64x2x2_t a = random_float64x2x2_t();
	print_float64x2x2_t(a);
	float64x2x2_t b = random_float64x2x2_t();
	print_float64x2x2_t(b);
	int imm8 = rand()%8;
	printf("%d\n", imm8);
	a = _mm256_shuffle_pd(a, b, imm8);
	print_float64x2x2_t(a);
}
void test_mm256_permute2f128_pd(){
	printf("_mm256_permute2f128_pd()\n");
	float64x2x2_t a = random_float64x2x2_t();
	print_float64x2x2_t(a);
	float64x2x2_t b = random_float64x2x2_t();
	print_float64x2x2_t(b);
	int imm8 = rand()%256;
	printf("%d\n", imm8);
	a = _mm256_permute2f128_pd(a, b, imm8);
	print_float64x2x2_t(a);
}
void test_mm256_castpd256_pd128(){
	printf("_mm256_castpd256_pd128()\n");
	float64x2x2_t a = random_float64x2x2_t();
	print_float64x2x2_t(a);
	float64x2_t a2 = _mm256_castpd256_pd128(a);
	print_float64x2_t(a2);
}


///////SSE2NEON TEST


void test_mm_set1_pd(){
	printf("_mm_set1_pd()\n");	
	double a= random_double(); 
	printf("%.17g\n", a);
	float64x2_t a2 = _mm_set1_pd(a);
	print_float64x2_t(a2);
}
void test_mm_set_pd(){
	printf("_mm_set_pd()\n");	
	double a= random_double(); 
	printf("%.17g\n", a);
	double b= random_double(); 
	printf("%.17g\n", b);
	float64x2_t a2 = _mm_set_pd(a,b);
	print_float64x2_t(a2);
}
void test_mm_loadu_pd(){
	printf("_mm_loadu_pd()\n");
	double a[2];
	a[1] = random_double();
	printf("%.17g,", a[1]);
	a[0] = random_double();
	printf("%.17g\n", a[0]);
	float64x2_t a2 = _mm_loadu_pd(&a[0]);
	print_float64x2_t(a2);
}
void test_mm_unpacklo_pd(){
	printf("_mm_unpacklo_pd()\n");
	float64x2_t a = random_float64x2_t();
	print_float64x2_t(a);
	float64x2_t b = random_float64x2_t();
	print_float64x2_t(b);
	a = _mm_unpacklo_pd(a,b);
	print_float64x2_t(a);
}
void test_mm_unpackhi_pd(){
	printf("_mm_unpackhi_pd()\n");
	float64x2_t a = random_float64x2_t();
	print_float64x2_t(a);
	float64x2_t b = random_float64x2_t();
	print_float64x2_t(b);
	a = _mm_unpackhi_pd(a,b);
	print_float64x2_t(a);
}

void test_mm_add_pd(){
	printf("_mm_add_pd()\n");
	float64x2_t a = random_float64x2_t();
	print_float64x2_t(a);
	float64x2_t b = random_float64x2_t();
	print_float64x2_t(b);
	a = _mm_add_pd(a,b);
	print_float64x2_t(a);
}
void test_mm_mul_pd(){
	printf("_mm_mul_pd()\n");
	float64x2_t a = random_float64x2_t();
	print_float64x2_t(a);
	float64x2_t b = random_float64x2_t();
	print_float64x2_t(b);
	a = _mm_mul_pd(a,b);
	print_float64x2_t(a);
}
void test_mm_sub_pd(){
	printf("_mm_sub_pd()\n");
	float64x2_t a = random_float64x2_t();
	print_float64x2_t(a);
	float64x2_t b = random_float64x2_t();
	print_float64x2_t(b);
	a = _mm_sub_pd(a,b);
	print_float64x2_t(a);
}
void test_mm_xor_pd(){
	printf("_mm_xor_pd()\n");
	float64x2_t a = random_float64x2_t();
	print_float64x2_t(a);
	float64x2_t b = random_float64x2_t();
	print_float64x2_t(b);
	a = _mm_xor_pd(a,b);
	print_float64x2_t(a);
}
void test_mm_cvtsd_f64(){
	printf("_mm_cvtsd_f64()\n");
	float64x2_t a = random_float64x2_t();
	print_float64x2_t(a);
	double a2 = _mm_cvtsd_f64(a);
	printf("%.17g\n",a2);
}
void test_mm_storeu_pd(){
	printf("_mm_storeu_pd()\n");
	float64x2_t a = random_float64x2_t();
	print_float64x2_t(a);
	double a2[2];
	_mm_storeu_pd(a2, a);
	printf("%.17g,", a2[1]);
	printf("%.17g\n", a2[0]);
}
void test_mm_cvtsi32_si128(){
	printf("_mm_cvtsi32_si128()\n");
	int a = rand();
	printf("%d\n", a);
	int64x2_t a2 = _mm_cvtsi32_si128(a);
	print_int64x2_t(a2);
}
void test_mm_srli_epi16(){
	printf("_mm_srli_epi16()\n");
	int64x2_t a = random_int64x2_t();
	print_int64x2_t(a);
	int imm8 = rand();
	printf("%d\n", imm8);
	int64x2_t a2 = _mm_srli_epi16(a, imm8);
	print_int64x2_t(a2);
}
void test_mm_setzero_si128(){
	printf("_mm_setzero_si128()\n");
	int64x2_t a = _mm_setzero_si128();
	print_int64x2_t(a);
}
void test_mm_cvtsi128_si32(){
	printf("_mm_cvtsi128_si32()\n");
	int64x2_t a = random_int64x2_t();
	print_int64x2_t(a);
	int a2 = _mm_cvtsi128_si32(a);
	printf("%d\n", a2);
}
void test_mm_cvtsi64_si128(){
	printf("_mm_cvtsi64_si128()\n");
	int a = rand();
	printf("%d\n", a);
	int64x2_t a2 = _mm_cvtsi64_si128(a);
	print_int64x2_t(a2);
}
void test_mm_add_epi64(){
	printf("_mm_add_epi64()\n");
	int64x2_t a = random_int64x2_t();
	print_int64x2_t(a);
	int64x2_t b = random_int64x2_t();
	print_int64x2_t(b);
	a = _mm_add_epi64(a,b);
	print_int64x2_t(a);
}
void test_mm_srli_si128(){
	printf("_mm_srli_si128()\n");
	int64x2_t a = random_int64x2_t();
	print_int64x2_t(a);
	print_int64x2_t(_mm_srli_si128(a, 0));
	print_int64x2_t(_mm_srli_si128(a, 1));
	print_int64x2_t(_mm_srli_si128(a, 2));
	print_int64x2_t(_mm_srli_si128(a, 3));
	print_int64x2_t(_mm_srli_si128(a, 4));
	print_int64x2_t(_mm_srli_si128(a, 5));
	print_int64x2_t(_mm_srli_si128(a, 6));
	print_int64x2_t(_mm_srli_si128(a, 7));
	print_int64x2_t(_mm_srli_si128(a, 8));
	print_int64x2_t(_mm_srli_si128(a, 9));
	print_int64x2_t(_mm_srli_si128(a, 10));
	print_int64x2_t(_mm_srli_si128(a, 11));
	print_int64x2_t(_mm_srli_si128(a, 12));
	print_int64x2_t(_mm_srli_si128(a, 13));
	print_int64x2_t(_mm_srli_si128(a, 14));
	print_int64x2_t(_mm_srli_si128(a, 15));
	print_int64x2_t(_mm_srli_si128(a, 16));
}
void test_mm_load1_pd(){
	printf("_mm_load1_pd()\n");
	double a  = random_double();
	printf("%.17g\n", a);
	print_float64x2_t(_mm_load1_pd(&a));
}
void test_mm_sqrt_pd(){
	printf("_mm_sqrt_pd()\n");
	float64x2_t a = random_float64x2_t();
	print_float64x2_t(a);
	a = _mm_sqrt_pd(a);
	print_float64x2_t(a);
}
void test_mm_storel_pd(){
	printf("_mm_storel_pd()\n");
	float64x2_t a = random_float64x2_t();
	print_float64x2_t(a);
	double a2[1];
	_mm_storel_pd(a2, a);
	printf("%.17g\n", a2[0]);
}

///////SSE3NEON TEST
void test_mm_hadd_epi16(){
	printf("_mm_hadd_epi16()\n");
	int64x2_t a = random_int64x2_t();
	print_int64x2_t(a);
	int64x2_t b = random_int64x2_t();
	print_int64x2_t(b);
	a = _mm_hadd_epi16(a,b);
	print_int64x2_t(a);
}

int main(){
		srand(time(NULL));
		///////AVX2NEON TEST
		test_mm256_broadcastq_epi64();
		test_mm256_broadcastw_epi16();
		test_mm256_and_si256();
		test_mm256_cvtepi16_epi64();
		test_mm256_permute4x64_epi64();
		test_mm256_or_si256();
		test_mm256_add_epi64();
		test_mm256_extracti128_si256();
		test_mm256_broadcastd_epi32();
		test_mm256_xor_si256();
		test_mm256_slli_epi32();
		test_mm256_srli_epi32();
		test_mm256_add_epi32();
		test_mm256_permute4x64_pd();
		test_mm256_cmpgt_epi64();
		test_mm256_bsrli_epi128();

		///////AVXNEON TEST
		test_mm256_set_pd();
		test_mm256_mul_pd();
		test_mm256_add_pd();
		test_mm256_sub_pd();
		test_mm256_xor_pd();
		test_mm256_unpacklo_pd();
		test_mm256_unpackhi_pd();
		test_mm_permute_pd();
		test_mm256_loadu_si256();
		test_mm256_cmpgt_epi16();
		test_mm256_cmpeq_epi16();
		test_mm256_castsi256_si128();
		test_mm256_storeu_si256();
		test_mm256_set1_pd();
		test_mm256_loadu_pd();
		test_mm256_storeu_pd();
		test_mm256_setzero_pd();
		test_mm256_div_pd();
		test_mm256_hadd_pd();
		test_mm256_extractf128_pd();
		test_mm256_hsub_pd();
		test_mm256_shuffle_pd();
		test_mm256_permute2f128_pd();
		test_mm256_castpd256_pd128();

		///////SSE2NEON TEST
		test_mm_set1_pd();
		test_mm_set_pd();
		test_mm_loadu_pd();
		test_mm_unpacklo_pd();
		test_mm_unpackhi_pd();
		test_mm_add_pd();
		test_mm_mul_pd();
		test_mm_sub_pd();
		test_mm_xor_pd();
		test_mm_cvtsd_f64();
		test_mm_storeu_pd();
		test_mm_cvtsi32_si128();
		test_mm_srli_epi16();
		test_mm_setzero_si128();
		test_mm_cvtsi128_si32();
		test_mm_cvtsi64_si128();
		test_mm_add_epi64();
		test_mm_srli_si128();
		test_mm_load1_pd();
		test_mm_sqrt_pd();
		test_mm_storel_pd();
		
		///////SSE3NEON TEST
		test_mm_hadd_epi16();
}
