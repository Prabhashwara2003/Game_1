struct button_state {
	bool is_down;
	bool changed;
};
enum 
{
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_W,
	BUTTON_S,

	BUTTON_COUNT,
};

struct Input {
	button_state buttons[BUTTON_COUNT];
};