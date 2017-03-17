#include "Powerpill.h"

Powerpill::Powerpill()
{
}

Powerpill::Powerpill(double x, double y)
{
	pillTexture = mApplication->LoadTexture("pill.png");
	this->SetTexture(pillTexture);
	this->SetSize(35, 35);

	xPos = x;
	yPos = y;
}

Powerpill::~Powerpill()
{
	SDL_DestroyTexture(pillTexture);
}

void Powerpill::Update(float deltaTime)
{
}
