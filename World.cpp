#pragma once
#include "DESI.h"
#include "Includes.h"

World::World() {}
World::World(int y, int x) {
	this->y = y;
	this->x = x;
	this->eventLog = "";
	this->worldMap = new Organism * *[this->y];
	for (int i = 0; i < this->y; i++) {
		worldMap[i] = new Organism * [this->x];
	}
	for (int i = 0; i < this->y; i++) {
		for (int j = 0; j < this->x; j++) {
			worldMap[i][j] = nullptr;
		}
	}
	this->player = new Human(this, 0, 0);
	Wolf* Wolfie = new Wolf(this, 12, 12);
	Wolf* WoofWoof = new Wolf(this, 23, 24);
	Sheep* Betty = new Sheep(this, 16, 16);
	Sheep* BeepBoop = new Sheep(this, 5, 5);
	Fox* Foxy = new Fox(this, 0, 35);
	Turtle* Franklin = new Turtle(this, 23, 35);
	Turtle* Johnny = new Turtle(this, 19, 6);
	Turtle* MichaelAngello = new Turtle(this, 21, 6);
	Antylope* Bubba = new Antylope(this, 19, 35);
	Antylope* Anton = new Antylope(this, 20, 31);
	Antylope* Anta = new Antylope(this, 12, 24);
	Grass* grassy = new Grass(this, 14, 2);
	Dandelion* Jaskier = new Dandelion(this, 15, 15);
	Guarana* baklazana = new Guarana(this, 17, 17);
	Guarana* maniana = new Guarana(this, 21, 33);
	Guarana* iguana = new Guarana(this, 6, 9);
	WolfBerries* silent = new WolfBerries(this, 20, 12);
	PineBorscht* killer = new PineBorscht(this, 3, 3);
}
void World::PrintMap() {
	cout << "World simulator made by Lukasz Prahl, s184340 " << endl;
	cout << "Use WSAD to steer Human, press Q to activate it's power, T to save the game or Y to load game from file." << endl;
	for (int i = 0; i < this->y; i++) {
		for (int j = 0; j < this->x; j++) {
			if (worldMap[i][j] != nullptr) {
				worldMap[i][j]->Print();
				cout << " ";
			}
			else {
				cout << ". ";
			}
		}
		cout << endl;
	}
	// PRINTING EVENTS THAT HAPPENED DURING LAST TURN
	cout << this->GetEventLog();
	this->SetEventLog("");
}
void World::MakeTurn(list<Organism*> organismList) {
	this->player->Steer(); // DECIDING HUMAN'S ACTION
	system("cls");
	if (loadFromFile == false) {
		for (auto tmpOrganism : organismList) {
			tmpOrganism->Action();
		}
	}
	else {
		this->Load();
		loadFromFile = false;
	}
	this->PrintMap();
}
int World::GetMaxX() {
	return this->x - 1;
}
int World::GetMaxY() {
	return this->y - 1;
}
Human* World::GetPlayer() {
	return this->player;
}
list<Organism*> World::GetList() {
	return this->organismList;
}
string World::GetEventLog() {
	return this->eventLog;
}
void World::AddOrganism(Organism* organism) {
	this->worldMap[organism->GetPosY()][organism->GetPosX()] = organism;
	if (organismList.size() == 0) {
		organismList.push_front(organism);
	}
	else {
		for (auto tmpOrganism : organismList) {
			if (organism->GetInitiative() > tmpOrganism->GetInitiative()) {
				auto position = find(organismList.begin(), organismList.end(), tmpOrganism);
				organismList.insert(position, organism);
				return;
			}
			else {
				continue;
			}
		}
		organismList.push_back(organism);
	}
}
void World::RemoveOrganism(Organism* organism) {
	organismList.remove(organism);
	organism->SetAlive(false);
	worldMap[organism->GetPosY()][organism->GetPosX()] = nullptr;
}
void World::SetEventLog(string log) {
	eventLog = log;
}
void World::SetLoadFromFile(bool set) {
	loadFromFile = set;
}
void World::Save() {
	fstream file;
	system("cls");
	cout << "Enter file name: ";
	string name; 
	cin >> name;
	file.open(name, fstream::out);
	file << y << " " << x << " " << organismList.size() << endl;
	for (auto temp : organismList) {
		file << temp->GetSign() << " ";
		file << temp->GetPosY() << " " << temp->GetPosX() << " ";
		file << temp->GetStrength() << " " << temp->GetAge() << " " << endl;
	}
	file.close();
	cout << "Game state saved to file: " << name << endl;
	cout << "Press any button to continue playing." << endl;
	char anything;
	anything = _getch();
}
void World::Load() {
	char anything;
	string name;
	system("cls");
	cout << "Enter file name: ";
	cin >> name;
	fstream file;
	file.open(name, fstream::in);
	if (!file.good()) {
		cout << "File with that name does not exist. " << endl;
		cout << "Press any button to continue playing." << endl;
		anything = _getch();
	}
	else {
		// clearing the world map
		//for (auto tmpOrganism : organismList) {
		//	tmpOrganism->SetAlive(false); // SO THE ORGANISMS DONT MOVE AND CREATE GHOST SIGNS ON MAP
		//}
		// DELETING ALL POINTERS FROM THE MAP
		for (int i = 0; i < this->y; i++) {
			for (int j = 0; j < this->x; j++) {
				worldMap[i][j] = nullptr;
			}
		}
		for (int i = 0; i < this->y; i++) {
			delete[] this->worldMap[i];
		}
		delete[] this->worldMap;
		//clearing the organism list
		organismList.clear();
		int worldY;
		int worldX;
		int organismAmount;
		char sign;
		int y;
		int x;
		int strength;
		int age;
		file >> worldY >> worldX >> organismAmount; // FIRST 3 VALUES FROM FILE ARE RELATED TO WORLD'S INFO, REST IS ORGANISMS
		this->y = worldY;
		this->x = worldX;
		this->worldMap = new Organism * *[this->y];
		for (int i = 0; i < this->y; i++) {
			worldMap[i] = new Organism * [this->x];
		}
		for (int i = 0; i < this->y; i++) {
			for (int j = 0; j < this->x; j++) {
				worldMap[i][j] = nullptr;
			}
		}
		for (int i = 0; i < organismAmount; i++) {
			file >> sign >> y >> x >> strength >> age;
			if (sign == HUMAN) {
				this->player = new Human(this, y, x, strength, age);
			}
			else if (sign == SHEEP) {
				Sheep* newborn = new Sheep(this, y, x, strength, age);
			}
			else if (sign == WOLF) {
				Wolf* newborn = new Wolf(this, y, x, strength, age);
			}
			else if (sign == FOX) {
				Fox* newborn = new Fox(this, y, x, strength, age);
			}
			else if (sign == TURTLE) {
				Turtle* newborn = new Turtle(this, y, x, strength, age);
			}
			else if (sign == ANTYLOPE) {
				Antylope* newborn = new Antylope(this, y, x, strength, age);
			}
			else if (sign == GRASS) {
				Grass* newborn = new Grass(this, y, x, strength, age);
			}
			else if (sign == DANDELION) {
				Dandelion* newborn = new Dandelion(this, y, x, strength, age);
			}
			else if (sign == GUARANA) {
				Guarana* newborn = new Guarana(this, y, x, strength, age);
			}
			else if (sign == WOLFBERRIES) {
				WolfBerries* newborn = new WolfBerries(this, y, x, strength, age);
			}
			else if (sign == PINEBORSCHT) {
				PineBorscht* newborn = new PineBorscht(this, y, x, strength, age);
			}
		}
		file.close();
		cout << "Game successfully loaded from file: " << name << endl;
		cout << "Press any button to continue playing game from file." << endl;
		anything = _getch();
	}
}
void World::ClearList() {
	for (auto& tmpOrganism : organismList) {
		delete tmpOrganism;
	}
}
World::~World(){}