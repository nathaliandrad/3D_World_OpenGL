#pragma once

#include <map>
#include <string>
#include <vector>
#include "configuration.h"

#include <glm/vec3.hpp>

class Game_Object;
class Input;

class Scene
{
public:
	Scene(const char* id);
	~Scene();

	virtual void update(const double seconds_to_simulate, Input* input, Configuration* config) = 0;

	Game_Object* get_game_object(const char* id) const;
	std::vector<Game_Object*> get_game_objects() const;

	const char* id() const;

	glm::vec3 camera_position() const;
	glm::vec3 camera_forward() const;
	glm::vec3 camera_up() const;
	int count = 0;

protected:
	std::map<std::string, Game_Object*> _game_objects;
	const char*                         _id;

	float     _camera_sensitivity = 0.25f;
	float     _camera_yaw         = -90.0f;
	float     _camera_pitch       = 0.0f;
	glm::vec3 _camera_position    = glm::vec3(0.f, 0.f, 1.f);
	glm::vec3 _camera_forward     = glm::vec3(0.f, 0.f, -1.f);
	glm::vec3 _camera_up          = glm::vec3(0.f, 1.f, 0.f);
};