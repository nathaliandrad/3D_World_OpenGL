#pragma once

#include "game_object.h"

class Human_Conqueror : public Game_Object
{
public:
	Human_Conqueror(const char* id);
	~Human_Conqueror();

	virtual void simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config, const Input*) override;
	virtual void render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) override;
};
