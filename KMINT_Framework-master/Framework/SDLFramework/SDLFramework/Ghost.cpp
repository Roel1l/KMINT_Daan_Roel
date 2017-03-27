#include "Ghost.h"

Ghost::Ghost()
{
}

Ghost::Ghost(double xPos, double yPos)
{
	ghostTexture = mApplication->LoadTexture("ghost_idle.png");
	SetTexture(ghostTexture);
	SetSize(35, 35);

	x = xPos;
	y = yPos;
	ghostState = new State();
	
	// random speed
	double low1 = PACMAN_BASE_SPEED;
	double up1 = PACMAN_BASE_SPEED + 2;

	std::uniform_real_distribution<double> unif1(low1, up1);
	std::default_random_engine re1;
	speed = unif1(re1);

	// random speedModifier
	double low2 = 1;
	double up2 = 3;

	std::uniform_real_distribution<double> unif2(low2, up2);
	std::default_random_engine re2;
	speedModifier = unif2(re2);

	// random wandering time
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(2, 10);

	wanderingTime = uni(rng);
}

Ghost::~Ghost()
{
	SDL_DestroyTexture(ghostTexture);
	delete ghostState;
}

void Ghost::increaseSpeed()
{
	speed = speed * speedModifier;
}

void Ghost::Update(float deltaTime)
{
	ghostState->updateState(WANDER_CHANCE, PILL_CHANCE, CHASE_CHANCE);

	SetOffset(x, y, 0);
}
