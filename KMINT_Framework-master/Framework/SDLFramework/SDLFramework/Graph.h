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
	bool run();

	// return functies
	std::vector<Ghost *> getGhosts();
	std::vector<Powerpill *> getPills();
	std::vector<Vertex *> getNeighbours(Vertex * vertex);
	Vertex * pickRandomNeighbour(std::vector<Vertex *> neighbours);
	Pacman * getPacman();
private:
	std::vector<Vertex *> vertexes;
	std::vector<Edge *> edges;
	std::vector<Ghost *> ghosts;
	std::vector<Powerpill *> pills;
	
	Pacman * pacman;

	FWApplication * app;

	Vertex * aStarSearch(Vertex * start, Vertex * goal);
};

