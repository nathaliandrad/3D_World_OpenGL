#include "input.h"

#include <iostream>

#include <glfw3.h>

Input* input;

Input::Input(GLFWwindow* window)
{
	const auto on_key_pressed_callback = [](GLFWwindow*, int key, int, int action, int)
	{
		switch(action)
		{
		case GLFW_PRESS:
			switch(key)
			{
				case GLFW_KEY_ESCAPE:
					input->set_button_state(Button::QUIT, Button_State::PRESSED);
					break;
				case GLFW_KEY_W:
					input->set_button_state(Button::FORWARD, Button_State::PRESSED);
					break;
				case GLFW_KEY_A:
					input->set_button_state(Button::LEFT, Button_State::PRESSED);
					break;
				case GLFW_KEY_S:
					input->set_button_state(Button::BACKWARD, Button_State::PRESSED);
					break;
				case GLFW_KEY_D:
					input->set_button_state(Button::RIGHT, Button_State::PRESSED);
					break;
				case GLFW_KEY_O:
					input->set_button_state(Button::ORTHO, Button_State::PRESSED);
					break;
				case GLFW_KEY_P:
					input->set_button_state(Button::PERP, Button_State::PRESSED);
					break;
				case GLFW_KEY_UP:
					input->set_button_state(Button::ARROWUP, Button_State::PRESSED);
					break;
				case GLFW_KEY_DOWN:
					input->set_button_state(Button::ARROWDOWN, Button_State::PRESSED);
					break;
				case GLFW_KEY_LEFT:
					input->set_button_state(Button::ARROWLEFT, Button_State::PRESSED);
					break;
				case GLFW_KEY_RIGHT:
					input->set_button_state(Button::ARROWRIGHT, Button_State::PRESSED);
					break;
			}
			break;

		case GLFW_RELEASE:
			switch(key)
			{
				case GLFW_KEY_ESCAPE:
					input->set_button_state(Button::QUIT, Button_State::RELEASED);
					break;
				case GLFW_KEY_W:
					input->set_button_state(Button::FORWARD, Button_State::RELEASED);
					break;
				case GLFW_KEY_A:
					input->set_button_state(Button::LEFT, Button_State::RELEASED);
					break;
				case GLFW_KEY_S:
					input->set_button_state(Button::BACKWARD, Button_State::RELEASED);
					break;
				case GLFW_KEY_D:
					input->set_button_state(Button::RIGHT, Button_State::RELEASED);
					break;
				case GLFW_KEY_O:
					input->set_button_state(Button::ORTHO, Button_State::RELEASED);
					break;
				case GLFW_KEY_P:
					input->set_button_state(Button::PERP, Button_State::RELEASED);
					break;
				case GLFW_KEY_UP:
					input->set_button_state(Button::ARROWUP, Button_State::RELEASED);
					break;
				case GLFW_KEY_DOWN:
					input->set_button_state(Button::ARROWDOWN, Button_State::RELEASED);
					break;
				case GLFW_KEY_LEFT:
					input->set_button_state(Button::ARROWLEFT, Button_State::RELEASED);
					break;
				case GLFW_KEY_RIGHT:
					input->set_button_state(Button::ARROWRIGHT, Button_State::RELEASED);
					break;
			}
			break;

		}
	};
	glfwSetKeyCallback(window, on_key_pressed_callback);

	const auto on_cusor_moved_callback = [](GLFWwindow*, double x, double y)
	{
		input->set_cursor_position(x, y);
	};
	_cursor_x = 0.0;
	_cursor_y = 0.0;
	_previous_cursor_x = 0.0;
	_previous_cursor_y = 0.0;
	glfwSetCursorPosCallback(window, on_cusor_moved_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	input = this;

	
	

	
}
Input::~Input()
{
}

void Input::update(GLFWwindow* window)
{
	_previous_cursor_x = _cursor_x;
	_previous_cursor_y = _cursor_y;

	for(auto button : _button_state)
	{
		if(button.second == Button_State::PRESSED)
		{
			_button_state[button.first] = Button_State::DOWN;
		}
		else if(button.second == Button_State::RELEASED)
		{
			_button_state[button.first] = Button_State::UP;
		}
	}

	glfwPollEvents();

	if(glfwWindowShouldClose(window))
	{
		input->set_button_state(Button::QUIT, Button_State::PRESSED);
	}
}

bool Input::is_button_state(Button type, Button_State state) const
{
	if(_button_state.find(type) == _button_state.end())
	{
		if(state == Button_State::UP)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return _button_state.find(type)->second == state;
}

void Input::set_button_state(Button type, Button_State state)
{
	_button_state[type] = state;
}

void Input::set_cursor_position(double x, double y)
{
	if(_previous_cursor_x == 0.0 && _previous_cursor_y == 0.0)
	{
		_previous_cursor_x = x;
		_previous_cursor_y = y;
	}

	_cursor_x = x;
	_cursor_y = y;
}

std::pair<double, double> Input::cursor_position() const
{
	return {_cursor_x, _cursor_y};
}

std::pair<double, double> Input::previous_cursor_position() const
{
	return {_previous_cursor_x, _previous_cursor_y};
}