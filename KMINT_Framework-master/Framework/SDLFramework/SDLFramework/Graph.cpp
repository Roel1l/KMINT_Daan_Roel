#include "Graph.h"

Graph::Graph()
{
}

Graph::Graph(FWApplication * fwapplication)
{
	app = fwapplication;
}


Graph::~Graph()
{
	
}

void Graph::addVertex(Vertex * v)
{
	vertexes.push_back(v);
}

void Graph::addEdge(Edge * e)
{
	edges.push_back(e);
}

void Graph::drawGraph()
{
	for each (auto e in edges)
	{
		app->SetColor(Color(255, 255, 255, 255));
		app->DrawLine(e->aX, e->aY, e->bX, e->bY);
	}
}
