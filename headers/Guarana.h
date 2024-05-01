#pragma once
#include "DESI.h"
#include "Includes.h"

class Guarana : public Plant {
public:
	Guarana();
	Guarana(World* world, int y, int x);
	Guarana(World* world, int y, int x, int strength, int age);
	void Collision(Organism* other, int j, int i) override;
	~Guarana();
};