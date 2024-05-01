#pragma once
#include "DESI.h"
#include "Includes.h"

Plant::Plant(){}
void Plant::Action() {
	string tmp = "";
	if (GetAlive() == true) {
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
				if (GetSign() == GRASS)
					Grass* seed = new Grass(GetWorld(), GetPosY() + j, GetPosX() + i);
				else if (GetSign() == GUARANA)
					Guarana* seed = new Guarana(GetWorld(), GetPosY() + j, GetPosX() + i);
				tmp += GetSign();
				tmp += " spreads";
				tmp += '\n';
				GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
			}
		}
	}
}
void Plant::Collision(Organism* other, int j, int i) {
	string tmp = "";
	tmp += other->GetSign();
	tmp += " ate ";
	tmp += GetSign();
	tmp += '\n';
	GetWorld()->SetEventLog(GetWorld()->GetEventLog() + tmp);
	GetWorld()->RemoveOrganism(this);
	other->MoveOrganism(j, i);
}
const void Plant::Print() {
	cout << this->GetSign();
}
Plant::~Plant(){}