#pragma once
#include "Vertex.h"

class Pacman
{
public:
	Pacman();
	Pacman(double x, double y);
	~Pacman();

	double xPos;
	double yPos;

	Vertex * targetVertex;
	Vertex * nextVertex;
};

