#include <immintrin.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_m256d(__m256d a){
	double buffer[4];
	_mm256_storeu_pd(buffer, a);
	printf("%.17g,", buffer[3]);
	printf("%.17g,", buffer[2]);
	printf("%.17g,", buffer[1]);
	printf("%.17g\n", buffer[0]);
}

void print_m128d(__m128d a){
	double buffer[4];
	_mm_storeu_pd(buffer, a);
	printf("%.17g,", buffer[1]);
	printf("%.17g\n", buffer[0]);
}
void print_m256i(__m256i a){
    long long int  buffer[4];
    _mm256_storeu_si256((__m256i_u *)buffer, a);
    printf("%lld,", buffer[3]);
	printf("%lld,", buffer[2]);
	printf("%lld,", buffer[1]);
	printf("%lld\n", buffer[0]);
}


void print_m128i(__m128i a){
	long long int  buffer[2];
	_mm_storeu_si128 ((__m128i*) buffer, a);
	printf("%lld,", buffer[1]);
	printf("%lld\n", buffer[0]);
}
__m256d read_m256d(FILE *fp, const int n_line){
	int ret = fseek(fp, 0 ,SEEK_SET);
	if (ret != 0){
			perror("Error read_m256d");
			exit(1);
	}
	char *line = NULL;
	size_t len = 0;
	for (int i = 0; i<=n_line; ++i){
		if(getline(&line, &len, fp) == -1){
			perror("Error read_m256d");
			exit(1);
		}
	}
	double n[4];
	int i = 3;
	char* token;
	while ((token = strsep(&line, ",")) != NULL){
		n[i] = atof(token);
		--i;
	}
	return _mm256_loadu_pd(&n[0]);
}

__m128d read_m128d(FILE *fp, const int n_line){
	int ret = fseek(fp, 0 ,SEEK_SET);
	if (ret != 0){
			perror("Error read_m128d");
			exit(1);
	}
	char *line = NULL;
	size_t len = 0;
	for (int i = 0; i<=n_line; ++i){
		if(getline(&line, &len, fp) == -1){
			perror("Error read_m128d");
			exit(1);
		}
	}
	double n[2];
	int i = 1;
	char* token;
	while ((token = strsep(&line, ",")) != NULL){
		n[i] = atof(token);
		--i;
	}
	return _mm_load_pd(&n[0]);
}



__m256i read_m256i(FILE *fp, const int n_line){
	int ret = fseek(fp, 0 ,SEEK_SET);
	if (ret != 0){
			perror("Error read_m256i");
			exit(1);
	}
	char *line = NULL;
	size_t len = 0;
	for (int i = 0; i<=n_line; ++i){
		if(getline(&line, &len, fp) == -1){
			perror("Error read_m128i");
			exit(1);
		}
	}
	long long int n[4];
	int i = 3;
	char* token;
	while ((token = strsep(&line, ",")) != NULL){
		n[i] = atoll(token);
		--i;
	}
	return _mm256_loadu_si256((__m128i const *) &n[0]);
}

__m128i read_m128i(FILE *fp, const int n_line){
	int ret = fseek(fp, 0 ,SEEK_SET);
	if (ret != 0){
			perror("Error read_m128i");
			exit(1);
	}
	char *line = NULL;
	size_t len = 0;
	for (int i = 0; i<=n_line; ++i){
		if(getline(&line, &len, fp) == -1){
			perror("Error read_m128i");
			exit(1);
		}
	}
	long long int n[2];
	int i = 1;
	char* token;
	while ((token = strsep(&line, ",")) != NULL){
		n[i] = atoll(token);
		--i;
	}
	return _mm_load_si128((__m128i const *) &n[0]);
}

int read_int(FILE *fp, const int n_line){
	int ret = fseek(fp, 0 ,SEEK_SET);
	if (ret != 0){
			perror("Error read_int");
			exit(1);
	}
	char *line = NULL;
	size_t len = 0;
	for (int i = 0; i<=n_line; ++i){
		if(getline(&line, &len, fp) == -1){
			perror("Error read_int");
			exit(1);
		}
	}
	return atoi(line);
}

long long int read_int64(FILE *fp, const int n_line){
	int ret = fseek(fp, 0 ,SEEK_SET);
	if (ret != 0){
			perror("Error read_int");
			exit(1);
	}
	char *line = NULL;
	size_t len = 0;
	for (int i = 0; i<=n_line; ++i){
		if(getline(&line, &len, fp) == -1){
			perror("Error read_int");
			exit(1);
		}
	}
	return atoll(line);
}


double read_double(FILE *fp, const int n_line){
	int ret = fseek(fp, 0 ,SEEK_SET);
	if (ret != 0){
			perror("Error read_int");
			exit(1);
	}
	char *line = NULL;
	size_t len = 0;
	for (int i = 0; i<=n_line; ++i){
		if(getline(&line, &len, fp) == -1){
			perror("Error read_int");
			exit(1);
		}
	}
	return atof(line);
}

int search_line(FILE *fp, char* str){
	int ret = fseek(fp, 0 ,SEEK_SET);
	if (ret != 0){
			perror("Error search_line");
			exit(1);
	}
	char *line = NULL;
	size_t len = 0;
	int i = 0;
	while (getline(&line, &len, fp) != -1){
		if(strcmp(str, line) == 0){
			return i; 
		}
		++i;
	}
	perror("Error search_line");
	exit(1);
}



void test_mm256_broadcastq_epi64(FILE *fp){
	char *command = "_mm256_broadcastq_epi64()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128i a = read_m128i(fp, ret+1);
	print_m128i(a);
	print_m256i(_mm256_broadcastq_epi64(a));
}

void test_mm256_broadcastw_epi16(FILE *fp){
	char *command = "_mm256_broadcastw_epi16()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128i a = read_m128i(fp, ret+1);
	print_m128i(a);
	print_m256i(_mm256_broadcastw_epi16(a));
}
void test_mm256_and_si256(FILE *fp){
	char *command = "_mm256_and_si256()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	__m256i b = read_m256i(fp, ret+2);
	print_m256i(b);
	print_m256i(_mm256_and_si256(a,b));
}
void test_mm256_cvtepi16_epi64(FILE *fp){
	char *command = "_mm256_cvtepi16_epi64()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128i a = read_m128i(fp, ret+1);
	print_m128i(a);
	print_m256i(_mm256_cvtepi16_epi64(a));
}


void test_mm256_permute4x64_epi64(FILE *fp){
	char *command = "_mm256_permute4x64_epi64()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	int imm8 = 55;
	printf("%d\n", imm8);
	print_m256i(_mm256_permute4x64_epi64(a,imm8));
}



void test_mm256_or_si256(FILE *fp){
	char *command = "_mm256_or_si256()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	__m256i b = read_m256i(fp, ret+2);
	print_m256i(b);
	print_m256i(_mm256_or_si256(a,b));
}
void test_mm256_add_epi64(FILE *fp){
	char *command = "_mm256_add_epi64()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	__m256i b = read_m256i(fp, ret+2);
	print_m256i(b);
	print_m256i(_mm256_add_epi64(a,b));	
}
void test_mm256_extracti128_si256(FILE *fp){
	char *command = "_mm256_extracti128_si256()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	int imm8 = 1;
	printf("%d\n", imm8);
	print_m128i(_mm256_extracti128_si256(a,imm8));
}
void test_mm256_broadcastd_epi32(FILE *fp){
	char *command = "_mm256_broadcastd_epi32()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128i a = read_m128i(fp, ret+1);
	print_m128i(a);
	print_m256i(_mm256_broadcastd_epi32(a));
}
void test_mm256_xor_si256(FILE *fp){
	char *command = "_mm256_xor_si256()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	__m256i b = read_m256i(fp, ret+2);
	print_m256i(b);
	print_m256i(_mm256_xor_si256(a,b));	
}
void test_mm256_slli_epi32(FILE *fp){
	char *command = "_mm256_slli_epi32()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	int imm8 = read_int(fp,ret+2);
	printf("%d\n", imm8);
	print_m256i(_mm256_slli_epi32(a,imm8));
}
void test_mm256_srli_epi32(FILE *fp){
	char *command = "_mm256_srli_epi32()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	int imm8 = read_int(fp,ret+2);
	printf("%d\n", imm8);
	print_m256i(_mm256_srli_epi32(a,imm8));
}
void test_mm256_add_epi32(FILE *fp){
	char *command = "_mm256_add_epi32()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	__m256i b = read_m256i(fp, ret+2);
	print_m256i(b);
	print_m256i(_mm256_add_epi64(a,b));	
}
void test_mm256_permute4x64_pd(FILE *fp){
	char *command = "_mm256_permute4x64_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d a = read_m256d(fp, ret+1);
	print_m256d(a);
	int imm8 = 246;
	printf("%d\n", imm8);
	print_m256d(_mm256_permute4x64_pd(a,imm8));
}
void test_mm256_cmpgt_epi64(FILE *fp){
	char *command = "_mm256_cmpgt_epi64()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	__m256i b = read_m256i(fp, ret+2);
	print_m256i(b);
	print_m256i(_mm256_cmpgt_epi64(a,b));	
}
void test_mm256_bsrli_epi128(FILE *fp){
	char *command = "_mm256_bsrli_epi128()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	print_m256i(_mm256_bsrli_epi128(a, 0));
	print_m256i(_mm256_bsrli_epi128(a, 1));
	print_m256i(_mm256_bsrli_epi128(a, 2));
	print_m256i(_mm256_bsrli_epi128(a, 3));
	print_m256i(_mm256_bsrli_epi128(a, 4));
	print_m256i(_mm256_bsrli_epi128(a, 5));
	print_m256i(_mm256_bsrli_epi128(a, 6));
	print_m256i(_mm256_bsrli_epi128(a, 7));
	print_m256i(_mm256_bsrli_epi128(a, 8));
	print_m256i(_mm256_bsrli_epi128(a, 9));
	print_m256i(_mm256_bsrli_epi128(a, 10));
	print_m256i(_mm256_bsrli_epi128(a, 11));
	print_m256i(_mm256_bsrli_epi128(a, 12));
	print_m256i(_mm256_bsrli_epi128(a, 13));
	print_m256i(_mm256_bsrli_epi128(a, 14));
	print_m256i(_mm256_bsrli_epi128(a, 15));
	print_m256i(_mm256_bsrli_epi128(a, 16));
}

///////AVXNEON TEST
void test_mm256_set_pd(FILE *fp){
	char *command = "_mm256_set_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	double e3 = read_double(fp, ret+1);
	printf("%.17g\n", e3);
	double e2 = read_double(fp, ret+2);
	printf("%.17g\n", e2);
	double e1 = read_double(fp, ret+3);
	printf("%.17g\n", e1);
	double e0 = read_double(fp, ret+4);
	printf("%.17g\n", e0);
	print_m256d(_mm256_set_pd(e3 , e2, e1, e0));
}
void test_mm256_mul_pd(FILE *fp){
	char *command = "_mm256_mul_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d a = read_m256d(fp, ret+1);
	print_m256d(a);
	__m256d b = read_m256d(fp, ret+2);
	print_m256d(b);
	print_m256d(_mm256_mul_pd(a,b));	
}
void test_mm256_add_pd(FILE *fp){
	char *command = "_mm256_add_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d a = read_m256d(fp, ret+1);
	print_m256d(a);
	__m256d b = read_m256d(fp, ret+2);
	print_m256d(b);
	print_m256d(_mm256_add_pd(a,b));	
}
void test_mm256_sub_pd(FILE *fp){
	char *command = "_mm256_sub_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d a = read_m256d(fp, ret+1);
	print_m256d(a);
	__m256d b = read_m256d(fp, ret+2);
	print_m256d(b);
	print_m256d(_mm256_sub_pd(a,b));
}
void test_mm256_xor_pd(FILE *fp){
	char *command = "_mm256_xor_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d a = read_m256d(fp, ret+1);
	print_m256d(a);
	__m256d b = read_m256d(fp, ret+2);
	print_m256d(b);
	print_m256d(_mm256_xor_pd(a,b));
}
void test_mm256_unpacklo_pd(FILE *fp){
	char *command = "_mm256_unpacklo_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d a = read_m256d(fp, ret+1);
	print_m256d(a);
	__m256d b = read_m256d(fp, ret+2);
	print_m256d(b);
	print_m256d(_mm256_unpacklo_pd(a,b));
}
void test_mm256_unpackhi_pd(FILE *fp){
	char *command = "_mm256_unpackhi_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d a = read_m256d(fp, ret+1);
	print_m256d(a);
	__m256d b = read_m256d(fp, ret+2);
	print_m256d(b);
	print_m256d(_mm256_unpackhi_pd(a,b));	
}
void test_mm_permute_pd(FILE *fp){
	char *command = "_mm_permute_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128d a = read_m128d(fp, ret+1);
	print_m128d(a);
	int imm8 = 3;
	printf("%d\n", imm8);
	print_m128d(_mm_permute_pd(a,imm8));
}
void test_mm256_loadu_si256(FILE *fp){
	char *command = "_mm256_loadu_si256()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	print_m256i(_mm256_loadu_si256(&a));
}
void test_mm256_cmpgt_epi16(FILE *fp){
	char *command = "_mm256_cmpgt_epi16()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	__m256i b = read_m256i(fp, ret+2);
	print_m256i(b);
	print_m256i(_mm256_cmpgt_epi16(a,b));
}
void test_mm256_cmpeq_epi16(FILE *fp){
	char *command = "_mm256_cmpeq_epi16()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	__m256i b = read_m256i(fp, ret+2);
	print_m256i(b);
	print_m256i(_mm256_cmpeq_epi16(a,b));
}
void test_mm256_castsi256_si128(FILE *fp){
	char *command = "_mm256_castsi256_si128()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	print_m128i(_mm256_castsi256_si128(a));
}
void test_mm256_storeu_si256(FILE *fp){
	char *command = "_mm256_storeu_si256()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256i a = read_m256i(fp, ret+1);
	print_m256i(a);
	long long int  buffer[4];
	_mm256_storeu_si256 ((__m256i *) &buffer[0], a);
	printf("%lld,", buffer[3]);
	printf("%lld,", buffer[2]);
	printf("%lld,", buffer[1]);
	printf("%lld\n", buffer[0]);
}
void test_mm256_set1_pd(FILE *fp){
	char *command = "_mm256_set1_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	double a = read_double(fp, ret+1);
	printf("%.17g\n", a);
	print_m256d(_mm256_set1_pd(a));
}

void test_mm256_loadu_pd(FILE *fp){
	char *command = "_mm256_loadu_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d mem_addr = read_m256d(fp, ret+1);
	print_m256d(mem_addr);
	print_m256d(_mm256_loadu_pd(&mem_addr));
}
void test_mm256_storeu_pd(FILE *fp){
	char *command = "_mm256_storeu_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d a = read_m256d(fp, ret+1);
	print_m256d(a);
	double  buffer[4];
	_mm256_storeu_pd(&buffer[0], a);
	printf("%.17g,", buffer[3]);
	printf("%.17g,", buffer[2]);
	printf("%.17g,", buffer[1]);
	printf("%.17g\n", buffer[0]);
}
void test_mm256_setzero_pd(FILE *fp){
	char *command = "_mm256_setzero_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	print_m256d(_mm256_setzero_pd());
}
void test_mm256_div_pd(FILE *fp){
	char *command = "_mm256_div_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d a = read_m256d(fp, ret+1);
	print_m256d(a);
	__m256d b = read_m256d(fp, ret+2);
	print_m256d(b);
	print_m256d(_mm256_div_pd(a,b));	
}
void test_mm256_hadd_pd(FILE *fp){
	char *command = "_mm256_hadd_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d a = read_m256d(fp, ret+1);
	print_m256d(a);
	__m256d b = read_m256d(fp, ret+2);
	print_m256d(b);
	print_m256d(_mm256_hadd_pd(a,b));	
}

void test_mm256_extractf128_pd(FILE *fp){
	char *command = "_mm256_extractf128_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d a = read_m256d(fp, ret+1);
	print_m256d(a);
	int imm8 = 1;
	printf("%d\n", imm8);
	print_m128d(_mm256_extractf128_pd(a, imm8));
}
void test_mm256_hsub_pd(FILE *fp){
	char *command = "_mm256_hsub_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d a = read_m256d(fp, ret+1);
	print_m256d(a);
	__m256d b = read_m256d(fp, ret+2);
	print_m256d(b);
	print_m256d(_mm256_hsub_pd(a,b));	
}
void test_mm256_shuffle_pd(FILE *fp){
	char *command = "_mm256_shuffle_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d a = read_m256d(fp, ret+1);
	print_m256d(a);
	__m256d b = read_m256d(fp, ret+2);
	print_m256d(b);
	int imm8 = 1;
	printf("%d\n", imm8);
	print_m256d(_mm256_shuffle_pd(a,b,imm8));
}
void test_mm256_permute2f128_pd(FILE *fp){
	char *command = "_mm256_permute2f128_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d a = read_m256d(fp, ret+1);
	print_m256d(a);
	__m256d b = read_m256d(fp, ret+2);
	print_m256d(b);
	int imm8 = 176;
	printf("%d\n", imm8);
	print_m256d(_mm256_permute2f128_pd(a,b,imm8));
}
void test_mm256_castpd256_pd128(FILE *fp){
	char *command = "_mm256_castpd256_pd128()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m256d a = read_m256d(fp, ret+1);
	print_m256d(a);
	print_m128d(_mm256_castpd256_pd128(a));
}

///////SSE2NEON TEST
void test_mm_set1_pd(FILE *fp){
	char *command = "_mm_set1_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	double a = read_double(fp, ret+1);
	printf("%.17g\n", a);
	print_m128d(_mm_set1_pd(a));
}
void test_mm_set_pd(FILE *fp){
	char *command = "_mm_set_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	double e1 = read_double(fp, ret+1);
	printf("%.17g\n", e1);
	double e0 = read_double(fp, ret+2);
	printf("%.17g\n", e0);
	print_m128d(_mm_set_pd(e1,e0));
}
void test_mm_loadu_pd(FILE *fp){
	char *command = "_mm_loadu_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128d a = read_m128d(fp, ret+1);
	print_m128d(a);
 	print_m128d(_mm_loadu_pd(&a));
}
void test_mm_unpacklo_pd(FILE *fp){
	char *command = "_mm_unpacklo_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128d a = read_m128d(fp, ret+1);
	print_m128d(a);
	__m128d b = read_m128d(fp, ret+2);
	print_m128d(b);
	print_m128d(_mm_unpacklo_pd(a,b));	
}
void test_mm_unpackhi_pd(FILE *fp){
	char *command = "_mm_unpackhi_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128d a = read_m128d(fp, ret+1);
	print_m128d(a);
	__m128d b = read_m128d(fp, ret+2);
	print_m128d(b);
	print_m128d(_mm_unpackhi_pd(a,b));	
}
void test_mm_add_pd(FILE *fp){
	char *command = "_mm_add_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128d a = read_m128d(fp, ret+1);
	print_m128d(a);
	__m128d b = read_m128d(fp, ret+2);
	print_m128d(b);
	print_m128d(_mm_add_pd(a,b));	
}
void test_mm_mul_pd(FILE *fp){
	char *command = "_mm_mul_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128d a = read_m128d(fp, ret+1);
	print_m128d(a);
	__m128d b = read_m128d(fp, ret+2);
	print_m128d(b);
	print_m128d(_mm_mul_pd(a,b));	
}
void test_mm_sub_pd(FILE *fp){
	char *command = "_mm_sub_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128d a = read_m128d(fp, ret+1);
	print_m128d(a);
	__m128d b = read_m128d(fp, ret+2);
	print_m128d(b);
	print_m128d(_mm_sub_pd(a,b));	
}
void test_mm_xor_pd(FILE *fp){
	char *command = "_mm_xor_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128d a = read_m128d(fp, ret+1);
	print_m128d(a);
	__m128d b = read_m128d(fp, ret+2);
	print_m128d(b);
	print_m128d(_mm_xor_pd(a,b));	
}
void test_mm_cvtsd_f64(FILE *fp){
	char *command = "_mm_cvtsd_f64()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128d a = read_m128d(fp, ret+1);
	print_m128d(a);
	printf("%.17g\n", _mm_cvtsd_f64(a));
}
void test_mm_storeu_pd(FILE *fp){
	char *command = "_mm_storeu_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128d a = read_m128d(fp, ret+1);
	print_m128d(a);
	double mem_addr[2];
	_mm_storeu_pd(mem_addr,a);
	printf("%.17g,", mem_addr[1]);
	printf("%.17g\n", mem_addr[0]);
}
void test_mm_cvtsi32_si128(FILE *fp){
	char *command = "_mm_cvtsi32_si128()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	int a = read_int(fp, ret+1);
	printf("%d\n", a);
	print_m128i(_mm_cvtsi32_si128(a));
}
void test_mm_srli_epi16(FILE *fp){
	char *command = "_mm_srli_epi16()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128i a = read_m128i(fp, ret+1);
	print_m128i(a);
	int imm8 = read_int(fp, ret+2);
	printf("%d\n", imm8);
	print_m128i(_mm_srli_epi16(a, imm8));
}
void test_mm_setzero_si128(FILE *fp){
	char *command = "_mm_setzero_si128()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	print_m128i(_mm_setzero_si128());
}
void test_mm_cvtsi128_si32(FILE *fp){
	char *command = "_mm_cvtsi128_si32()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128i a = read_m128i(fp, ret+1);
	print_m128i(a);
	printf("%d\n",  _mm_cvtsi128_si32 (a));
}
void test_mm_cvtsi64_si128(FILE *fp){
	char *command = "_mm_cvtsi64_si128()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	long long int a = read_int64(fp, ret+1);
	printf("%lld\n", a);
	print_m128i(_mm_cvtsi64_si128(a));
}
void test_mm_add_epi64(FILE *fp){
	char *command = "_mm_add_epi64()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128i a = read_m128i(fp, ret+1);
	print_m128i(a);
	__m128i b = read_m128i(fp, ret+2);
	print_m128i(b);
	print_m128i(_mm_add_epi64(a,b));		
}
void test_mm_srli_si128(FILE *fp){
	char *command = "_mm_srli_si128()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128i a = read_m128i(fp, ret+1);
	print_m128i(a);
	print_m128i(_mm_srli_si128(a, 0));
	print_m128i(_mm_srli_si128(a, 1));
	print_m128i(_mm_srli_si128(a, 2));
	print_m128i(_mm_srli_si128(a, 3));
	print_m128i(_mm_srli_si128(a, 4));
	print_m128i(_mm_srli_si128(a, 5));
	print_m128i(_mm_srli_si128(a, 6));
	print_m128i(_mm_srli_si128(a, 7));
	print_m128i(_mm_srli_si128(a, 8));
	print_m128i(_mm_srli_si128(a, 9));
	print_m128i(_mm_srli_si128(a, 10));
	print_m128i(_mm_srli_si128(a, 11));
	print_m128i(_mm_srli_si128(a, 12));
	print_m128i(_mm_srli_si128(a, 13));
	print_m128i(_mm_srli_si128(a, 14));
	print_m128i(_mm_srli_si128(a, 15));
	print_m128i(_mm_srli_si128(a, 16));
}
void test_mm_load1_pd(FILE *fp){
	char *command = "_mm_load1_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	double a = read_double(fp, ret+1);
	printf("%.17g\n", a);
	print_m128d(_mm_load1_pd(&a));
}
void test_mm_sqrt_pd(FILE *fp){
	char *command = "_mm_sqrt_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128d a = read_m128d(fp, ret+1);
	print_m128d(a);
	print_m128d(_mm_sqrt_pd(a));
}
void test_mm_storel_pd(FILE *fp){
	char *command = "_mm_storel_pd()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128d a = read_m128d(fp, ret+1);
	print_m128d(a);
	double a2[1];
	_mm_storel_pd(a2, a);
	printf("%.17g\n", a2[0]);
}

///////SSE3NEON TEST
void test_mm_hadd_epi16(FILE *fp){
	char *command = "_mm_hadd_epi16()\n";
	printf("%s", command);
	int ret = search_line(fp, command);
	__m128i a = read_m128i(fp, ret+1);
	print_m128i(a);
	__m128i b = read_m128i(fp, ret+2);
	print_m128i(b);
	print_m128i(_mm_hadd_epi16(a,b));	
}
		
	
int main(int argc, char* argv[]){
		FILE *fp;
		fp = fopen(argv[1], "r");
		if (fp == NULL){
			perror("Error fopen");
			exit(1);
		}
		///////AVX2NEON TEST
		test_mm256_broadcastq_epi64(fp);
		test_mm256_broadcastw_epi16(fp);
		test_mm256_and_si256(fp);
		test_mm256_cvtepi16_epi64(fp);
		//1
		test_mm256_permute4x64_epi64(fp);
		test_mm256_or_si256(fp);
		test_mm256_add_epi64(fp);
		//2
		test_mm256_extracti128_si256(fp);
		test_mm256_broadcastd_epi32(fp);
		test_mm256_xor_si256(fp);
		test_mm256_slli_epi32(fp);
		test_mm256_srli_epi32(fp);
		test_mm256_add_epi32(fp);
		//3
		test_mm256_permute4x64_pd(fp);
		test_mm256_cmpgt_epi64(fp);
		test_mm256_bsrli_epi128(fp);

		///////AVXNEON TEST
		test_mm256_set_pd(fp);
		test_mm256_mul_pd(fp);
		test_mm256_add_pd(fp);
		test_mm256_sub_pd(fp);
		test_mm256_xor_pd(fp);
		test_mm256_unpacklo_pd(fp);
		test_mm256_unpackhi_pd(fp);
		//4
		test_mm_permute_pd(fp);
		test_mm256_loadu_si256(fp);
		test_mm256_cmpgt_epi16(fp);
		test_mm256_cmpeq_epi16(fp);
		test_mm256_castsi256_si128(fp);
		test_mm256_storeu_si256(fp);
		test_mm256_set1_pd(fp);
		test_mm256_loadu_pd(fp);
		test_mm256_storeu_pd(fp);
		test_mm256_setzero_pd(fp);
		test_mm256_div_pd(fp);
		test_mm256_hadd_pd(fp);
		//5
		test_mm256_extractf128_pd(fp);
		test_mm256_hsub_pd(fp);
		//6
		test_mm256_shuffle_pd(fp);
		//7
		test_mm256_permute2f128_pd(fp);
		test_mm256_castpd256_pd128(fp);

		///////SSE2NEON TEST
		test_mm_set1_pd(fp);
		test_mm_set_pd(fp);
		test_mm_loadu_pd(fp);
		test_mm_unpacklo_pd(fp);
		test_mm_unpackhi_pd(fp);
		test_mm_add_pd(fp);
		test_mm_mul_pd(fp);
		test_mm_sub_pd(fp);
		test_mm_xor_pd(fp);
		test_mm_cvtsd_f64(fp);
		test_mm_storeu_pd(fp);
		test_mm_cvtsi32_si128(fp);
		test_mm_srli_epi16(fp);
		test_mm_setzero_si128(fp);
		test_mm_cvtsi128_si32(fp);
		test_mm_cvtsi64_si128(fp);
		test_mm_add_epi64(fp);
		test_mm_srli_si128(fp);
		test_mm_load1_pd(fp);
		test_mm_sqrt_pd(fp);
		test_mm_storel_pd(fp);

		///////SSE3NEON TEST
		test_mm_hadd_epi16(fp);
}


