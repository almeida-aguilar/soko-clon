#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef long seed_t;

void print_help() {
	printf("skcln -h                      shows this information\n");
	printf("skcln                         generate levels with a random seed\n");
	printf("skcln <seed>                  generate levels with a custom seed\n");
}

int main(int argc, char *argv[]) {
	seed_t seed = 0;
	switch (argc) {
	case 1:
		printf("random seed\n");
		seed = time(NULL);
		break;
	case 2:
		if (strcmp("-h", argv[1]) == 0) {
			print_help();
			return 0;
		} else {
			char *end;
			seed = (seed_t)strtol(argv[1], &end, 10);
			if (argv[1] == end) {
				fprintf(stderr, "Error: Seed format not supported, seed have to be a number.\n");
				return 1;
			}
		}
		break;
	default:
		print_help();
		return 0;
	}

	printf("init game:\n");
	printf("    seed: %ld\n", seed);
	return 0;
}
