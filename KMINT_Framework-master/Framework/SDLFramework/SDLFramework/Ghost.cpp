#include "Ghost.h"

Ghost::Ghost()
{
}

Ghost::Ghost(double x, double y)
{
	ghostTexture = mApplication->LoadTexture("ghost_idle.png");
	this->SetTexture(ghostTexture);
	this->SetSize(35, 35);

	xPos = x;
	yPos = y;
}

Ghost::~Ghost()
{
	SDL_DestroyTexture(ghostTexture);
}

void Ghost::Update(float deltaTime)
{
}
