#pragma once

#include "square_mesh.h"

Square_Mesh::Square_Mesh()
	: Mesh("Mesh.Square")
{
	_verticies.insert(_verticies.end(), {-0.5f, 0.5f, 0.f});  // v1
	_verticies.insert(_verticies.end(), {-0.5f, -0.5f, 0.f}); // v2
	_verticies.insert(_verticies.end(), {0.5f, -0.5f, 0.f});  // v3
	_verticies.insert(_verticies.end(), {-0.5f, 0.5f, 0.f});  // v1
	_verticies.insert(_verticies.end(), {0.5f, -0.5f, 0.f});  // v3
	_verticies.insert(_verticies.end(), {0.5f, 0.5f, 0.f});   // v4

	_texture_coordinates.insert(_texture_coordinates.end(), {0.0f, 0.0f});
	_texture_coordinates.insert(_texture_coordinates.end(), {0.0f, 1.0f});
	_texture_coordinates.insert(_texture_coordinates.end(), {1.0f, 1.0f});
	_texture_coordinates.insert(_texture_coordinates.end(), {0.0f, 0.0f});
	_texture_coordinates.insert(_texture_coordinates.end(), {1.0f, 1.0f});
	_texture_coordinates.insert(_texture_coordinates.end(), {1.0f, 0.0f});
}
Square_Mesh::~Square_Mesh()
{
}