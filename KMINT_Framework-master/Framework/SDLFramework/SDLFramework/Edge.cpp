#include "Edge.h"
#include <iostream>

Edge::Edge()
{
}

Edge::Edge(Vertex * a, Vertex * b)
{
	vertexA = a;
	vertexB = b;
	aX = a->x;
	aY = a->y;
	bX = b->x;
	bY = b->y;
	pixelDistance = abs((aX - bX) + (aY - bY));
}

Edge::~Edge()
{
	delete vertexA;
	delete vertexB;
}
