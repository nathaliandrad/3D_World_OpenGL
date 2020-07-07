#include "human_conqueror.h"
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

Human_Conqueror::Human_Conqueror(const char* id)
	: Game_Object(id)
{
	_scale *= 0.05;

}
Human_Conqueror::~Human_Conqueror()
{
}
void Human_Conqueror::simulate_AI(const double, const Assets*, const Scene*, const Configuration*, const Input*)
{
}
void Human_Conqueror::render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config)
{
	static double total_time = 0;
	total_time += seconds_to_simulate;

	_rotation.y += (float)seconds_to_simulate;
	const Textured_3D_Shader_Program_Light* program = (Textured_3D_Shader_Program_Light*)assets->get_asset("Shader_Program.3D.Textured_Light");
	const Mesh* mesh = (Mesh*)assets->get_asset("Mesh.Robot");
	const Texture* texture = (Texture*)assets->get_asset("Texture.Robot");
	program->render(config, mesh, texture, translation(), rotation(), scale(), camera(scene, config), projection(scene, config));
}