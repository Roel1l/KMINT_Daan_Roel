#pragma once
#include <vector>
#include "Edge.h"
#include "Vertex.h"
#include "FWApplication.h"

class Graph
{
public:
	Graph();
	Graph(FWApplication * fwapplication);
	~Graph();

	void addVertex(Vertex * v);
	void addEdge(Edge * e);

	void drawGraph();
private:
	std::vector<Vertex*> vertexes;
	std::vector<Edge*> edges;

	FWApplication * app;
};

