#pragma once
#include "DESI.h"
#include "Includes.h"

class Dandelion : public Plant {
public:
	Dandelion();
	Dandelion(World* world, int y, int x);
	Dandelion(World* world, int y, int x, int strength, int age);
	void Action() override;
	~Dandelion();
};