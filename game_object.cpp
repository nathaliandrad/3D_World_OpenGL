#pragma once

#include "game_object.h"
#include "scene.h"
#include "configuration.h"


#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/transform.hpp>

Game_Object::Game_Object(const char* id)
	: _id(id)
{
}
Game_Object::~Game_Object()
{
}

const char* Game_Object::id() const
{
	return _id;
}

void Game_Object::simulate_physics(const double, const Assets*, const Scene*, const Configuration*)
{
}

glm::mat4x4 Game_Object::translation() const
{
	return glm::translate(glm::mat4(1.0f), _translation);
}
glm::mat4x4 Game_Object::rotation() const
{
	glm::mat4 rotation_x = glm::rotate(_rotation.x, glm::vec3(1.f, 0.f, 0.f));
	glm::mat4 rotation_y = glm::rotate(_rotation.y, glm::vec3(0.f, 1.f, 0.f));
	glm::mat4 rotation_z = glm::rotate(_rotation.z, glm::vec3(0.f, 0.f, 1.f));
	return rotation_x * rotation_y * rotation_z;
}
glm::mat4x4 Game_Object::scale() const
{
	return glm::scale(glm::mat4(1.0f), _scale);
}

void Game_Object::translate(const glm::vec3 translation)
{
	_translation += translation;
}



glm::mat4x4 Game_Object::camera(const Scene* scene, const Configuration*) const
{
	glm::vec3 camera_position = scene->camera_position();
	glm::vec3 camera_forward = scene->camera_forward();
	glm::vec3 camera_up = scene->camera_up();

	__pragma(warning(push))
	__pragma(warning(disable:4127))
	return glm::lookAt(camera_position, camera_position + camera_forward, camera_up);
	__pragma(warning(pop))
}

glm::mat4x4 Game_Object::projection(const Scene*, const Configuration* config) const
{
	const float aspect_ratio = float(config->screen_width) / config->screen_height;
	const float x_units      = aspect_ratio * config->y_units;
	const float y_units      = float(config->y_units);

	if(config->projection == Configuration::Projection::Orthographic)
	{
		return glm::ortho(-x_units / 2, x_units / 2, -y_units / 2, y_units / 2,
			0.1f, float(config->z_units));
	}
	else if(config->projection == Configuration::Projection::Perspective)
	{
		
		return glm::perspectiveFov(
			glm::radians(config->fov), 
			(float)config->screen_width,
			(float)config->screen_height,
			0.00001f, 
			(float)config->z_units);
			
	}




	else
	{
		throw new std::exception("Unhandled projection type");
	}
}