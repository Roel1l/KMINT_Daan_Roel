#pragma once
#include <vector>
#include "Edge.h"
#include "Vertex.h"
#include "Powerpill.h"
#include "Ghost.h"
#include "Pacman.h"
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
	void addPacman(Pacman * p);
	void drawGraph();

	// return functies
	std::vector<Ghost *> getGhosts();
	std::vector<Powerpill *> getPills();
	Pacman * getPacman();
private:
	std::vector<Vertex *> vertexes;
	std::vector<Edge *> edges;
	std::vector<Ghost *> ghosts;
	std::vector<Powerpill *> pills;
	
	Pacman * pacman;

	FWApplication * app;
};

