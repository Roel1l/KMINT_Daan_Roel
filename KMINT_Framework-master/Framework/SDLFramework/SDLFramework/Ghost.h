#pragma once
#include "Vertex.h"
#include "IGameObject.h"
#include <SDL_render.h>

class Ghost : public IGameObject
{
public:
	Ghost();
	Ghost(double x, double y);
	~Ghost();

	double xPos;
	double yPos;

	SDL_Texture *ghostTexture;

	Vertex * targetVertex;
	Vertex * nextVertex;

	void Update(float deltaTime);
};

