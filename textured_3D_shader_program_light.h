#pragma once

#include "shader_program.h"
#include "texture.h"
#include "scene.h"

#include <glm/mat4x4.hpp>

#include <vector>

class Mesh;
struct Configuration;

class Textured_3D_Shader_Program_Light : public Shader_Program
{
public:
	Textured_3D_Shader_Program_Light(const Shader* vertex_shader, const Shader* fragment_shader);
	~Textured_3D_Shader_Program_Light();

	void render(const Configuration* config, const Mesh* mesh, const Texture* texture, const glm::mat4 translation, const glm::mat4 rotation, const glm::mat4 scale, const glm::mat4 camera, const glm::mat4 projection) const;
};