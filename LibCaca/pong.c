/*
** EPITECH PROJECT, 2018
** Cobra
** File description:
** pong
*/

#include <caca.h>

typedef struct pos {
	float x;
	float y;
} pos_t;

void move(int key, pos_t *pos)
{
	if (key == CACA_KEY_LEFT)
		pos->x -= 2;
	if (key == CACA_KEY_RIGHT)
		pos->x += 2;
}

void clear(caca_canvas_t *bar1)
{
	caca_set_color_ansi(bar1, CACA_BLACK, CACA_BLACK);
	caca_clear_canvas(bar1);
	caca_set_color_ansi(bar1, CACA_BLACK, CACA_WHITE);
}

int check_ball(pos_t *mvt, pos_t *pos, pos_t bar, int *score)
{
	if (pos->x <= 0 || pos->x >= 80)
		mvt->x = mvt->x * -1;
	if (pos->y <= 2)
		mvt->y = mvt->y * -1;
	if (pos->y >= bar.y) {
		if (pos->x >= bar.x && pos->x <= bar.x + 12) {
			mvt->y = mvt->y * -1;
			score[0]++;
		}
		else
			return (1);
	}
	pos->x += mvt->x;
	pos->y += mvt->y;
	return (0);
}

int main(void)
{
	caca_display_t *win = caca_create_display(NULL);
	caca_event_t ev;
	caca_canvas_t *canv = caca_get_canvas(win);
	pos_t pos1 = {32, 30};
	pos_t pos_b = {1, 15};
	pos_t mvt = {0.04, -0.04};
	int score = 0;
	int key = 0;

	caca_set_color_ansi(canv, CACA_BLACK, CACA_WHITE);
	do {
		clear(canv);
		caca_printf(canv, 1, 2, "Your score : %d", score);
		caca_put_str(canv, pos1.x, pos1.y, "------------");
		caca_put_str(canv, pos_b.x-5, 1, "------------");
		caca_put_str(canv, pos_b.x, pos_b.y, "*");
		caca_get_event(win, CACA_EVENT_KEY_PRESS, &ev, 1);
		key = ev.data.key.ch;
		if (check_ball(&mvt, &pos_b, pos1, &score) == 1)
			break;
		move(key, &pos1);
		caca_refresh_display(win);
	} while (key != CACA_KEY_ESCAPE);
	return (0);
}
