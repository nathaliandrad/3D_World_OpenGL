#pragma once

#include "scene.h"
#include "game_object.h"

Scene::Scene(const char* id)
	: _id(id)
{
}

Scene::~Scene()
{
}

std::vector<Game_Object*> Scene::get_game_objects() const
{
	std::vector<Game_Object*> game_objects;

	for(auto key_value : _game_objects)
	{
		game_objects.push_back(key_value.second);
	}

	return game_objects;
}

Game_Object* Scene::get_game_object(const char* id) const
{
	if(_game_objects.find(id) == _game_objects.end())
	{
		std::cout << "Attempted to find a game object that does not exist. ID: " << id << std::endl;
		exit(1);
	}

	return _game_objects.find(id)->second;
}

const char* Scene::id() const
{
	return _id;
}

glm::vec3 Scene::camera_position() const
{
	return _camera_position;
}
glm::vec3 Scene::camera_forward() const
{
	return _camera_forward;
}
glm::vec3 Scene::camera_up() const
{
	return _camera_up;
}