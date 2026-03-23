#define pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define hold(b) (input->buttons[b].is_down)
#define release(b) (!input-buttons[b].is_down && input ->buttons[b].changed)


int player_p_1   ,player_dp_1;
int player_p_2  , player_dp_2;
int player_height ;
int player_width ;
int ball_p_x = 250, ball_p_y = 250;
int ball_dp_x = 1000;
int ball_dp_y = 1000;
int player_1_score = 0;
int player_2_score = 0;


inline void simulate_game(Input* input, int buffer_width, int buffer_height, void* buffer_memory, float dt)
{
	player_height = buffer_height * 0.4;
	player_width = buffer_width * 0.01;

	clear_screen(buffer_width, buffer_height, buffer_memory, 0x0000FF00);

	//Arena
	int arena_height = buffer_height - 15;
	int arena_width = buffer_width - 15;
	int arena_p_x = 7;
	int arena_p_y = 7;

	draw_rect(buffer_width, buffer_height, buffer_memory, arena_p_x, arena_p_y, arena_width, arena_height, 0x0000293);

	//player 1
	float player_ddp_1 = 0.f;
	int player_1_x = arena_p_x + arena_width - 15;

	/*if (hold(BUTTON_UP))
		player_ddp_1 -= 3500;
	if (hold(BUTTON_DOWN))
		player_ddp_1 += 3500;
	*/

	if (ball_p_y < player_p_1 + player_height / 2)
		player_ddp_1 -= 1000;
	else if (ball_p_y > player_p_1 + player_height / 2)
		player_ddp_1 += 1000;


	player_ddp_1 -= player_dp_1 * 2.f;
	player_dp_1 = player_dp_1 + player_ddp_1 * dt;
	player_p_1 = (int)(player_p_1 + player_dp_1 * dt + player_ddp_1 * dt * dt * 0.5f);

	if (player_p_1 < arena_p_y) {
		player_p_1 = arena_p_y;
		player_ddp_1 = 0;
	}
	else if (player_p_1 + player_height > arena_p_y + arena_height) {
		player_p_1 = arena_p_y + arena_height - player_height;
		player_ddp_1 = 0;
	}

	draw_rect(buffer_width, buffer_height, buffer_memory, player_1_x, player_p_1, player_width, player_height, 0x00FAFA00);

	//player 2
	float player_ddp_2 = 0.f;
	float player_2_x = arena_p_x + 7;

	if (hold(BUTTON_W))
		player_ddp_2 -= 3500;
	if (hold(BUTTON_S))
		player_ddp_2 += 3500;

	player_ddp_2 -= player_dp_2 * 2.f;
	player_dp_2 = player_dp_2 + player_ddp_2 * dt;
	player_p_2 = player_p_2 + player_dp_2 * dt + player_ddp_2 * dt * dt * 0.5f;

	if (player_p_2 < arena_p_y) {
		player_p_2 = arena_p_y;
		player_ddp_2 = 0;
	}
	else if (player_p_2 + player_height > arena_p_y + arena_height) {
		player_p_2 = arena_p_y + arena_height - player_height;
		player_ddp_2 = 0;
	}

	draw_rect(buffer_width, buffer_height, buffer_memory, player_2_x, player_p_2, player_width, player_height, 0x00FAFA00);

	//ball

	ball_p_x += (int)(ball_dp_x * dt);
	ball_p_y += (int)(ball_dp_y * dt);

	if (ball_p_y < arena_p_y) {
		ball_p_y = arena_p_y;
		ball_dp_y = -ball_dp_y;
	}
	else if (ball_p_y + 10 > arena_p_y + arena_height) {
		ball_p_y = arena_p_y + arena_height - 10;
		ball_dp_y = -ball_dp_y;
	}

	if (ball_p_x < player_2_x + player_width + 1 && ball_p_x + 10 > player_2_x && ball_p_y > player_p_2 && ball_p_y < player_p_2 + player_height) {
		ball_p_x = player_2_x + player_width;
		ball_dp_x = -ball_dp_x;
		ball_dp_y = player_dp_2 * 0.75f;
	}
	else if (ball_p_x + 11 > player_1_x && ball_p_x < player_1_x + player_width && ball_p_y > player_p_1 && ball_p_y < player_p_1 + player_height) {
		ball_p_x = player_1_x - 10;
		ball_dp_x = -ball_dp_x;
		ball_dp_y = player_dp_1 * 0.75f;
	}

	if (ball_p_x < arena_p_x) {
		ball_p_x = arena_p_x + arena_width / 2;
		ball_p_y = arena_p_y + arena_height / 2;
		ball_dp_x = -ball_dp_x;
		player_2_score++;
	}
	else if (ball_p_x + 10 > arena_p_x + arena_width)
	{
		ball_p_x = arena_p_x + arena_width / 2;
		ball_p_y = arena_p_y + arena_height / 2;
		ball_dp_x = -ball_dp_x;
		player_1_score++;
	}
	draw_score(buffer_width, buffer_height, buffer_memory, player_2_score);
	draw_rect(buffer_width, buffer_height, buffer_memory, ball_p_x, ball_p_y, 10, 10, 0x00FA2000);
	

}
