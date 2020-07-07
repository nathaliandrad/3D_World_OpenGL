#pragma once

struct Configuration
{
	bool render_wireframe = false;

	int screen_width      = 1400;
	int screen_height     = 1000;
	int y_units           = 1;
	int z_units           = 1000;
	float fov             = 90.f;


	enum class Projection
	{
		Orthographic,
		Perspective,
		Player
	};
	Projection projection = Projection::Orthographic;	
};