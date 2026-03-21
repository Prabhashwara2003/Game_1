#define pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define hold(b) (input->buttons[b].is_down)
#define release(b) (!input-buttons[b].is_down && input ->buttons[b].changed)


int t = 0;
int k = 0;

inline void simulate_game(Input* input , int buffer_width, int buffer_height, void* buffer_memory)
{
	


	clear_screen(buffer_width, buffer_height, buffer_memory, 0x0000293);

	if (pressed(BUTTON_UP))
		t = t - 10;
	if (pressed(BUTTON_DOWN))
		t = t + 10;
	if (pressed(BUTTON_LEFT))
		k = k - 10;
	if (pressed(BUTTON_RIGHT))
		k = k + 10;

	draw_rect(buffer_width, buffer_height, buffer_memory, k, t, 1, 1, 0x0000FF00);
}