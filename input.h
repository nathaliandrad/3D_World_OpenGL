#pragma once

#include <map>

struct GLFWwindow;

class Input
{
public:
	Input(GLFWwindow* window);
	~Input();

	enum class Button
	{
		QUIT,

		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT,
		ORTHO,
		PERP,

		ARROWUP,
		ARROWDOWN,
		ARROWLEFT,
		ARROWRIGHT
	};

	enum class Button_State
	{
		PRESSED,
		DOWN,
		RELEASED,
		UP
	};

	void update(GLFWwindow* window);

	void set_button_state(Button type, Button_State state);
	bool is_button_state(Button type, Button_State state) const;

	void set_cursor_position(double x, double y);
	std::pair<double, double> cursor_position() const;
	std::pair<double, double> previous_cursor_position() const;

private:
	std::map<Button, Button_State> _button_state;

	double _cursor_x;
	double _cursor_y;

	double _previous_cursor_x;
	double _previous_cursor_y;
};