#pragma once
#include "DESI.h"
#include "Includes.h"

Dandelion::Dandelion() {}
Dandelion::Dandelion(World* world, int y, int x){
	this->SetWorld(world);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetInitiative(0);
	this->SetStrength(0);
	this->SetSign(DANDELION);
	this->GetWorld()->AddOrganism(this);
}
Dandelion::Dandelion(World* world, int y, int x, int strength, int age) {
	this->SetStrength(strength);
	this->SetInitiative(0);
	this->SetAge(age);
	this->SetSign(DANDELION);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
void Dandelion::Action(){
	string tmp = "";
	if (GetAlive() == true) {
		for (int i = 0; i < 3; i++) {
			int grow = rand() % 100 + 1;
			if (grow > 98) {
				Direction direction;
				RandomDirection(direction);
				int j = 0;
				int i = 0;
				if (direction == UP)
					j--;
				else if (direction == DOWN)
					j++;
				else if (direction == LEFT)
					i--;
				else if (direction == RIGHT)
					i++;
				if (GetWorld()->worldMap[GetPosY() + j][GetPosX() + i] == nullptr) {
					Dandelion* seed = new Dandelion(GetWorld(), GetPosY() + j, GetPosX() + i);
					tmp += GetSign();
					tmp += " spreads";
					tmp += '\n';
					GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
				}
			}
		}
	}
}
Dandelion::~Dandelion(){}