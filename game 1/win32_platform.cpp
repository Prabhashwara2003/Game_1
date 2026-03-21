#include "windows.h"
#include "utility.cpp"
#include "platform_common.cpp"
#include "renderer.cpp"
#include "game.cpp"

#define process_button(b,vk)\
case (vk):{\
	input.buttons[b].is_down = is_down;\
	input.buttons[b].changed = true;\
}break;


bool running = true;
void* buffer_memory = nullptr;
int buffer_width = 0;
int buffer_height = 0;
static BITMAPINFO buffer_bitmap_info = {};

LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT result =0 ;

	switch (uMsg)
	{
		case WM_CLOSE:
		case WM_DESTROY: {
			running = false;
		}
		break;

		case WM_SIZE: {
			RECT rect;
			GetClientRect(hwnd, &rect);
			buffer_width = rect.right - rect.left;
			buffer_height = rect.bottom - rect.top;
			int buffer_size = buffer_width * buffer_height * sizeof(unsigned int);
			if (buffer_memory)
			{
				VirtualFree(buffer_memory, 0, MEM_RELEASE);
			}
				
			buffer_memory = VirtualAlloc(0,buffer_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

			buffer_bitmap_info.bmiHeader.biSize = sizeof(buffer_bitmap_info.bmiHeader);
			buffer_bitmap_info.bmiHeader.biWidth = buffer_width;
			buffer_bitmap_info.bmiHeader.biHeight = -buffer_height;
			buffer_bitmap_info.bmiHeader.biPlanes = 1;
			buffer_bitmap_info.bmiHeader.biBitCount = 32;
			buffer_bitmap_info.bmiHeader.biCompression = BI_RGB;


			break;
		}
	default:
		result = DefWindowProc(hwnd, uMsg, wParam, lParam);
	}


	return result;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS windowClass = {};
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpszClassName = L"Game1WindowClass";
	windowClass.lpfnWndProc = window_callback;

	RegisterClass(&windowClass);

	HWND window = CreateWindowExW(0, windowClass.lpszClassName, L"Game1", WS_OVERLAPPEDWINDOW | WS_VISIBLE,CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);

	HDC hdc = GetDC(window);

	Input input = {};


	while (running)
	{
		MSG massage;

		for (int i = 0; i < BUTTON_COUNT; i++)
		{
			input.buttons[i].changed = false;
		}

		while (PeekMessage(&massage,window,0,0,PM_REMOVE))
		{
			switch (massage.message)
			{
				case WM_KEYUP:
				case WM_KEYDOWN:
				{
					u32 vk_code = (u32)massage.wParam;
					bool is_down = ((massage.lParam & (1 << 31)) == 0);

					switch (vk_code) {
						process_button(BUTTON_UP, VK_UP);
						process_button(BUTTON_DOWN, VK_DOWN);
						process_button(BUTTON_LEFT, VK_LEFT);
						process_button(BUTTON_RIGHT, VK_RIGHT);
					
					
					default: {}
						break;
					}

				}
				break;


				default: {
					TranslateMessage(&massage);
					DispatchMessageW(&massage);
				}
			}
		}

		render_background( buffer_width , buffer_height, buffer_memory);

		simulate_game(&input, buffer_width, buffer_height, buffer_memory);

		StretchDIBits(hdc, 0, 0, buffer_width, buffer_height, 0, 0, buffer_width, buffer_height, buffer_memory, &buffer_bitmap_info, DIB_RGB_COLORS, SRCCOPY);

	}

    return 0;
}
