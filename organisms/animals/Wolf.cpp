#pragma once
#include "DESI.h"
#include "Includes.h"

Wolf::Wolf() {}
Wolf::Wolf(World* world, int y, int x) {
	this->SetStrength(9);
	this->SetInitiative(5);
	this->SetAge(0);
	this->SetSign(WOLF);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
Wolf::Wolf(World* world, int y, int x, int strength, int age) {
	this->SetStrength(strength);
	this->SetInitiative(5);
	this->SetAge(age);
	this->SetSign(WOLF);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
Wolf::~Wolf() {}