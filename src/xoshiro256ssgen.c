/*
 * xoshiro256ssgen.c
 *
 * Prints a continuous stream of random numbers 64bit generated with xoshiro256** PRNG to stdout
 * 
 * xoshiro256** pseudorandom number generator - Copyright(C) D.Blackman & S.Vigna (vigna@acm.org)
 *
 * xoshiro256ssgen - Copyright(C) 2026 Matteo Zapparoli (zapparoli.matteo@gmail.com)
 * 
 * SPDX-License-Identifier: Apache-2.0
 *
 * Compile: gcc -O3 xoshiro256ssgen.c -o xoshiro256ssgen
 *
 * Sintax:
 *  xoshiro256ssgen [-r | (<seed> <seed> <seed> <seed>) [-low32 | -high32]]
 *
 * 	xoshiro256ssgen                               Print help
 * 	xoshiro256ssgen -r                            Seeds random (prints values on stderr)
 *  xoshiro256ssgen <seed> <seed> <seed> <seed>   Seeds must be non-zero
 *
 *  option -low32:  write on stdout the lowest 32 bit instead full 64 bit
 *  option -high32: write on stdout the highest 32 bit instead full 64 bit
 * 
 */

#include <stdio.h> // fwrite()
#include <string.h> // strcmp()
#include <stdint.h> // uint64_t
#include <time.h> // clock_gettime()
#include <stdlib.h> // strtoull()
#include <errno.h> // errno
#include <ctype.h> // isdigit()

#define BUF_SIZE 65536

/*
 * xoshiro256** PRNG state.
 */
typedef struct {
    uint64_t s[4];
} Xoshiro256ssState;

uint64_t xoshiro256ss(Xoshiro256ssState *state) 
{
    uint64_t result = state->s[1] * 5;
    result = (result << 7) | (result >> 57);
    result *= 9;

    uint64_t t = state->s[1] << 17;

    state->s[2] ^= state->s[0];
    state->s[3] ^= state->s[1];
    state->s[1] ^= state->s[2];
    state->s[0] ^= state->s[3];

    state->s[2] ^= t;
    state->s[3] = (state->s[3] << 45) | (state->s[3] >> 19);

    return result;
}

void usage(void)
{
	printf("xoshiro256ssgen - Continous xoshiro256** stdout pseudo number 64bit generator in binary format\n");
	printf("Usage:\n");
	printf("      xoshiro256ssgen [-r | (<seed> <seed> <seed> <seed>) [-low32 | -high32]]\n");
	printf("\n");
	printf("      xoshiro256ssgen                              Print help\n");
	printf("      xoshiro256ssgen -r                           Seeds random (prints values on stderr)\n");
	printf("      xoshiro256ssgen <seed> <seed> <seed> <seed>  Seeds must be non-zero\n");
	printf("\n");
	printf("option -low32: write on stdout the lowest 32 bit instead full 64 bit\n");
	printf("option -high32: write on stdout the highest 32 bit instead full 64 bit\n");
}

// Return 1 id str a uint64_t, 0 else
int is_valid_uint64(const char *str, uint64_t *out_value)
{
	if (str == NULL || *str == '\0') return 0;

	// Controlla che la stringa contenga solo cifre
	for (const char *p = str; *p; p++) {
		if (!isdigit((unsigned char)*p)) return 0;
	}

	errno = 0;
	char *end;
	unsigned long long v = strtoull(str, &end, 10);

	// end non deve spostarsi oltre la fine
	if (*end != '\0') return 0;

	// Overflow rilevato da errno
	if (errno == ERANGE) return 0;

	// Controllo ulteriore: strtoull potrebbe essere > UINT64_MAX su alcune piattaforme
	if (v > UINT64_MAX) return 0;

	if (out_value) *out_value = (uint64_t)v;

	return 1;
}

// Return a simple "pseudo-random" based on clock
uint64_t random_from_clock(void) 
{
	static uint64_t counter = 0;
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);

	uint64_t x = ((uint64_t)ts.tv_sec << 32) ^ (uint64_t)ts.tv_nsec;

	// aggiungi un contatore per garantire unicità
	x ^= (++counter * 0x9E3779B97F4A7C15ULL);

	// mixing forte (stile splitmix64)
	x ^= x >> 33;
	x *= 0xff51afd7ed558ccdULL;
	x ^= x >> 33;
	x *= 0xc4ceb9fe1a85ec53ULL;
	x ^= x >> 33;

	return x;
}

// Return -32 if option = "low32"
//        +32 if option = "high32"
//          0 else
int check_low_high(char *option)
{
	if(strcmp(option, "-low32") == 0) return -32;
	
	if(strcmp(option, "-high32") == 0) return +32;

	return 0;
}

int main(int argc, char *argv[])
{
	Xoshiro256ssState state;
	int low_high_option;
	
	if(argc <= 1) {
		usage();
		return 0;
	}
	
	if(argc > 6) {
		fprintf(stderr, "*** Error: invalid arguments\n");
		return 1;
	}
	
	low_high_option = check_low_high(argv[argc - 1]);
	
	if(strcmp(argv[1], "-r") == 0) {
		if(argc > 2 && low_high_option == 0) {
			fprintf(stderr, "*** Error: invalid argument %s\n", argv[2]);
			return 1;
		}
		
		for(int i = 0; i < 4; i++)
			state.s[i] = random_from_clock();
		
		fprintf(stderr, "xoshiro256ssgen: seed0 = %llu, seed1 = %llu seed2 = %llu, seed3 = %llu\n", 
		                (unsigned long long)state.s[0], 
						(unsigned long long)state.s[1],
						(unsigned long long)state.s[2],
						(unsigned long long)state.s[3]);
	}
	else if(is_valid_uint64(argv[1], &(state.s[0])) 
	        && is_valid_uint64(argv[2], &(state.s[1]))
		    && is_valid_uint64(argv[3], &(state.s[2]))
			&& is_valid_uint64(argv[4], &(state.s[3]))) {

				if(argc == 6 && low_high_option == 0) {
					fprintf(stderr, "*** Error: invalid argument %s\n", argv[5]);
					return 1;
				}
	}
	else {
		fprintf(stderr, "*** Error: invalid arguments\n");
		return 1;
	}
	
	for(int i = 0; i < 4; i++) {
		if(state.s[i] == 0) {
			fprintf(stderr, "*** Error: seeds must be non-zero\n");
			return 1;
		}
	}

	if(low_high_option == -32) { // 4 byte bassi
		uint32_t buffer[BUF_SIZE];
		for(;;) {
			for(int i = 0; i < BUF_SIZE; i++) {
				buffer[i] = (uint32_t)xoshiro256ss(&state);
			}
			fwrite(buffer, sizeof(uint32_t), BUF_SIZE, stdout);
		}
	}
	else if(low_high_option == +32) { // 4 byte alti
		uint32_t buffer[BUF_SIZE];
		for(;;) {
			for(int i = 0; i < BUF_SIZE; i++) {
				buffer[i] = (uint32_t)(xoshiro256ss(&state) >> 32);
			}
			fwrite(buffer, sizeof(uint32_t), BUF_SIZE, stdout);
		}
	}
	else { // Tutti gli 8 byte
		uint64_t buffer[BUF_SIZE];
		for(;;) {
			for(int i = 0; i < BUF_SIZE; i++) {
				buffer[i] = xoshiro256ss(&state);
			}
			fwrite(buffer, sizeof(uint64_t), BUF_SIZE, stdout);
		}
	}

	return 0;
}
