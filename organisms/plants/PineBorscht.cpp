#pragma once
#include "DESI.h"
#include "Includes.h"

PineBorscht::PineBorscht(){}
PineBorscht::PineBorscht(World* world, int y, int x) {
	this->SetWorld(world);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetInitiative(0);
	this->SetStrength(10);
	this->SetSign(PINEBORSCHT);
	this->GetWorld()->AddOrganism(this);
}
PineBorscht::PineBorscht(World* world, int y, int x, int strength, int age) {
	this->SetStrength(strength);
	this->SetInitiative(0);
	this->SetAge(age);
	this->SetSign(PINEBORSCHT);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
void PineBorscht::Action(){
	string tmp = "";
	for (int y = -1; y < 2; y++) {
		for (int x = -1; x < 2; x++) {
			if (0 <= GetPosY() + y and GetPosY() + y <= GetWorld()->GetMaxY() and 0 <= GetPosX() + x and GetPosX() + x <= GetWorld()->GetMaxX()) {
				if (x == 0 and y == 0) {
					continue;
				}
				else{
					// Getting too close to Pine Borscht kills the organism
					if (GetWorld()->worldMap[GetPosY() + y][GetPosX() + x] != nullptr) {
						tmp += GetWorld()->worldMap[GetPosY() + y][GetPosX() + x]->GetSign();
						tmp += " got too close to ";
						tmp += GetSign();
						tmp += " and died";
						tmp += '\n';
						GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
						GetWorld()->RemoveOrganism(GetWorld()->worldMap[GetPosY() + y][GetPosX() + x]);
					}
				}
			}
		}
	}
}
void PineBorscht::Collision(Organism* other, int j, int i) {
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
PineBorscht::~PineBorscht(){}