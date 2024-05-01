#pragma once
#include "DESI.h"
#include "Includes.h"

class Antylope : public Animal {
public:
	Antylope();
	Antylope(World* world, int y, int x);
	Antylope(World* world, int y, int x, int strength, int age);
	void Action() override;
	void Collision(Organism* other, int j, int i) override;
	bool RunAway();
	~Antylope();
};
