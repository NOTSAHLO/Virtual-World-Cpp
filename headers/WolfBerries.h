#pragma once
#include "DESI.h"
#include "Includes.h"

class WolfBerries : public Plant {
public:
	WolfBerries();
	WolfBerries(World* world, int y, int x);
	WolfBerries(World* world, int y, int x, int strength, int age);
	void Collision(Organism* other, int j, int i) override;
	~WolfBerries();
};