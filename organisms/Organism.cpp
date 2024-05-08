#pragma once
#include "DESI.h"
#include "Includes.h"

Organism::Organism() {}
Organism::Organism(int y, int x) {
	this->SetPosX(x);
	this->SetPosY(y);
}
int Organism::GetStrength() {
	return this->strength;
}
int Organism::GetInitiative() {
	return this->initiative;
}
int Organism::GetAge() {
	return this->age;
}
char Organism::GetSign() {
	return this->sign;
}
int Organism::GetPosX() {
	return this->position.x;
}
int Organism::GetPosY() {
	return this->position.y;
}
bool Organism::GetAlive() {
	return this->alive;
}
World* Organism::GetWorld() {
	return this->world;
}
void Organism::SetStrength(int strength) {
	this->strength = strength;
}
void Organism::SetInitiative(int initiative) {
	this->initiative = initiative;
}
void Organism::SetSign(char sign) {
	this->sign = sign;
}
void Organism::SetAge(int age) {
	this->age = age;
}
void Organism::SetPosX(int x) {
	this->position.x = x;
}
void Organism::SetPosY(int y) {
	this->position.y = y;
}
void Organism::SetWorld(World* world) {
	this->world = world;
}
void Organism::SetAlive(bool alive) {
	this->alive = alive;
}
void Organism::MoveOrganism(int j, int i) {
	GetWorld()->worldMap[GetPosY() + j][GetPosX() + i] = this;
	GetWorld()->worldMap[GetPosY()][GetPosX()] = nullptr;
	SetPosY(GetPosY() + j);
	SetPosX(GetPosX() + i);
}
void Organism::RandomDirection(Direction& direction) {
	// Top-Left Corner
	if (this->GetPosY() == 0 and this->GetPosX() == 0) {
		int temp = rand() % 2;
		if (temp == 0)
			direction = DOWN;
		else
			direction = RIGHT;
	}
	// Top-Right Corner
	else if (this->GetPosY() == 0 and this->GetPosX() == this->GetWorld()->GetMaxX()) {
		int temp = rand() % 2;
		if (temp == 0)
			direction = DOWN;
		else
			direction = LEFT;
	}
	// Bottom-Left Corner
	else if (this->GetPosY() == this->GetWorld()->GetMaxY() and this->GetPosX() == 0) {
		int temp = rand() % 2;
		if (temp == 0)
			direction = UP;
		else
			direction = RIGHT;
	}
	// Bottom-Right Corner
	else if (this->GetPosY() == this->GetWorld()->GetMaxY() and this->GetPosX() == this->GetWorld()->GetMaxX()) {
		int temp = rand() % 2;
		if (temp == 0)
			direction = UP;
		else
			direction = LEFT;
	}
	// Left Side not Corner
	else if (this->GetPosX() == 0) {
		int temp = rand() % 3;
		if (temp == 0)
			direction = UP;
		else if (temp == 1)
			direction = DOWN;
		else
			direction = RIGHT;
	}
	// Top Side not Corner
	else if (this->GetPosY() == 0) {
		int temp = rand() % 3;
		if (temp == 0)
			direction = DOWN;
		else if (temp == 1)
			direction = LEFT;
		else
			direction = RIGHT;
	}
	// Right Side not Corner
	else if (this->GetPosX() == this->GetWorld()->GetMaxX()) {
		int temp = rand() % 3;
		if (temp == 0)
			direction = UP;
		else if (temp == 1)
			direction = DOWN;
		else
			direction = LEFT;
	}
	// Bottom Side not Corner
	else if (this->GetPosY() == this->GetWorld()->GetMaxY()) {
		int temp = rand() % 3;
		if (temp == 0)
			direction = UP;
		else if (temp == 1)
			direction = LEFT;
		else
			direction = RIGHT;
	}
	// If it's not on any border
	else {
		direction = (Direction)(rand() % 4);
	}
}
Organism::~Organism() {}