#include "textured_3D_shader_grey_program.h"
#include "mesh.h"
#include "expectations.h"
#include "configuration.h"


#include <glm/vec3.hpp>

Textured_3D_Shader_Program_Light_Grey::Textured_3D_Shader_Program_Light_Grey(const Shader* vertex_shader, const Shader* fragment_shader)
	: Shader_Program("Shader_Program.3D.Textured_Light_Grey", vertex_shader, fragment_shader)
{
}
Textured_3D_Shader_Program_Light_Grey::~Textured_3D_Shader_Program_Light_Grey()
{
}

void Textured_3D_Shader_Program_Light_Grey::render(const Configuration* config, const Mesh* mesh, const Texture* texture,
	const glm::mat4 translation, const glm::mat4 rotation, const glm::mat4 scale,
	const glm::mat4 camera, const glm::mat4 projection) const
{
	glUseProgram(program());
	glBindVertexArray(vao());

	GLuint vbo_index;
	glGenBuffers(1, &vbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh->verticies().size(), mesh->verticies().data(), GL_STATIC_DRAW);

	GLint vertex_location = glGetAttribLocation(program(), "vertex_position");
	expect(vertex_location != -1, "Failed to get vertex_location");
	glEnableVertexAttribArray(vertex_location);
	glVertexAttribPointer(vertex_location, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	GLint translation_location = glGetUniformLocation(program(), "translation");
	expect(translation_location != -1, "Failed to find translation location.");
	glUniformMatrix4fv(translation_location, 1, GL_FALSE, &(translation)[0][0]);

	GLint scale_location = glGetUniformLocation(program(), "scale");
	expect(scale_location != -1, "Failed to find scale location.");
	glUniformMatrix4fv(scale_location, 1, GL_FALSE, &(scale)[0][0]);

	GLint rotation_location = glGetUniformLocation(program(), "rotation");
	expect(rotation_location != -1, "Failed to find rotation location.");
	glUniformMatrix4fv(rotation_location, 1, GL_FALSE, &(rotation)[0][0]);

	GLint camera_location = glGetUniformLocation(program(), "camera");
	expect(camera_location != -1, "Failed to find camera location.");
	glUniformMatrix4fv(camera_location, 1, GL_FALSE, &(camera)[0][0]);

	GLint projection_location = glGetUniformLocation(program(), "projection");
	expect(projection_location != -1, "Failed to find projection location.");
	glUniformMatrix4fv(projection_location, 1, GL_FALSE, &(projection)[0][0]);

	GLuint tbo_index;
	glGenBuffers(1, &tbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, tbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh->texture_coordinates().size(), mesh->texture_coordinates().data(), GL_STATIC_DRAW);

	GLint vertex_texture_coordinate_location = glGetAttribLocation(program(), "vertex_texture_coordinate");
	expect(vertex_texture_coordinate_location != -1, "Failed to get vertex_texture_coordinate_location");
	glEnableVertexAttribArray(vertex_texture_coordinate_location);
	glVertexAttribPointer(vertex_texture_coordinate_location, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	GLuint texture_location;
	glGenTextures(1, &texture_location);

	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_2D, texture_location);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->width(), texture->height(),
		0, GL_RGB, GL_UNSIGNED_BYTE, texture->data());
	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	GLint image_location = glGetUniformLocation(program(), "image");
	expect(image_location != -1, "Failed to find image uniform location.");
	glUniform1i(image_location, 0);

	if (config->render_wireframe)
	{
		glDrawArrays(GL_LINE_LOOP, 0, GLsizei(mesh->verticies().size() / 2));
	}
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, GLsizei(mesh->verticies().size() / 2));
	}


	glDeleteBuffers(1, &vbo_index);
	glDeleteTextures(1, &texture_location);
}