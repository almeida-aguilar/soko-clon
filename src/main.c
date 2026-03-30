#include <raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define ROWS 10
#define LINES 10

typedef long seed_t;

typedef enum {
	WALL = '#',
	PUSHER = '@',
	PUSHER_ON_GOAL = '+',
	BOX = '$',
	BOX_ON_GOAL = '*',
	GOAL = '.',
	FLOOR = ' ',
} cell_e;

void print_help() {
	printf("skcln -h                      shows this information\n");
	printf("skcln <file.sok>              open an indivisual level\n");
}

char level[ROWS * LINES];

void init_level(char *file_name) {
	char line[64];
	int idx = 0;

	FILE *fptr = fopen(file_name, "r");

	if (!fptr) {
		printf("Not able to open the level\n");
	}

	while (fgets(line, sizeof(line), fptr) && idx < ROWS * LINES) {
		for (int i = 0; line[i] != '\0' && line[i] != '\n' && line[i] != '\r'; i++) {
			if (idx < ROWS * LINES) {
				level[idx++] = line[i];
			}
		}
	}

	fclose(fptr);
}

int cords_to_idx(int x, int y) { return (y * 10 + x); }

int main(int argc, char *argv[]) {

	char *file_name;
	seed_t seed = 0;
	if (argc == 2) {
		if (strcmp(argv[1], "-h") == 0) {
			print_help();
			return 0;
		} else {
			file_name = argv[1];
		}
	} else {
		print_help();
		return 0;
	}

	init_level(file_name);
	printf("init game:\n");
	printf("    file: %s\n", file_name);
	printf("    level: %s\n", level);
	printf("    player: %c\n", level[cords_to_idx(2, 2)]);

	const int16_t screen_width = 800;
	const int16_t screen_height = 800;

	InitWindow(screen_width, screen_height, "Soko Clon");

	SetTargetFPS(60);
	int x = 0;
	int y = 0;
	int r = 40;
	int player_idx = 0;
	Vector2 player = (Vector2){0, 0};

	for (int i = 0; i < ROWS * LINES; i++) {
		if (level[i] == PUSHER) {
			player_idx = level[i];
			break;
		}
	}

	while (!WindowShouldClose()) {
		// Update
		if (IsKeyPressed(KEY_S)) {
			player.x -= 1;
		}

		// Draw

		BeginDrawing();
		ClearBackground(WHITE);
		for (int i = 0; i < ROWS * LINES; i++) {
			x = (i % 10) * 80;
			y = (i / 10) * 80;
			if (level[i] == WALL) {
				DrawRectangle(x, y, 80, 80, GRAY);
			} else if (level[i] == BOX) {
				DrawRectangle(x + 5, y + 5, 70, 70, BROWN);
			} else if (level[i] == GOAL) {
				DrawCircle(x + r, y + r, r - 20, GREEN);
			} else if (level[i] == PUSHER) {
				DrawCircle(x + r, y + r, r - 10, BLUE);
			} else if (level[i] == BOX_ON_GOAL) {
				DrawRectangle(x, y, 80, 80, BROWN);
				DrawCircle(x + r, y + r, r - 20, GREEN);
			} else if (level[i] == PUSHER_ON_GOAL) {
				DrawCircle(x, y, r, BLUE);
				DrawCircle(x + r, y + r, r - 20, GREEN);
			}
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
