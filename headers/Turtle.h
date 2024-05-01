#pragma once
#include "DESI.h"
#include "Includes.h"

class Turtle : public Animal {
public:
	Turtle();
	Turtle(World* world, int y, int x);
	Turtle(World* world, int y, int x, int strength, int age);
	void Action() override;
	void Collision(Organism* other, int j, int i) override;
	bool PushBack(Organism* other);
	~Turtle();
};