#pragma once

#include "game_object.h"

class Blocky_Boy : public Game_Object
{
public:
	Blocky_Boy(const char* id);
	~Blocky_Boy();

	virtual void simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config, const Input* input) override;
	virtual void render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) override;

private:
	double _total_time;
};
