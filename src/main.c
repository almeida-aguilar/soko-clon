#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEVELS 255
#define MIN_LEVELS 0

typedef time_t seed_t;

typedef struct {
  seed_t seed;
  uint8_t num_levels;
} game_s;

void print_help() {
  printf("skcln -h                      shows this information\n");
  printf("skcln                         generate infinite levels with a random seed\n");
  printf("skcln <num_levels>            generate n levels with a random seed\n");
  printf("skcln 00 <seed>               generate infinite levels with a custom seed\n");
  printf("skcln <num_levels> <seed>     generate n levels with a custom seed\n");
}

int clamp_uint(int number, int minimun, int maximun) {
  if (number < 0) {
    return 0;
  } else if (number < minimun) {
    return minimun;
  } else if (number > maximun) {
    return maximun;
  }
  return number;
}

int main(int argc, char *argv[]) {
  game_s game;
  game.seed = -1;
  game.num_levels = 0;
  switch (argc) {
  case 1:
    printf("infinite levels with a random seed\n");
    game.seed = time(NULL);
    break;
  case 2:
    if (strcmp("-h", argv[1]) == 0) {
      print_help();
      return 0;
    } else {
      game.num_levels = clamp_uint(atoi(argv[1]), MIN_LEVELS, MAX_LEVELS);
      game.seed = time(NULL);
      printf("n levels with a random seed\n");
    }
    break;
  case 3:
    game.num_levels = clamp_uint(atoi(argv[1]), MIN_LEVELS, MAX_LEVELS);
    game.seed = atoi(argv[2]);
    printf("n or inf levels with custom seed\n");
    break;
  default:
    print_help();
    return 0;
  }

  // Inicializando rand con el seed selecionado.
  srand(game.seed);
  printf("game:\n");
  printf("    seed: %ld\n", game.seed);
  printf("    num_levels: %d\n", game.num_levels);
  return 0;
}
