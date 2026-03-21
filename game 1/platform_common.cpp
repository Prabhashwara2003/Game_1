struct button_state {
	bool is_down;
	bool changed;
};
enum 
{
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_LEFT,
	BUTTON_RIGHT,

	BUTTON_COUNT,
};

struct Input {
	button_state buttons[BUTTON_COUNT];
};