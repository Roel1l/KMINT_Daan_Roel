#pragma once
#include "IGameObject.h"
#include <SDL_render.h>

class Powerpill : public IGameObject
{
public:
	Powerpill();
	Powerpill(double x, double y);
	~Powerpill();

	SDL_Texture *pillTexture;

	double xPos;
	double yPos;

	void Update(float deltaTime);
};

