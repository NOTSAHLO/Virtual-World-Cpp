#pragma once
#include "DESI.h"
#include "Includes.h"

Fox::Fox() {}
Fox::Fox(World* world, int y, int x) {
	this->SetStrength(3);
	this->SetInitiative(7);
	this->SetAge(0);
	this->SetSign(FOX);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
Fox::Fox(World* world, int y, int x, int strength, int age) {
	this->SetStrength(strength);
	this->SetInitiative(7);
	this->SetAge(age);
	this->SetSign(FOX);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
void Fox::Action() {
	string tmp = "";
	if (GetAlive() == true) {
		this->SetAge(this->GetAge() + 1);
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
			MoveOrganism(j, i);
		}
		else {
			// Fox will never more to a spot with a stronger organism
			if (GetWorld()->worldMap[GetPosY() + j][GetPosX() + i]->GetStrength() > this->GetStrength()) {
				tmp += GetSign();
				tmp += " smelled danger and avoided death";
				tmp += '\n';
				GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
				Position newPos = FindFreeSpot(GetWorld(), this);
				MoveOrganism(newPos.y, newPos.x);
			}
			else {
				Collision(GetWorld()->worldMap[GetPosY() + j][GetPosX() + i], j, i);
			}
		}
	}
}
Fox::~Fox() {}