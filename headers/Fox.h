#pragma once
#include "DESI.h"
#include "Includes.h"

class Fox : public Animal {
public:
	Fox();
	Fox(World* world, int y, int x);
	Fox(World* world, int y, int x, int strength, int age);
	void Action() override;
	~Fox();
};