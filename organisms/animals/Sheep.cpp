#pragma once
#include "DESI.h"
#include "Includes.h"

Sheep::Sheep() {}
Sheep::Sheep(World* world, int y, int x) {
	this->SetStrength(4);
	this->SetInitiative(4);
	this->SetAge(0);
	this->SetSign(SHEEP);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
Sheep::Sheep(World* world, int y, int x, int strength, int age) {
	this->SetStrength(strength);
	this->SetInitiative(4);
	this->SetAge(age);
	this->SetSign(SHEEP);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
Sheep::~Sheep() {}