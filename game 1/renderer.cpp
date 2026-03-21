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

void draw_rect(int buffer_width, int buffer_height, void* buffer_memory, int x, int y, int width, int height, unsigned int color)
{
	unsigned int* pixel = (unsigned int*)buffer_memory;
	height =height*buffer_height*0.2;
	width = width*buffer_width*0.2;
	for (int j = y; j < y+height; j++)
	{
		for (int i = x; i <x+width; i++)
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
