#pragma once
#include "DESI.h"
#include "Includes.h"

Antylope::Antylope() {}
Antylope::Antylope(World* world, int y, int x) {
	this->SetStrength(4);
	this->SetInitiative(4);
	this->SetAge(0);
	this->SetSign(ANTYLOPE);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
Antylope::Antylope(World* world, int y, int x, int strength, int age) {
	this->SetStrength(strength);
	this->SetInitiative(4);
	this->SetAge(age);
	this->SetSign(ANTYLOPE);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
void Antylope::Action() {
	if (GetAlive() == true) {
		int jumpLength = rand() % 2 + 1;
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
		if (0 >= GetPosY() + j* jumpLength or GetPosY() + j * jumpLength >= GetWorld()->GetMaxY() or 0 >= GetPosX() + i * jumpLength or GetPosX()+i * jumpLength >= GetWorld()->GetMaxX()) {
			Position newPos = FindFreeSpot(GetWorld(), this);
			MoveOrganism(newPos.y, newPos.x);
		}
		else if (GetWorld()->worldMap[GetPosY() + j * jumpLength][GetPosX() + i * jumpLength] == nullptr) {
			MoveOrganism(j * jumpLength, i * jumpLength);
		}
		else {
			GetWorld()->worldMap[GetPosY() + j * jumpLength][GetPosX() + i * jumpLength]->Collision(this, j * jumpLength, i * jumpLength);
		}
	}
}
void Antylope::Collision(Organism* other, int j, int i) {
	bool run = RunAway();
	string tmp = "";
	if (this->GetSign() == other->GetSign()) {
		if (this->GetAge() > 3 and other->GetAge() > 3) {
			Position pos = FindFreeSpot(this->GetWorld(), this);
			if (pos.y != 0 and pos.x != 0) {
				Antylope* kid = new Antylope(GetWorld(), GetPosY() + pos.y, GetPosX() + pos.x);
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
		// Antylope has a 50% chance to run away from the attacker
		if (run == true) {
			tmp += GetSign();
			tmp += " ran away from attacking ";
			tmp += other->GetSign();
			tmp += '\n';
			GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
			Position newPos = FindFreeSpot(GetWorld(), this);
			MoveOrganism(newPos.y, newPos.x);
			other->MoveOrganism(j, i);
		}
		else {
			if (other->GetStrength() >= this->GetStrength()) {
				tmp += other->GetSign();
				tmp += " anihilates ";
				tmp += GetSign();
				tmp += '\n';
				GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
				GetWorld()->RemoveOrganism(this);
				other->MoveOrganism(j, i);
			}
			else {
				tmp += other->GetSign();
				tmp += " gets anihilated by ";
				tmp += GetSign();
				tmp += '\n';
				GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
				GetWorld()->RemoveOrganism(other);
			}
		}
	}
}
bool Antylope::RunAway() {
	int doesItRun = rand() % 100 + 1;
	if (doesItRun > 50)
		return true;
	else
		return false;
}
Antylope::~Antylope() {}