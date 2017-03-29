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
	Ghost(Vertex * v, double wanderChance, double searchPillChance, double chaseChance);
	~Ghost();

	double x;
	double y;

	Vertex * targetVertex;
	Vertex * currentVertex;

	void move();

	void increaseSpeed();
	void Update(float deltaTime);

	State *ghostState;
private:
	// chances
	double wandering;
	double searchPill;
	double chase;

	SDL_Texture *ghostTextureIdle;
	SDL_Texture *ghostTexturePill;
	SDL_Texture *ghostTextureChase;

	int wanderingTime;
	double speed;
	double speedModifier;
};

