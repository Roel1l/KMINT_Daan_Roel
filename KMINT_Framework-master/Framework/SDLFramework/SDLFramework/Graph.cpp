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
	delete app;
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

bool Graph::run()
{
	// stop running when there are no more ghosts chasing pacman
	if (ghosts.empty()) {
		return false;
	}

	// pacman move

	for each (auto ghost in ghosts)
	{
		// only find a new target when there is no current target
		if (ghost->targetVertex == NULL) {
			if (ghost->ghostState->currentState == "wandering") {
				ghost->targetVertex = pickRandomNeighbour(getNeighbours(ghost->currentVertex));
			}
			else if (ghost->ghostState->currentState == "searchPill") {
				ghost->targetVertex = aStarClosestPill(ghost->currentVertex);
			}
			else if (ghost->ghostState->currentState == "chasePacman") {
				ghost->targetVertex = aStarSearch(ghost->currentVertex, pacman->currentVertex);
			}
		}
		ghost->move();
	}
	return true;
}

std::vector<Ghost*> Graph::getGhosts()
{
	return ghosts;
}

std::vector<Powerpill*> Graph::getPills()
{
	return pills;
}

std::vector<Vertex*> Graph::getNeighbours(Vertex * vertex)
{
	std::vector<Vertex *> neighbours;
	for each (auto e in edges)
	{
		if (e->vertexA == vertex) {
			neighbours.push_back(e->vertexB);
		}
		else if (e->vertexB == vertex) {
			neighbours.push_back(e->vertexA);
		}
	}
	return neighbours;
}

Vertex * Graph::pickRandomNeighbour(std::vector<Vertex*> neighbours)
{
	int random = 0;
	if (neighbours.size() != 0) {
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> uni(0, neighbours.size() - 1);

		random = uni(rng);
		return neighbours[random];
	}
	return nullptr;
}

Pacman * Graph::getPacman()
{
	return pacman;
}

Vertex * Graph::aStarSearch(Vertex * start, Vertex * goal)
{
	return nullptr;
}

Vertex * Graph::aStarClosestPill(Vertex * start)
{
	//std::priority_queue<Vertex *, double> frontier;
	//frontier.emplace(start, 0);

	//std::unordered_map<Vertex *, Vertex *> came_from;
	//std::unordered_map<Vertex *, double> cost_so_far;

	//came_from[start] = start;
	//cost_so_far[start] = 0;

	//while (!frontier.empty()) {
	//	auto current = frontier.top();
	//	frontier.pop();

	//	for each (auto p in getPills())
	//	{
	//		if (current->x == p->x && current->y == p->y) {
	//			break;
	//		}
	//	}

	//	for (auto next : getNeighbours(current)) {
	//		double new_cost = cost_so_far[current] + getCost(current, next);
	//		if (!cost_so_far.count(next) || new_cost < cost_so_far[next]) {
	//			cost_so_far[next] = new_cost;

	//			//double priority = new_cost + heuristic(next, goal); // <----

	//			//frontier.emplace(next, priority);
	//			came_from[next] = current;
	//		}
	//	}
	//}

	return nullptr;
}

double Graph::heuristic(Vertex * a, Vertex * b)
{
	return abs(a->x - b->x) + abs(a->y - b->y);
}

double Graph::getCost(Vertex * a, Vertex * b)
{
	for each (auto e in edges)
	{
		if (e->vertexA == a && e->vertexB == b) {
			return e->pixelDistance;
		}
		else if (e->vertexA == b && e->vertexB == a) {
			return e->pixelDistance;
		}
		else {
			return 0;
		}
	}
}
