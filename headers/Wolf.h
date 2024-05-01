#pragma once
#include "DESI.h"
#include "Includes.h"

class Wolf : public Animal {
public:
	Wolf();
	Wolf(World* world, int y, int x);
	Wolf(World* world, int y, int x, int strength, int age);
	~Wolf();
};