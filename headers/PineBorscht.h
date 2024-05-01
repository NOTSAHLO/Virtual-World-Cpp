#pragma once
#include "DESI.h"
#include "Includes.h"

class PineBorscht : public Plant {
public:
	PineBorscht();
	PineBorscht(World* world, int y, int x);
	PineBorscht(World* world, int y, int x, int strength, int age);
	void Action() override;
	void Collision(Organism* other, int j, int i) override;
	~PineBorscht();
};