#include "game_scene.h"
#include "pointy_head.h"
#include "blocky_boy.h"
#include "airplane.h"
#include "crazy_crate.h"
#include "robot.h"
#include "input.h"
#include "human_conqueror.h"
#include "configuration.h"
#include "pyramid.h"
#include "cube_modified.h"
#include "unique_obj.h"
#include "cube_grey.h"

Game_Scene::Game_Scene()
	: Scene("Game")
{
	Crazy_Crate* crazy_crate = new Crazy_Crate("Game_Object.Crate");
	_game_objects[crazy_crate->id()] = crazy_crate;

}

Game_Scene::~Game_Scene()
{

}

void Game_Scene::update(const double seconds_to_simulate, Input* input, Configuration* config )
{
	
	if (count == 1) {
		Human_Conqueror* human_conqueror = new Human_Conqueror("Game_Object.Human_Conqueror");
		_game_objects[human_conqueror->id()] = human_conqueror;
		human_conqueror->translate(glm::vec3(0.5, 0.2, 0));

		Human_Conqueror* human_conqueror2 = new Human_Conqueror("Game_Object.Human_Conqueror2");
		_game_objects[human_conqueror2->id()] = human_conqueror2;
		human_conqueror2->translate(glm::vec3(-0.5, 0.2, 0));

		Human_Conqueror* human_conqueror3 = new Human_Conqueror("Game_Object.Human_Conqueror3");
		_game_objects[human_conqueror3->id()] = human_conqueror3;
		human_conqueror3->translate(glm::vec3(0.5, -0.2, 0));

		Human_Conqueror* human_conqueror4 = new Human_Conqueror("Game_Object.Human_Conqueror4");
		_game_objects[human_conqueror4->id()] = human_conqueror4;
		human_conqueror4->translate(glm::vec3(-0.5, -0.2, 0));
	}
	glm::vec3 pos; pos.x = 0; pos.y = 0; pos.z = -1;
	if (_camera_position.z <0 &&  _camera_position.z > -0.1) {
		Pyramid* pyramid = new Pyramid("Game_Object.Pyramid");
		_game_objects[pyramid->id()] = pyramid;
		pyramid->translate(pos);
	}
	glm::vec3 pos2; pos2.x = 0; pos2.y = 0; pos2.z = -2.5;
	if (_camera_position.z <-1 && _camera_position.z > -1.05) {
		Robot* robot = new Robot("Game_Object.Robot2");
		_game_objects[robot->id()] = robot;
		robot->translate(pos2);
	}
	glm::vec3 pos3; pos3.x = 0; pos3.y = 0; pos3.z = -3.5;
	if (_camera_position.z <-2.5 && _camera_position.z > -2.6) {
		Cube_Modified* cube_modified = new Cube_Modified("Game_Object.Cube_Modified");
		_game_objects[cube_modified->id()] = cube_modified;
		cube_modified->translate(pos3);
	}
	glm::vec3 pos4; pos4.x = 0; pos4.y = 0; pos4.z = -4.5;
	if (_camera_position.z <-3.5 && _camera_position.z > -3.6) {
		Unique_Object* unique_obj = new Unique_Object("Game_Object.Unique");
		_game_objects[unique_obj->id()] = unique_obj;
		unique_obj->translate(pos4);
	}
	glm::vec3 pos5; pos5.x = 0; pos5.y = 0; pos5.z = -5.5;
	if (_camera_position.z <-4.5 && _camera_position.z > -4.6) {
		Cube_Grey* cube_grey = new Cube_Grey("Game_Object.Cube_Grey");
		_game_objects[cube_grey->id()] = cube_grey;
		cube_grey->translate(pos5);
	}
	if(input->is_button_state(Input::Button::FORWARD, Input::Button_State::DOWN))
	{
		_camera_position += _camera_forward * (float)seconds_to_simulate;

	}
	if(input->is_button_state(Input::Button::BACKWARD, Input::Button_State::DOWN))
	{
		_camera_position -= _camera_forward * (float)seconds_to_simulate;
	}
	if(input->is_button_state(Input::Button::RIGHT, Input::Button_State::DOWN))
	{
		glm::vec3 right = glm::cross(_camera_forward, _camera_up);
		_camera_position += right * (float)seconds_to_simulate;
	}
	if(input->is_button_state(Input::Button::LEFT, Input::Button_State::DOWN))
	{
		glm::vec3 right = glm::cross(_camera_forward, _camera_up);
		_camera_position -= right * (float)seconds_to_simulate;
		
	}
	if (input->is_button_state(Input::Button::PERP, Input::Button_State::DOWN)) 
	{
		config->projection = Configuration::Projection::Perspective;
		count++;
	}
	if (input->is_button_state(Input::Button::ORTHO, Input::Button_State::DOWN))
	{
		config->projection = Configuration::Projection::Orthographic;
	}
	const double mouse_movement_x = input->cursor_position().first - input->previous_cursor_position().first;
	const double mouse_movement_y = input->cursor_position().second - input->previous_cursor_position().second;

	_camera_yaw   += (float)mouse_movement_x * _camera_sensitivity;
	_camera_pitch -= (float)mouse_movement_y * _camera_sensitivity;

	if(_camera_pitch > 89.0f) _camera_pitch = 89.0f;
	if(_camera_pitch < -89.0f) _camera_pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(_camera_yaw)) * cos(glm::radians(_camera_pitch));
	direction.y = sin(glm::radians(_camera_pitch));
	direction.z = sin(glm::radians(_camera_yaw)) * cos(glm::radians(_camera_pitch));
	_camera_forward = glm::normalize(direction);
}