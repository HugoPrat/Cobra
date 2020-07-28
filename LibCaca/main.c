/*
** EPITECH PROJECT, 2018
** Cobra
** File description:
** main.c
*/

#include <caca.h>

int main(int ac, char **av)
{
	caca_display_t *dp = caca_create_display(NULL);
	caca_event_t ev;
	caca_canvas_t *cv = caca_get_canvas(dp);
	caca_canvas_t *err = caca_get_canvas(dp);
	uint8_t color[4] = {CACA_BLUE, CACA_RED, CACA_YELLOW, CACA_BLACK};
	int i = 0;
	int key = 0;

	if (!dp)
		return (84);
	while (key != CACA_KEY_ESCAPE) {
		if (i == 4)
			i = 0;
		caca_set_color_ansi(cv, CACA_WHITE, color[i]);
		caca_put_str(cv, 30, 15, "Bonsoir les amissss");
		caca_get_event(dp, CACA_EVENT_KEY_PRESS, &ev, 1);
		if ((key = ev.data.key.ch) != CACA_KEY_ESCAPE && key != 0) {
			caca_set_color_ansi(err, CACA_RED, CACA_BLACK);
			caca_printf(err, 24, 17, "You press %c instead of escape", key);
		}
		caca_refresh_display(dp);
		i++;
	}
	return (0);
}
