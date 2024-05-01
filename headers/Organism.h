#pragma once
#include "DESI.h"
#include "Includes.h"

class World;

class Organism {
private:
	int strength;
	int initiative;
	int age = 0;
	bool alive = true;
	char sign;
	Position position;
	World* world;
public:
	Organism();
	Organism(int y, int x);
	virtual void Action() = 0;
	virtual void Collision(Organism* attacker, int j, int i) = 0;
	virtual const void Print() = 0;
	int GetStrength();
	int GetInitiative();
	int GetAge();
	char GetSign();
	int GetPosX();
	int GetPosY();
	bool GetAlive();
	void SetStrength(int strength);
	void SetInitiative(int initiative);
	void SetSign(char sign);
	void SetPosX(int x);
	void SetPosY(int y);
	void SetAge(int age);
	void SetWorld(World* world);
	void SetAlive(bool alive);
	World* GetWorld();
	void MoveOrganism(int j, int i);
	void RandomDirection(Direction& direction);
	~Organism();
};