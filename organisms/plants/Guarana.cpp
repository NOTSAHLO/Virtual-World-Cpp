#pragma once
#include "DESI.h"
#include "Includes.h"

Guarana::Guarana() {}
Guarana::Guarana(World* world, int y, int x) {
	this->SetWorld(world);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetInitiative(0);
	this->SetStrength(0);
	this->SetSign(GUARANA);
	this->GetWorld()->AddOrganism(this);
}
Guarana::Guarana(World* world, int y, int x, int strength, int age) {
	this->SetStrength(strength);
	this->SetInitiative(0);
	this->SetAge(age);
	this->SetSign(GUARANA);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
void Guarana::Collision(Organism* other, int j, int i) {
	// Eating guarana gives 3 strength points
	string tmp = "";
	tmp += other->GetSign();
	tmp += " ate ";
	tmp += GetSign();
	tmp += '\n';
	GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
	GetWorld()->RemoveOrganism(this);
	other->SetStrength(other->GetStrength() + 3);
	other->MoveOrganism(j, i);
}
Guarana::~Guarana() {}