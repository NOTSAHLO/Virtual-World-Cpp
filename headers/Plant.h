#pragma once
#include "DESI.h"
#include "Includes.h"

class Plant : public Organism {
public:
	Plant();
	void Action() override;
	void Collision(Organism* other, int j, int i) override;
	const void Print() override;
	~Plant();
};