#include "Background.h"



Background::Background()
{
	backgroundTexture = mApplication->LoadTexture("background.png");
	this->SetTexture(backgroundTexture);
	this->SetSize(1200, 600);
	this->SetOffset(600, 300, 0);
}

Background::~Background()
{
	SDL_DestroyTexture(backgroundTexture);
}

void Background::Update(float deltaTime)
{
}
