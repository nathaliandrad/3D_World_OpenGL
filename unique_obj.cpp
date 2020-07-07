#include "unique_obj.h"
#include "assets.h"
#include "textured_3D_shader_program.h"
#include "textured_3D_shader_program_light.h"
#include "colored_3D_shader_program.h"
#include "textured_3D_shader_program_color.h"
#include "input.h"

#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtx/transform.hpp>

#define GLEW_STATIC
#include <glew.h>

#include <vector>
#include <math.h>

Unique_Object::Unique_Object(const char* id)
	: Game_Object(id)
{
	_scale *= 0.05;
}
Unique_Object::~Unique_Object()
{
}
void Unique_Object::simulate_AI(const double seconds_to_simulate, const Assets*, const Scene*, const Configuration*, const Input* input)
{
	const float speed = 1.f;

	if (input->is_button_state(Input::Button::ARROWDOWN, Input::Button_State::DOWN)) {
		_rotation.y -= (float)seconds_to_simulate * speed;

	}
	if (input->is_button_state(Input::Button::ARROWLEFT, Input::Button_State::DOWN)) {
		_rotation.x -= (float)seconds_to_simulate * speed;
	}
	if (input->is_button_state(Input::Button::ARROWRIGHT, Input::Button_State::DOWN)) {
		_rotation.x += (float)seconds_to_simulate * speed;
	}
	if (input->is_button_state(Input::Button::ARROWUP, Input::Button_State::DOWN)) {
		_rotation.y += (float)seconds_to_simulate * speed;
	}
}
void Unique_Object::render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config)
{
	static double total_time = 0;
	total_time += seconds_to_simulate;
	const Textured_3D_Shader_Program_Light* program = (Textured_3D_Shader_Program_Light*)assets->get_asset("Shader_Program.3D.Textured_Light");
	const Mesh* mesh = (Mesh*)assets->get_asset("Mesh.Unique_Obj");
	const Texture* texture = (Texture*)assets->get_asset("Textured.Unique.Obj");

	program->render(config, mesh, texture, translation(), rotation(), scale(), camera(scene, config), projection(scene, config));
}