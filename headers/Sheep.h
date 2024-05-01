#pragma once
#include "DESI.h"
#include "Includes.h"

class Sheep : public Animal {
public:
	Sheep();
	Sheep(World* world, int y, int x);
	Sheep(World* world, int y, int x, int strength, int age);
	~Sheep();
};
