#pragma once
#include "DESI.h"
#include "Includes.h"

int main() {
	srand(time(NULL));
	World* Earth = new World(24, 36);
	Earth->PrintMap();
	while (Earth->GetPlayer()->GetAlive()) {
		Earth->MakeTurn(Earth->GetList());
	}
	delete Earth;
	cout << "Game Over!" << endl;
}