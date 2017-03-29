#pragma once
#include <vector>
#include "Edge.h"
#include "Vertex.h"
#include "Powerpill.h"
#include "Ghost.h"
#include "FWApplication.h"

class Graph
{
public:
	Graph();
	Graph(FWApplication * fwapplication);
	~Graph();

	void addVertex(Vertex * v);
	void addEdge(Edge * e);
	void addPill(Powerpill * p);
	void addGhost(Ghost * g);
	void drawGraph();

	// return functies
	std::vector<Ghost *> getGhosts();
	std::vector<Powerpill *> getPills();
private:
	std::vector<Vertex *> vertexes;
	std::vector<Edge *> edges;
	std::vector<Ghost *> ghosts;
	std::vector<Powerpill *> pills;

	FWApplication * app;
};

