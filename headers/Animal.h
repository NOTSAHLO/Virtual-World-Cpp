#pragma once
#include "DESI.h"
#include "Includes.h"

class Animal : public Organism {
public:
	Animal();
	void Action() override;
	void Collision(Organism* other, int j, int i) override;
	const void Print() override;
	Position FindFreeSpot(World* world, Organism* organism);
	~Animal();
};