#include "cube_modified.h"
#include "assets.h"
#include "textured_3D_shader_program.h"
#include "textured_3D_shader_program_light.h"

#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtx/transform.hpp>

#define GLEW_STATIC
#include <glew.h>

#include <vector>
#include <math.h>

Cube_Modified::Cube_Modified(const char* id)
	: Game_Object(id)
{
	_scale *= 0.05;
}
Cube_Modified::~Cube_Modified()
{
}
void Cube_Modified::simulate_AI(const double, const Assets*, const Scene*, const Configuration*, const Input*)
{
}
void Cube_Modified::render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config)
{
	static double total_time = 0;
	total_time += seconds_to_simulate;
	_rotation.y += (float)seconds_to_simulate;
	const Textured_3D_Shader_Program_Light* program = (Textured_3D_Shader_Program_Light*)assets->get_asset("Shader_Program.3D.Textured_Light");
	const Mesh* mesh = (Mesh*)assets->get_asset("Mesh.Cube_Modified");
	const Texture* texture = (Texture*)assets->get_asset("Textured.Cube.Modified");

	program->render(config, mesh, texture, translation(), rotation(), scale(), camera(scene, config), projection(scene, config));
}