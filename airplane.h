#pragma once

#include "game_object.h"

class Airplane : public Game_Object
{
public:
	Airplane(const char* id);
	~Airplane();

	virtual void simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config, const Input*) override;
	virtual void render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) override;
};