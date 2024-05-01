#pragma once
#include "DESI.h"
#include "Includes.h"

class Organism;
class Human;

class World {
private:
	int y;
	int x;
	string eventLog;
	list<Organism*> organismList;
	Human* player;
	bool loadFromFile = false;
public:
	Organism*** worldMap;
	World();
	World(int y, int x);
	void PrintMap();
	void MakeTurn(list<Organism*> organismList);
	int GetMaxX();
	int GetMaxY();
	Human* GetPlayer();
	list<Organism*> GetList();
	string GetEventLog();
	void AddOrganism(Organism* organism);
	void RemoveOrganism(Organism* organism);
	void SetEventLog(string log);
	void SetLoadFromFile(bool set);
	void Save();
	void Load();
	~World();
};