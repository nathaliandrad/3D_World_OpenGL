#include "cube_grey.h"
#include "assets.h"
#include "textured_3D_shader_program.h"
#include "textured_3D_shader_program_light.h"
#include "textured_3D_shader_grey_program.h"
#include "input.h"

#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtx/transform.hpp>

#define GLEW_STATIC
#include <glew.h>

#include <vector>
#include <math.h>

Cube_Grey::Cube_Grey(const char* id)
	: Game_Object(id)
{
	_scale *= 0.05;
}
Cube_Grey::~Cube_Grey()
{
}
void Cube_Grey::simulate_AI(const double seconds_to_simulate, const Assets*, const Scene*, const Configuration*, const Input* input)
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
void Cube_Grey::render(const double , const Assets* assets, const Scene* scene, const Configuration* config)
{
	const Textured_3D_Shader_Program_Light_Grey* program = (Textured_3D_Shader_Program_Light_Grey*)assets->get_asset("Shader_Program.3D.Textured_Light_Grey");
	const Mesh* mesh = (Mesh*)assets->get_asset("Mesh.Cube");
	const Texture* texture = (Texture*)assets->get_asset("Texture.Crate_With_Sides_Marked");
	program->render(config, mesh, texture, translation(), rotation(), scale(), camera(scene, config), projection(scene, config));
}