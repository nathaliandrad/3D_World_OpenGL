#include "airplane.h"
#include "assets.h"
#include "textured_3D_shader_program.h"

#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtx/transform.hpp>

#define GLEW_STATIC
#include <glew.h>

#include <vector>
#include <math.h>

Airplane::Airplane(const char* id)
	: Game_Object(id)
{
	_scale.x = 0.2f;
	_scale.y = 0.2f;
	_scale.z = 0.2f;

	_translation.x += 0.25f;
	_translation.y -= 0.25f;
}
Airplane::~Airplane()
{
}
void Airplane::simulate_AI(const double, const Assets*, const Scene*, const Configuration*, const Input*)
{
}
void Airplane::render(const double, const Assets* assets, const Scene* scene, const Configuration* config)
{
	//_rotation.y += (float)seconds_to_simulate;

	const Textured_3D_Shader_Program* program = (Textured_3D_Shader_Program*)assets->get_asset("Shader_Program.3D.Textured");
	const Mesh* mesh = (Mesh*)assets->get_asset("Mesh.Square");
	const Texture* texture = (Texture*)assets->get_asset("Sprite.Airplane");

	glm::mat4 trans = transformation(scene, config);
	program->render(config, mesh, texture, &trans);
}