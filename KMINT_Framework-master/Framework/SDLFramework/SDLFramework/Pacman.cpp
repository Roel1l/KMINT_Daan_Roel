#include "Pacman.h"

Pacman::Pacman()
{
}

Pacman::Pacman(double x, double y)
{
	pacmanTexture = mApplication->LoadTexture("pacman.png");
	SetTexture(pacmanTexture);
	SetSize(35, 35);

	xPos = x;
	yPos = y;
	speed = PACMAN_BASE_SPEED;
}

Pacman::~Pacman()
{
	SDL_DestroyTexture(pacmanTexture);
}

void Pacman::Update(float deltaTime)
{
	SetOffset(xPos, yPos, 0);
}
