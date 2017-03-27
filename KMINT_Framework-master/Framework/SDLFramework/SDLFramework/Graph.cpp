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
	delete pacman;
}

void Graph::addVertex(Vertex * v)
{
	vertexes.push_back(v);
}

void Graph::addEdge(Edge * e)
{
	edges.push_back(e);
}

void Graph::addPill(Powerpill * p)
{
	pills.push_back(p);
}

void Graph::addGhost(Ghost * g)
{
	ghosts.push_back(g);
}

void Graph::addPacman(Pacman * p)
{
	pacman = p;
}

void Graph::drawGraph()
{
	app->SetColor(Color(255, 255, 255, 255));
	for each (auto e in edges)
	{
		app->DrawLine(e->aX, e->aY, e->bX, e->bY);
	}

	for each (auto e in edges)
	{
		app->DrawCircle(e->aX, e->aY, e->bX, e->bY);
	}
}

std::vector<Ghost*> Graph::getGhosts()
{
	return ghosts;
}

std::vector<Powerpill*> Graph::getPills()
{
	return pills;
}

Pacman * Graph::getPacman()
{
	return pacman;
}
