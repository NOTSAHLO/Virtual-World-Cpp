#pragma once
#include "DESI.h"
#include "Includes.h"

Turtle::Turtle() {}
Turtle::Turtle(World* world, int y, int x) {
	this->SetStrength(2);
	this->SetInitiative(1);
	this->SetAge(0);
	this->SetSign(TURTLE);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
Turtle::Turtle(World* world, int y, int x, int strength, int age) {
	this->SetStrength(strength);
	this->SetInitiative(1);
	this->SetAge(age);
	this->SetSign(TURTLE);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
void Turtle::Action() {
	if(GetAlive() == true){
		int doesItMove = rand() % 100 + 1;
		if (doesItMove > 75) {
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
}
void Turtle::Collision(Organism* other, int j, int i) {
	string tmp = "";
	bool pushBack = PushBack(other);
	if (this->GetSign() == other->GetSign()) {
		if (this->GetAge() > 3 and other->GetAge() > 3) {
			Position pos = FindFreeSpot(this->GetWorld(), this);
			if (pos.y != 0 and pos.x != 0) {		
				Turtle* kid = new Turtle(GetWorld(), GetPosY() + pos.y, GetPosX() + pos.x);	
				tmp += "New ";
				tmp += GetSign();
				tmp += " was born";
				tmp += '\n';
				GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
				this->SetAge(0);
				other->SetAge(0);
			}
		}
	}
	else {
		// Turtle can resist attackers with strength < 5
		if (pushBack == true) {
			tmp += GetSign();
			tmp += " pushes back attacking ";
			tmp += other->GetSign();
			tmp += '\n';
			GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
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
bool Turtle::PushBack(Organism* attacker) {
	if (attacker->GetStrength() < 5)
		return true;
	else
		return false;
}
Turtle::~Turtle() {}