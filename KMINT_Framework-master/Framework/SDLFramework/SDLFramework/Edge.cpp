#include "Edge.h"

Edge::Edge()
{
}

Edge::Edge(Vertex * a, Vertex * b)
{
	aX = a->x;
	aY = a->y;
	bX = b->x;
	bY = b->y;
}

Edge::~Edge()
{
}
