#pragma once
#include "DESI.h"
#include "Includes.h"

WolfBerries::WolfBerries(){}
WolfBerries::WolfBerries(World* world, int y, int x){
	this->SetWorld(world);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetInitiative(0);
	this->SetStrength(99);
	this->SetSign(WOLFBERRIES);
	this->GetWorld()->AddOrganism(this);
}
WolfBerries::WolfBerries(World* world, int y, int x, int strength, int age) {
	this->SetStrength(strength);
	this->SetInitiative(0);
	this->SetAge(age);
	this->SetSign(WOLFBERRIES);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
void WolfBerries::Collision(Organism* other, int j, int i){
	// Eating Wolf Berries is kills the organism
	string tmp = "";
	tmp += other->GetSign();
	tmp += " ate ";
	tmp += GetSign();
	tmp += " and died";
	tmp += '\n';
	GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
	
	GetWorld()->RemoveOrganism(this);
	GetWorld()->RemoveOrganism(other);
}
WolfBerries::~WolfBerries(){}