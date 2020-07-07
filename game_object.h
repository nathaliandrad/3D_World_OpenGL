#pragma once

#include <string>
#include <iostream>

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/transform.hpp>

class Assets;
class Input;
struct Configuration;
class Scene;

class Game_Object
{
public:
	Game_Object(const char* id);
	~Game_Object();

	const char* id() const;

	virtual void simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config, const Input* input) = 0;
	virtual void simulate_physics(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config);
	virtual void render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) = 0;

	glm::mat4x4 translation()    const;
	glm::mat4x4 rotation()       const;
	glm::mat4x4 scale()          const;

	glm::mat4x4 camera(const Scene* scene, const Configuration* config) const;
	glm::mat4x4 projection(const Scene* scene, const Configuration* config) const;

	void translate(const glm::vec3 translation);



protected:
	const char* _id;

	glm::vec3 _translation = glm::vec3(0.f, 0.f, 0.f);
	glm::vec3 _rotation = glm::vec3(0.f, 0.f, 0.f);
	glm::vec3 _scale = glm::vec3(1.f, 1.f, 1.f);
};