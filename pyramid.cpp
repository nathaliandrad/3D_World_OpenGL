#include "pyramid.h"
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

Pyramid::Pyramid(const char* id)
	: Game_Object(id)
{
	_scale.x = 0.2f;
	_scale.y = 0.2f;
	_scale.z = 0.2f;
}
Pyramid::~Pyramid()
{
}


void Pyramid::simulate_AI(const double , const Assets*, const Scene*, const Configuration*, const Input* )
{

}
void Pyramid::render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config)
{
	static double total_time = 0;
	total_time += seconds_to_simulate;

	_rotation.y = (float)total_time / 2;
	_rotation.z = 0.1f;

	const Mesh* mesh = (Mesh*)assets->get_asset("Mesh.Pyramid");
	//glm::mat4 trans = transformation(scene, config);

	const Textured_3D_Shader_Program_Light* program = (Textured_3D_Shader_Program_Light*)assets->get_asset("Shader_Program.3D.Textured_Light");
	const Texture* texture = (Texture*)assets->get_asset("Texture.Crazy.Pyramid_Texture");
	//program->render(config, mesh, texture, &trans);
	program->render(config, mesh, texture, translation(), rotation(), scale(), camera(scene, config), projection(scene, config));
}