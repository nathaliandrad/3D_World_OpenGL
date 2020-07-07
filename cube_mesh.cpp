#pragma once

#include "cube_mesh.h"


Cube_Mesh::Cube_Mesh()
	: Mesh("Mesh.Cube")
{
	auto v1 = {-0.5f, 0.5f, 0.5f};
	auto v2 = {-0.5f, -0.5f, 0.5f};
	auto v3 = {0.5f, -0.5f, 0.5f};
	auto v4 = {0.5f, 0.5f, 0.5f};

	auto v5 = {-0.5f, 0.5f, -0.5f};
	auto v6 = {-0.5f, -0.5f, -0.5f};
	auto v7 = {0.5f, -0.5f, -0.5f};
	auto v8 = {0.5f, 0.5f, -0.5f};

	auto forward  = {0.f, 0.f, 1.f};
	auto backward = {0.f, 0.f, -1.f};
	auto left     = {-1.f, 0.f, 0.f};
	auto right    = {1.f, 0.f, 0.f};
	auto up       = {0.f, 1.f, 0.f};
	auto down     = {0.f, -1.f, 0.f};

	auto width = 1.0f / 6.0f;
	for(int face_index = 0; face_index < 6; ++face_index)
	{
		auto tl = {face_index * width, 0.0f};
		auto tr = {(face_index * width) + width, 0.0f};
		auto br = {(face_index * width) + width, 1.0f};
		auto bl = {face_index * width, 1.0f};

		_texture_coordinates.insert(_texture_coordinates.end(), tl);
		_texture_coordinates.insert(_texture_coordinates.end(), bl);
		_texture_coordinates.insert(_texture_coordinates.end(), br);
		_texture_coordinates.insert(_texture_coordinates.end(), tl);
		_texture_coordinates.insert(_texture_coordinates.end(), br);
		_texture_coordinates.insert(_texture_coordinates.end(), tr);
	}

	/*
	auto tl = {0.0f, 0.0f};
	auto tr = {1.0f, 0.0f};
	auto br = {1.0f, 1.0f};
	auto bl = {0.0f, 1.0f};
	*/

	// Front Face
	_verticies.insert(_verticies.end(), v1);
	_verticies.insert(_verticies.end(), v2);
	_verticies.insert(_verticies.end(), v3);
	_verticies.insert(_verticies.end(), v1);
	_verticies.insert(_verticies.end(), v3);
	_verticies.insert(_verticies.end(), v4);

	_normals.insert(_normals.end(), forward);
	_normals.insert(_normals.end(), forward);
	_normals.insert(_normals.end(), forward);
	_normals.insert(_normals.end(), forward);
	_normals.insert(_normals.end(), forward);
	_normals.insert(_normals.end(), forward);
	
	/*
	_texture_coordinates.insert(_texture_coordinates.end(), tl);
	_texture_coordinates.insert(_texture_coordinates.end(), bl);
	_texture_coordinates.insert(_texture_coordinates.end(), br);
	_texture_coordinates.insert(_texture_coordinates.end(), tl);
	_texture_coordinates.insert(_texture_coordinates.end(), br);
	_texture_coordinates.insert(_texture_coordinates.end(), tr);
	*/

	// Right Face
	_verticies.insert(_verticies.end(), v4);
	_verticies.insert(_verticies.end(), v3);
	_verticies.insert(_verticies.end(), v7);
	_verticies.insert(_verticies.end(), v4);
	_verticies.insert(_verticies.end(), v7);
	_verticies.insert(_verticies.end(), v8);

	_normals.insert(_normals.end(), right);
	_normals.insert(_normals.end(), right);
	_normals.insert(_normals.end(), right);
	_normals.insert(_normals.end(), right);
	_normals.insert(_normals.end(), right);
	_normals.insert(_normals.end(), right);

	/*
	_texture_coordinates.insert(_texture_coordinates.end(), tl);
	_texture_coordinates.insert(_texture_coordinates.end(), bl);
	_texture_coordinates.insert(_texture_coordinates.end(), br);
	_texture_coordinates.insert(_texture_coordinates.end(), tl);
	_texture_coordinates.insert(_texture_coordinates.end(), br);
	_texture_coordinates.insert(_texture_coordinates.end(), tr);
	*/

	// Back Face
	_verticies.insert(_verticies.end(), v8);
	_verticies.insert(_verticies.end(), v7);
	_verticies.insert(_verticies.end(), v6);
	_verticies.insert(_verticies.end(), v8);
	_verticies.insert(_verticies.end(), v6);
	_verticies.insert(_verticies.end(), v5);

	_normals.insert(_normals.end(), backward);
	_normals.insert(_normals.end(), backward);
	_normals.insert(_normals.end(), backward);
	_normals.insert(_normals.end(), backward);
	_normals.insert(_normals.end(), backward);
	_normals.insert(_normals.end(), backward);

	/*
	_texture_coordinates.insert(_texture_coordinates.end(), tl);
	_texture_coordinates.insert(_texture_coordinates.end(), bl);
	_texture_coordinates.insert(_texture_coordinates.end(), br);
	_texture_coordinates.insert(_texture_coordinates.end(), tl);
	_texture_coordinates.insert(_texture_coordinates.end(), br);
	_texture_coordinates.insert(_texture_coordinates.end(), tr);
	*/
	
	// Left Face
	_verticies.insert(_verticies.end(), v5);
	_verticies.insert(_verticies.end(), v6);
	_verticies.insert(_verticies.end(), v2);
	_verticies.insert(_verticies.end(), v5);
	_verticies.insert(_verticies.end(), v2);
	_verticies.insert(_verticies.end(), v1);

	_normals.insert(_normals.end(), left);
	_normals.insert(_normals.end(), left);
	_normals.insert(_normals.end(), left);
	_normals.insert(_normals.end(), left);
	_normals.insert(_normals.end(), left);
	_normals.insert(_normals.end(), left);

	/*
	_texture_coordinates.insert(_texture_coordinates.end(), tl);
	_texture_coordinates.insert(_texture_coordinates.end(), bl);
	_texture_coordinates.insert(_texture_coordinates.end(), br);
	_texture_coordinates.insert(_texture_coordinates.end(), tl);
	_texture_coordinates.insert(_texture_coordinates.end(), br);
	_texture_coordinates.insert(_texture_coordinates.end(), tr);
	*/

	// Top Face
	_verticies.insert(_verticies.end(), v5);
	_verticies.insert(_verticies.end(), v1);
	_verticies.insert(_verticies.end(), v4);
	_verticies.insert(_verticies.end(), v5);
	_verticies.insert(_verticies.end(), v4);
	_verticies.insert(_verticies.end(), v8);

	_normals.insert(_normals.end(), up);
	_normals.insert(_normals.end(), up);
	_normals.insert(_normals.end(), up);
	_normals.insert(_normals.end(), up);
	_normals.insert(_normals.end(), up);
	_normals.insert(_normals.end(), up);

	/*
	_texture_coordinates.insert(_texture_coordinates.end(), tl);
	_texture_coordinates.insert(_texture_coordinates.end(), bl);
	_texture_coordinates.insert(_texture_coordinates.end(), br);
	_texture_coordinates.insert(_texture_coordinates.end(), tl);
	_texture_coordinates.insert(_texture_coordinates.end(), br);
	_texture_coordinates.insert(_texture_coordinates.end(), tr);
	*/

	// Bottom Face
	
	_verticies.insert(_verticies.end(), v2);
	_verticies.insert(_verticies.end(), v6);
	_verticies.insert(_verticies.end(), v7);
	_verticies.insert(_verticies.end(), v2);
	_verticies.insert(_verticies.end(), v7);
	_verticies.insert(_verticies.end(), v3);

	_normals.insert(_normals.end(), down);
	_normals.insert(_normals.end(), down);
	_normals.insert(_normals.end(), down);
	_normals.insert(_normals.end(), down);
	_normals.insert(_normals.end(), down);
	_normals.insert(_normals.end(), down);
	
	/*
	_texture_coordinates.insert(_texture_coordinates.end(), tl);
	_texture_coordinates.insert(_texture_coordinates.end(), bl);
	_texture_coordinates.insert(_texture_coordinates.end(), br);
	_texture_coordinates.insert(_texture_coordinates.end(), tl);
	_texture_coordinates.insert(_texture_coordinates.end(), br);
	_texture_coordinates.insert(_texture_coordinates.end(), tr);
	*/
}
Cube_Mesh::~Cube_Mesh()
{
}