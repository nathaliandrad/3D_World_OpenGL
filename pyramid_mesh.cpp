#pragma once

#include "pyramid_mesh.h"


Pyramid_Mesh::Pyramid_Mesh()
	: Mesh("Mesh.Pyramid")
{
	/*SQUARE PYRAMID*/

	auto v1Plus = { -0.5f, -0.5f, 0.5f };
	auto v2 = { 0.f, 0.5f , 0.f };
	auto v3Plus = { 0.5f, -0.5f ,0.5f };

	auto v1Neg = { -0.5f, -0.5f , -0.5f };
	auto v3Neg = { 0.5f, -0.5f,-0.5f };

	auto s1 = { -0.5f, 0.5f, 0.5f };
	auto s2 = { -0.5f, -0.5f, 0.5f };
	auto s3 = { 0.5f, -0.5f, 0.5f };
	auto s4 = { 0.5f, 0.5f, 0.5f };

	auto s5 = { -0.5f, 0.5f, -0.5f };
	auto s6 = { -0.5f, -0.5f, -0.5f };
	auto s7 = { 0.5f, -0.5f, -0.5f };
	auto s8 = { 0.5f, 0.5f, -0.5f };

	auto width = 1.0f / 5.0f;
	for (int face_index = 0; face_index < 5; ++face_index)
	{
		auto tl = { face_index * width, 0.0f };
		auto tr = { (face_index * width) + width, 0.0f };
		auto br = { (face_index * width) + width, 1.0f };
		auto bl = { face_index * width, 1.0f };

		_texture_coordinates.insert(_texture_coordinates.end(), tl);
		_texture_coordinates.insert(_texture_coordinates.end(), bl);
		_texture_coordinates.insert(_texture_coordinates.end(), br);
		_texture_coordinates.insert(_texture_coordinates.end(), tl);
		_texture_coordinates.insert(_texture_coordinates.end(), br);
		_texture_coordinates.insert(_texture_coordinates.end(), tr);
	}
	//front
	_verticies.insert(_verticies.end(), v1Neg);
	_verticies.insert(_verticies.end(), v2);
	_verticies.insert(_verticies.end(), v3Neg);

	//right
	_verticies.insert(_verticies.end(), v3Neg);
	_verticies.insert(_verticies.end(), v2);
	_verticies.insert(_verticies.end(), v3Plus);

	//back
	_verticies.insert(_verticies.end(), v3Plus);
	_verticies.insert(_verticies.end(), v2);
	_verticies.insert(_verticies.end(), v1Plus);

	//left
	_verticies.insert(_verticies.end(), v1Plus);
	_verticies.insert(_verticies.end(), v2);
	_verticies.insert(_verticies.end(), v1Neg);

	// Bottom
	_verticies.insert(_verticies.end(), s2);
	_verticies.insert(_verticies.end(), s6);
	_verticies.insert(_verticies.end(), s7);
	_verticies.insert(_verticies.end(), s2);
	_verticies.insert(_verticies.end(), s7);
	_verticies.insert(_verticies.end(), s3);

}
Pyramid_Mesh::~Pyramid_Mesh()
{
}