#pragma once
#include "Vertex.h"
#include "IGameObject.h"
#include <SDL_render.h>
#include <random>
#include "State.h"

class Ghost : public IGameObject
{
public:
	Ghost();
	Ghost(double xPos, double yPos);
	~Ghost();

	double x;
	double y;

	Vertex * targetVertex;
	Vertex * nextVertex;

	void increaseSpeed();
	void Update(float deltaTime);
private:
	SDL_Texture *ghostTexture;
	int wanderingTime;
	double speed;
	double speedModifier;
	State *ghostState;
};

