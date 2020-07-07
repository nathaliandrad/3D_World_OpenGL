#pragma once

#include "game_object.h"

class Crazy_Crate : public Game_Object
{
public:
	Crazy_Crate(const char* id);
	~Crazy_Crate();

	virtual void simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config, const Input* input) override;
	virtual void render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) override;
};