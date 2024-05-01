#pragma once
#include "DESI.h"
#include "Includes.h"

Grass::Grass(){}
Grass::Grass(World* world, int y, int x) {
	this->SetWorld(world);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetInitiative(0);
	this->SetStrength(0);
	this->SetSign(GRASS);
	this->GetWorld()->AddOrganism(this);
}
Grass::Grass(World* world, int y, int x, int strength, int age) {
	this->SetStrength(strength);
	this->SetInitiative(0);
	this->SetAge(age);
	this->SetSign(GRASS);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
Grass::~Grass(){}
