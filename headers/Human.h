#pragma once
#include "DESI.h"
#include "Includes.h"

class Human : public Animal {
private:
	int j = 0;
	int i = 0;
	int powerActive = 0;
	int cooldown = 0;
public:
	Human();
	Human(World* world, int y, int x);
	Human(World* world, int y, int x, int strength, int age);
	void Steer();
	void Action() override;
	void Collision(Organism* other, int j, int i) override;
	int GetPowerActive();
	int GetCooldown();
	~Human();
};