#include "Powerpill.h"

Powerpill::Powerpill()
{
}

Powerpill::Powerpill(double xPos, double yPos)
{
	pillTexture = mApplication->LoadTexture("pill.png");
	this->SetTexture(pillTexture);
	this->SetSize(35, 35);

	x = xPos;
	y = yPos;
}

Powerpill::~Powerpill()
{
	SDL_DestroyTexture(pillTexture);
}

void Powerpill::Update(float deltaTime)
{
	SetOffset(x, y, 0);
}
