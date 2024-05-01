#pragma once
#include "DESI.h"
#include "Includes.h"

Human::Human() {}
Human::Human(World* world, int y, int x) {
	this->SetStrength(5);
	this->SetInitiative(4);
	this->SetAge(0);
	this->SetSign(HUMAN);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
Human::Human(World* world, int y, int x, int strength, int age) {
	this->SetStrength(strength);
	this->SetInitiative(4);
	this->SetAge(age);
	this->SetSign(HUMAN);
	this->SetPosY(y);
	this->SetPosX(x);
	this->SetWorld(world);
	world->AddOrganism(this);
}
void Human::Steer() {
	string tmp = "";
	char input;
	input = _getch();
	if (input == 'w') {
		this->j = -1;
		this->i = 0;
	}
	else if (input == 's') {
		this->j = 1;
		this->i = 0;
	}
	else if (input == 'a') {
		this->j = 0;
		this->i = -1;
	}
	else if (input == 'd') {
		this->j = 0;
		this->i = 1;
	}
	else if (input == 'q') {
		this->j = 0;
		this->i = 0;
		if (this->cooldown == 0) {
			this->powerActive = 1;
			this->cooldown = 12;
			tmp += GetSign();
			tmp += " activated it's power";
			tmp += '\n';
			GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
		}
		else {
			tmp += GetSign();
			tmp += " power recovering";
			tmp += '\n';
			GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
		}
	}
	else if (input == 't') {
		GetWorld()->Save();
	}
	else if (input == 'y') {
		this->GetWorld()->SetLoadFromFile(true);
	}
	else {
		this->j = 0;
		this->i = 0;
	}
}
void Human::Action() {
	string tmp = "";
	if (powerActive == 1) {
		if (cooldown < 8) {
			powerActive = 0;
			tmp += GetSign();
			tmp += " power expired";
			tmp += '\n';
			GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
		}
		cooldown--;
	}
	if (powerActive == 0 and cooldown != 0) {
		cooldown--;
		if (cooldown == 0) {
			tmp += GetSign();
			tmp += " power ready";
			tmp += '\n';
			GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
		}
	}		
	if (GetAlive() == true) {
		if (GetPosY() + j >= 0 and GetPosY() + j <= GetWorld()->GetMaxY()) {
			if (GetPosX() + i >= 0 and GetPosX() + i <= GetWorld()->GetMaxX()) {
				if(GetWorld()->worldMap[GetPosY() + j][GetPosX() + i] == nullptr)
					MoveOrganism(j, i);
				else {
					if ((j == 1 and i == 0) or (j == -1 and i == 0) or (j == 0 and i == 1) or (j == 0 and i == -1)) {
						if(powerActive == 0)
							GetWorld()->worldMap[GetPosY() + j][GetPosX() + i]->Collision(this, j, i);
						else {
							if (GetWorld()->worldMap[GetPosY() + j][GetPosX() + i]->GetStrength() > GetStrength()) {
								tmp += GetSign();
								tmp += " escaped death with his power";
								tmp += '\n';
								GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
								Position newPos = FindFreeSpot(GetWorld(), this);
								MoveOrganism(newPos.y, newPos.x);
							}
							else {
								GetWorld()->worldMap[GetPosY() + j][GetPosX() + i]->Collision(this, j, i);
							}
						}
					}
				}
			}
		}	
	}	
}
void Human::Collision(Organism* other, int j, int i){
	string tmp = "";
	if (powerActive == 0) {
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
	else {
		if (other->GetStrength() >= this->GetStrength()) {
			tmp += GetSign();
			tmp += " escaped death with his power";
			tmp += '\n';
			GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
			Position newPos = FindFreeSpot(GetWorld(), this);
			MoveOrganism(newPos.y, newPos.x);
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
int Human::GetPowerActive() {
	return this->powerActive;
}
int Human::GetCooldown() {
	return this->cooldown;
}
Human::~Human(){}