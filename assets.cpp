#include "assets.h"
#include "shader.h"
#include "shader_program.h"
#include "triangle_mesh.h"
#include "square_mesh.h"
#include "texture.h"
#include "colored_3D_shader_program.h"
#include "textured_3D_shader_program.h"
#include "textured_3D_shader_program_light.h"
#include "textured_3D_shader_program_color.h"
#include "textured_3D_shader_grey_program.h"
#include "cube_mesh.h"
#include "obj_file_mesh.h"
#include "pyramid_mesh.h"
#include "unique_obj.h"

#define GLEW_STATIC
#include <glew.h>

#include <iostream>

Assets::Assets()
{
	Triangle_Mesh* traingle_mesh = new Triangle_Mesh();
	_assets.insert({traingle_mesh->id(), traingle_mesh});

	Square_Mesh* square_mesh = new Square_Mesh();
	_assets.insert({square_mesh->id(), square_mesh});

	Texture* airplane_sprite = new Texture("Sprite.Airplane", "Assets/sprite.airplane.png");
	_assets.insert({airplane_sprite->id(), airplane_sprite});

	Texture* airplane_background_mask = new Texture("Mask.Airplane_Background", "Assets/mask.airplane_background.png");
	_assets.insert({airplane_background_mask->id(), airplane_background_mask});

	Texture* airplane_mask = new Texture("Mask.Airplane", "Assets/mask.airplane.png");
	_assets.insert({airplane_mask->id(), airplane_mask});

	Texture* polygons_mask = new Texture("Mask.Polygons", "Assets/mask.polygons.png");
	_assets.insert({polygons_mask->id(), polygons_mask});


	Shader* colored_3D_vertex_shader = new Shader("Shader.Colored.3D.Vertex", "Shaders/colored.3D.vertex_shader.glsl", Shader::Type::Vertex);
	_assets.insert({colored_3D_vertex_shader->id(), colored_3D_vertex_shader});

	Shader* colored_3D_fragment_shader = new Shader("Shader.Colored.3D.Fragment", "Shaders/colored.3D.fragment_shader.glsl", Shader::Type::Fragment);
	_assets.insert({colored_3D_fragment_shader->id(), colored_3D_fragment_shader});

	Colored_3D_Shader_Program* colored_3D_program = new Colored_3D_Shader_Program(colored_3D_vertex_shader, colored_3D_fragment_shader);
	_assets.insert({colored_3D_program->id(), colored_3D_program});

	Cube_Mesh* cube_mesh = new Cube_Mesh();
	_assets.insert({cube_mesh->id(), cube_mesh});

	Shader* textured_3D_vertex_shader = new Shader("Shader.Textured.3D.Vertex", "Shaders/textured.3D.vertex_shader.glsl", Shader::Type::Vertex);
	_assets.insert({textured_3D_vertex_shader->id(), textured_3D_vertex_shader});

	Shader* textured_3D_fragment_shader = new Shader("Shader.Textured.3D.Fragment", "Shaders/textured.3D.fragment_shader.glsl", Shader::Type::Fragment);
	_assets.insert({textured_3D_fragment_shader->id(), textured_3D_fragment_shader});

	Textured_3D_Shader_Program* textured_3D_program = new Textured_3D_Shader_Program(textured_3D_vertex_shader, textured_3D_fragment_shader);
	_assets.insert({textured_3D_program->id(), textured_3D_program});

	Shader* textured_3D_vertex_shader_light = new Shader("Shader.Textured.3D.Vertex.Light", "Shaders/textured_3D.vertex_shader_light.glsl", Shader::Type::Vertex);
	_assets.insert({ textured_3D_vertex_shader_light->id(),textured_3D_vertex_shader_light });

	Shader* textured_3D_fragment_shader_light = new Shader("Shader.Textured.3D.Fragment.Light", "Shaders/textured.3D.fragment_shader_light.glsl", Shader::Type::Fragment);
	_assets.insert({ textured_3D_fragment_shader_light->id(), textured_3D_fragment_shader_light });

	Shader* textured_3D_fragment_shader_light_grey = new Shader("Shader.Textured.3D.Fragment.Light.Grey", "Shaders/texture.3D.fragment_shader_grey_light.glsl", Shader::Type::Fragment);
	_assets.insert({ textured_3D_fragment_shader_light_grey->id(), textured_3D_fragment_shader_light_grey });

	Textured_3D_Shader_Program_Light* textured_3D_program_light = new Textured_3D_Shader_Program_Light(textured_3D_vertex_shader_light, textured_3D_fragment_shader_light);
	_assets.insert({ textured_3D_program_light->id(), textured_3D_program_light });

	Textured_3D_Shader_Program_Light_Grey* textured_3D_program_light_grey = new Textured_3D_Shader_Program_Light_Grey(textured_3D_vertex_shader_light, textured_3D_fragment_shader_light_grey);
	_assets.insert({ textured_3D_program_light_grey->id(), textured_3D_program_light_grey });

	Shader* textured_3D_vertex_shader_color = new Shader("Shader.Textured.3D.Vertex.Color", "Shaders/textured.3D.vertex_shader_color.glsl", Shader::Type::Vertex);
	_assets.insert({ textured_3D_vertex_shader_color->id(),textured_3D_vertex_shader_color });

	Shader* textured_3D_fragment_shader_color = new Shader("Shader.Textured.3D.Fragment.Color", "Shaders/textured.3D.fragment_shader_color.glsl", Shader::Type::Fragment);
	_assets.insert({ textured_3D_fragment_shader_color->id(), textured_3D_fragment_shader_color });

	Textured_3D_Shader_Program_Color* textured_3D_program_color = new Textured_3D_Shader_Program_Color(textured_3D_vertex_shader_color, textured_3D_fragment_shader_color);
	_assets.insert({ textured_3D_program_color->id(), textured_3D_program_color });

	Texture* crate_texture = new Texture("Texture.Crate", "Assets/texture.crate.jpg");
	_assets.insert({crate_texture->id(), crate_texture});

	Texture* crate_sides_texture = new Texture("Texture.Crate_With_Sides_Marked", "Assets/texture.crate_with_sides_marked.jpg");
	_assets.insert({crate_sides_texture->id(), crate_sides_texture});

	Texture* cube_texture_instructions = new Texture("Texture.Cube_With_Instructions", "Assets/texture.intructions.jpg");
	_assets.insert({ cube_texture_instructions->id(), cube_texture_instructions });

	Mesh* loaded_mesh = new Obj_File_Mesh("Mesh.Robot", "Assets/Robot.obj");
	_assets.insert({loaded_mesh->id(), loaded_mesh});

	Texture* robot_tex = new Texture("Texture.Robot", "Assets/robot_diffuse.jpg", true);
	_assets.insert({robot_tex->id(), robot_tex});

	Mesh* cube_grey = new Obj_File_Mesh("Mesh.Cube_Grey", "Assets/Cube.obj");
	_assets.insert({ cube_grey->id(), cube_grey });

	Mesh* loaded_robot2_mesh = new Obj_File_Mesh("Mesh.Robot2", "Assets/Robot2.obj");
	_assets.insert({ loaded_robot2_mesh->id(), loaded_robot2_mesh });

	Mesh* loaded_dear_mesh = new Obj_File_Mesh("Mesh.Dear", "Assets/deer.obj");
	_assets.insert({ loaded_dear_mesh->id(), loaded_dear_mesh });

	Texture* white_tex = new Texture("Texture.White", "Assets/white_background.jpg", true);
	_assets.insert({ white_tex->id(), white_tex });


	Mesh* cube_modifed = new Obj_File_Mesh("Mesh.Cube_Modified", "Assets/cube_modified.obj");
	_assets.insert({ cube_modifed->id(), cube_modifed });

	Texture* cube_modified_texture = new Texture("Textured.Cube.Modified", "Assets/geometric_pattern.jpg", true);
	_assets.insert({ cube_modified_texture->id(), cube_modified_texture });

	Mesh* unique_obj = new Obj_File_Mesh("Mesh.Unique_Obj", "Assets/pyramid.obj");
	_assets.insert({ unique_obj->id(), unique_obj });

	Texture* unique_obj_texture = new Texture("Textured.Unique.Obj", "Assets/img.jpeg");
	_assets.insert({ unique_obj_texture->id(), unique_obj_texture });

	Pyramid_Mesh* pyramid_mesh = new Pyramid_Mesh();
	_assets.insert({ pyramid_mesh->id(), pyramid_mesh });

	Texture* pyramid_texture = new Texture("Texture.Crazy.Pyramid_Texture", "Assets/geo_texture.jpg");
	_assets.insert({ pyramid_texture->id(), pyramid_texture });
}
Assets::~Assets()
{
}

const Asset* Assets::get_asset(const char* id) const
{
	if(_assets.find(id) == _assets.end())
	{
		std::cout << "Attempted to find an asset that was not loaded. ID: " << id << std::endl;
		exit(1);
	}

	return _assets.find(id)->second;
}