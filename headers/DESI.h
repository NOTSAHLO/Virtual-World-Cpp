#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include <list>
#include <string>

//ANIMALS
#define WOLF 'W'
#define SHEEP 'S'
#define FOX 'F'
#define TURTLE 'T'
#define ANTYLOPE 'A'
#define HUMAN 'H'

//PLANTS
#define GRASS '#'
#define DANDELION '@' 
#define GUARANA '+' 
#define WOLFBERRIES '-' 
#define PINEBORSCHT '!'

using namespace std;
enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};
struct Position {
	int y;
	int x;
};
