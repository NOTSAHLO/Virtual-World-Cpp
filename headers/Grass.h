#pragma once
#include "DESI.h"
#include "Includes.h"

class Grass : public Plant {
public:
	Grass();
	Grass(World* world, int y, int x);
	Grass(World* world, int y, int x, int strength, int age);
	~Grass();
};