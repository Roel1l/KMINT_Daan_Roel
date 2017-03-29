#pragma once
#include "Vertex.h"

class Edge
{
public:
	Edge();
	Edge(Vertex * a, Vertex * b);
	~Edge();

	double aX;
	double bX;
	double aY;
	double bY;
	Vertex * vertexA;
	Vertex * vertexB;

	double pixelDistance;
};

