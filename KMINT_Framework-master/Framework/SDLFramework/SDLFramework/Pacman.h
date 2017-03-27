#pragma once
#include "Vertex.h"
#include "IGameObject.h"
#include <SDL_render.h>

class Pacman : public IGameObject
{
public:
	Pacman();
	Pacman(double x, double y);
	~Pacman();

	double xPos;
	double yPos;

	double speed;

	Vertex * targetVertex;
	Vertex * nextVertex;

	void Update(float deltaTime);
private:
	SDL_Texture *pacmanTexture;
};

