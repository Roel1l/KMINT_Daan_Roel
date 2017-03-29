#pragma once
#include "IGameObject.h"
#include <SDL_render.h>

class Powerpill : public IGameObject
{
public:
	Powerpill();
	Powerpill(double xPos, double yPos);
	~Powerpill();

	double x;
	double y;

	void Update(float deltaTime);
private:
	SDL_Texture *pillTexture;
};

