void render_background(int buffer_width, int buffer_height ,void* buffer_memory)
{
	unsigned int* pixel = (unsigned int*)buffer_memory;
	for (int y = 0; y < buffer_height; y++)
	{
		for (int x = 0; x < buffer_width; x++)
		{
			*pixel++ = 0x00FF0000 + y * x;
		}
	}
}
void clear_screen(int buffer_width, int buffer_height, void* buffer_memory ,unsigned int color)
{
	unsigned int* pixel = (unsigned int*)buffer_memory;
	for (int y = 0; y < buffer_height; y++)
	{
		for (int x = 0; x < buffer_width; x++)
		{
			*pixel++ = color;
		}
	}
}
/*void draw_rect_in_pixel(int buffer_width, int buffer_height, void* buffer_memory, int x, int y, int width, int height, unsigned int color, int x0, int x1, int y0, int y1)
{

	x0 = clamp(0, x0, buffer_width);
	x1 = clamp(0, x1, buffer_width);
	y0 = clamp(0, y0, buffer_height);
	y1 = clamp(0, y1, buffer_height);

	unsigned int* pixel = (unsigned int*)buffer_memory;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			int pixel_x = x + i;
			int pixel_y = y + j;
			if (pixel_x >= 0 && pixel_x < buffer_width && pixel_y >= 0 && pixel_y < buffer_height)
			{
				pixel[pixel_y * buffer_width + pixel_x] = color;
			}
		}
	}
}
void draw_rect(int buffer_width, int buffer_height, void* buffer_memory, int x, int y, int width, int height, unsigned int color)
{
	int x0 = x;
	int x1 = x + width;
	int y0 = y;
	int y1 = y + height;


	draw_rect_in_pixel(buffer_width, buffer_height, buffer_memory, x, y, width, height, color ,x,x+width,y,y+height);
}*/

/*void draw_rect(int buffer_width, int buffer_height, void* buffer_memory, float x, float y, float width, float height, unsigned int color)
{

	unsigned int* pixel = (unsigned int*)buffer_memory;
	height =y + height*buffer_height*0.2;
	width = x + width*buffer_width*0.1;
	for (int j = y; j < height; j++)
	{
		for (int i = x; i <width; i++)
		{
			int pixel_x = x + i;
			int pixel_y = y + j;
			if (pixel_x >= 0 && pixel_x < buffer_width && pixel_y >= 0 && pixel_y < buffer_height)
			{
				pixel[pixel_y * buffer_width + pixel_x] = color;
			}
		}
	}
}*/

void draw_rect(int buffer_width, int buffer_height, void* buffer_memory,
	int x, int y, int width, int height, unsigned int color)
{
	unsigned int* pixel = (unsigned int*)buffer_memory;

	int x0 = x;
	int y0 = y;
	int x1 = x + width;
	int y1 = y + height;

	if (x0 < 0) x0 = 0;
	if (y0 < 0) y0 = 0;
	if (x1 > buffer_width) x1 = buffer_width;
	if (y1 > buffer_height) y1 = buffer_height;

	for (int j = y0; j < y1; j++)
	{
		for (int i = x0; i < x1; i++)
		{
			pixel[j * buffer_width + i] = color;
		}
	}
}

void draw_score(int buffer_width, int buffer_height, void* buffer_memory,
	int player_2_score)
{
	switch (player_2_score)
	{
	case 0: {
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 10, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 10, 5, 45, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1205, 50, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1220, 10, 5, 40, 0x00FFFFFF);
		break;
	}
	case 1: {
		draw_rect(buffer_width, buffer_height, buffer_memory, 1220, 10, 5, 40, 0x00FFFFFF);
		break;
	}
	case 2: {
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 10, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 25, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 25, 5, 22, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1205, 42, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1220, 10, 5, 20, 0x00FFFFFF);
		break;
	}
	case 3: {
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 10, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 28, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 45, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1220, 10, 5, 40, 0x00FFFFFF);
		break;
	}
	case 4: {
		//draw_rect(buffer_width, buffer_height, buffer_memory, 400, 10, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1215, 10, 5, 20, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 10, 5, 20, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 25, 20, 5, 0x00FFFFFF);
		//draw_rect(buffer_width, buffer_height, buffer_memory, 400, 25, 5, 20, 0x00FFFFFF);
		//draw_rect(buffer_width, buffer_height, buffer_memory, 400, 45, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1215, 25, 5, 20, 0x00FFFFFF);
		break;
	}
	case 5: {
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 10, 20, 5, 0x00FFFFFF);
		//draw_rect(buffer_width, buffer_height, buffer_memory, 415, 10, 5, 20, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 10, 5, 20, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 25, 20, 5, 0x00FFFFFF);
		//draw_rect(buffer_width, buffer_height, buffer_memory, 400, 25, 5, 20, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 45, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1215, 25, 5, 20, 0x00FFFFFF);
		break;
	}
	case 6: {
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 10, 20, 5, 0x00FFFFFF);
		//draw_rect(buffer_width, buffer_height, buffer_memory, 415, 10, 5, 20, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 10, 5, 20, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 25, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 25, 5, 20, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 45, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1215, 25, 5, 20, 0x00FFFFFF);
		break;
	}
	case 7: {
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 10, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1215, 10, 5, 20, 0x00FFFFFF);
		//draw_rect(buffer_width, buffer_height, buffer_memory, 400, 10, 5, 20, 0x00FFFFFF);
		//draw_rect(buffer_width, buffer_height, buffer_memory, 400, 25, 20, 5, 0x00FFFFFF);
		//draw_rect(buffer_width, buffer_height, buffer_memory, 400, 25, 5, 20, 0x00FFFFFF);
		//draw_rect(buffer_width, buffer_height, buffer_memory, 400, 45, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1215, 25, 5, 20, 0x00FFFFFF);
		break;
	}
	case 8: {
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 10, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1215, 10, 5, 20, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 10, 5, 20, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 25, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 25, 5, 20, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 45, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1215, 25, 5, 20, 0x00FFFFFF);
		break;
	}
	case 9: {
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 10, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1215, 10, 5, 20, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 10, 5, 20, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 25, 20, 5, 0x00FFFFFF);
		//draw_rect(buffer_width, buffer_height, buffer_memory, 400, 25, 5, 20, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1200, 45, 20, 5, 0x00FFFFFF);
		draw_rect(buffer_width, buffer_height, buffer_memory, 1215, 25, 5, 20, 0x00FFFFFF);
		break;
	}

	default:
		break;
	}
}