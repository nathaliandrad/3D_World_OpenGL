#include "crazy_crate.h"
#include "colored_3D_shader_program.h"
#include "textured_3D_shader_program.h"
#include "textured_3D_shader_program_light.h"
#include "assets.h"
#include "mesh.h"
#include "input.h"

#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtx/transform.hpp>

#define GLEW_STATIC
#include <glew.h>

#include <vector>
#include <math.h>

Crazy_Crate::Crazy_Crate(const char* id)
	: Game_Object(id)
{
	_scale.x = 0.3f;
	_scale.y = 0.3f;
	_scale.z = 0.3f;
}
Crazy_Crate::~Crazy_Crate()
{
}


void Crazy_Crate::simulate_AI(const double time_to_simulate_s, const Assets*, const Scene*, const Configuration*, const Input*)
{
	static double total_time = 0;
	total_time += time_to_simulate_s;

	_rotation.x += (float)time_to_simulate_s / 4;
}
void Crazy_Crate::render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config)
{
	static double total_time = 0;
	total_time += seconds_to_simulate;
	const Mesh* mesh = (Mesh*)assets->get_asset("Mesh.Cube");

	const Textured_3D_Shader_Program* program = (Textured_3D_Shader_Program*)assets->get_asset("Shader_Program.3D.Textured");
	//const Texture* texture = (Texture*)assets->get_asset("Texture.Crate_With_Sides_Marked"); Texture.Cube_With_Instructions
	const Texture* texture = (Texture*)assets->get_asset("Texture.Cube_With_Instructions");
	program->render(config, mesh, texture, translation(), rotation(), scale(), camera(scene, config), projection(scene, config));
}