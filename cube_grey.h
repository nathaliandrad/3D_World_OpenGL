#pragma once

#include "game_object.h"

class Cube_Grey : public Game_Object
{
public:
	Cube_Grey(const char* id);
	~Cube_Grey();

	virtual void simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config, const Input*) override;
	virtual void render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) override;
};
