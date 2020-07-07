#pragma once

#include "game_object.h"

class Pointy_Head : public Game_Object
{
public:
	Pointy_Head(const char* id);
	~Pointy_Head();

	virtual void simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config, const Input* input) override;
	virtual void render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) override;

private:
	double _total_time;
};