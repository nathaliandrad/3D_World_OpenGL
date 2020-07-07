#pragma once

#include "game_object.h"

class Unique_Object : public Game_Object
{
public:
	Unique_Object(const char* id);
	~Unique_Object();

	virtual void simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config, const Input*) override;
	virtual void render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) override;
};
