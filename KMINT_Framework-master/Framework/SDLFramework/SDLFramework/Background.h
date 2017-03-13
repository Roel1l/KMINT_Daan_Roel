#pragma once
#include "IGameObject.h"
#include <SDL_render.h>

class Background : public IGameObject
{
public:

	Background();
	~Background();
	void Update(float deltaTime);
private:
	SDL_Texture *backgroundTexture;
};

