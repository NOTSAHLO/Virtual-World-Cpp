#pragma once
#include"DESI.h"
#include "Includes.h"

Animal::Animal() {}
void Animal::Action() {
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
			GetWorld()->worldMap[GetPosY() + j][GetPosX() + i]->Collision(this, j, i);
		}
	}
}
void Animal::Collision(Organism* other, int j, int i) {
	// collision is handled from the perspective of the organism that is not moving
	string tmp = "";
	if (this->GetSign() == other->GetSign()) {
		if (this->GetAge() > 3 and other->GetAge() > 3) {
			Position pos = FindFreeSpot(this->GetWorld(), this);
			if (pos.y != 0 and pos.x != 0) {
				if (GetSign() == WOLF) {
					Wolf* kid = new Wolf(GetWorld(), GetPosY() + pos.y, GetPosX() + pos.x);
				}
				else if (GetSign() == SHEEP) {
					Sheep* kid = new Sheep(GetWorld(), GetPosY() + pos.y, GetPosX() + pos.x);
				}
				else if (GetSign() == FOX) {
					Fox* kid = new Fox(GetWorld(), GetPosY() + pos.y, GetPosX() + pos.x);
				}
				tmp += "New ";
				tmp += GetSign();
				tmp += " was born";
				tmp += '\n';
				GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
				// this prevents constant breeding, the order of organisms in list is preserved
				this->SetAge(0);
				other->SetAge(0);
			}
		}
	}
	else {
		if (other->GetStrength() >= this->GetStrength()) {
			tmp += other->GetSign();
			tmp += " anihilates ";
			tmp += this->GetSign();
			tmp += '\n';
			GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
			GetWorld()->RemoveOrganism(this);
			other->MoveOrganism(j, i);
		}
		else {
			tmp += other->GetSign();
			tmp += " gets anihilated by ";
			tmp += this->GetSign();
			tmp += '\n';
			GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
			GetWorld()->RemoveOrganism(other);
		}
	}
}
Position Animal::FindFreeSpot(World* world, Organism* organism) {
	Position tmp;
	tmp.y = 0;
	tmp.x = 0;
	for (int y = -1; y < 2; y++) {
		for (int x = -1; x < 2; x++) {
			if (0 <= organism->GetPosY() + y and organism->GetPosY() + y <= world->GetMaxY() and 0 <= organism->GetPosX() + x and organism->GetPosX() + x <= world->GetMaxX()) {
				if (world->worldMap[organism->GetPosY() + y][organism->GetPosX() + x] == nullptr) {
					tmp.y = y;
					tmp.x = x;
					return tmp;
				}
			}
		}
	}
	return tmp;
}
const void Animal::Print() {
	cout << this->GetSign();
}
Animal::~Animal() {

}