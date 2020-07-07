#include "blocky_boy.h"
#include "colored_3D_shader_program.h"
#include "assets.h"

#define GLEW_STATIC
#include <glew.h>

#include <vector>
#include <math.h>

Blocky_Boy::Blocky_Boy(const char* id)
	: Game_Object(id)
{
	_total_time = 0;

	_translation.x -= 0.25f;
	_translation.y -= 0.25f;

	_scale.x = 0.2f;
	_scale.y = 0.25f;
	_scale.z = 0.25f;
}
Blocky_Boy::~Blocky_Boy()
{
}


void Blocky_Boy::simulate_AI(const double, const Assets*, const Scene*, const Configuration*, const Input*)
{

}
void Blocky_Boy::render(const double s, const Assets* assets, const Scene* scene, const Configuration* config)
{
	static double time = 0;
	time -= s;

	_rotation.z = (float)time;

	std::vector<GLfloat> colors =
	{
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,

		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
	};

	const Colored_3D_Shader_Program* program = (Colored_3D_Shader_Program*)assets->get_asset("Shader_Program.3D.Colored");
	const Mesh* mesh = (Mesh*)assets->get_asset("Mesh.Square");

	glm::mat4 trans = transformation(scene, config);

	program->render(config, mesh, &colors, &trans);
}