#include "Ghost.h"

Ghost::Ghost()
{
}

Ghost::Ghost(Vertex * v, double wanderChance, double searchPillChance, double chaseChance)
{
	ghostTextureIdle = mApplication->LoadTexture("ghost_idle.png");
	ghostTexturePill = mApplication->LoadTexture("ghost_chase_powerpill.png");
	ghostTextureChase = mApplication->LoadTexture("ghost_chase_packman.png");

	SetTexture(ghostTextureIdle);
	SetSize(35, 35);

	wandering = wanderChance;
	searchPill = searchPillChance;
	chase = chaseChance;

	currentVertex = v;

	x = v->x;
	y = v->y;
	ghostState = new State();

	// random speed
	std::random_device rd;
	std::mt19937 rng(rd());

	double low1 = PACMAN_BASE_SPEED;
	double up1 = PACMAN_BASE_SPEED + 2;

	std::uniform_real_distribution<double> unif1(low1, up1);
	speed = unif1(rng);

	// random speedModifier
	double low2 = 1;
	double up2 = 3;

	std::uniform_real_distribution<double> unif2(low2, up2);
	speedModifier = unif2(rng);

	// random wandering time
	std::uniform_int_distribution<int> uni(2, 10);

	wanderingTime = uni(rng);
}

Ghost::~Ghost()
{
	SDL_DestroyTexture(ghostTextureIdle);
	SDL_DestroyTexture(ghostTexturePill);
	SDL_DestroyTexture(ghostTextureChase);
	delete ghostState;
	delete currentVertex;
	delete targetVertex;
}

void Ghost::move()
{
	// x - movement
	if (x < targetVertex->x) {
		if (x + speed > targetVertex->x) {
			x = targetVertex->x;
		}
		else {
			x = x + speed;
		}
	}
	else if (x > targetVertex->x) {
		if (x - speed < targetVertex->x) {
			x = targetVertex->x;
		}
		else {
			x = x - speed;
		}
	}

	// y - movement
	if (y < targetVertex->y) {
		if (y + speed > targetVertex->y) {
			y = targetVertex->y;
		}
		else {
			y = y + speed;
		}
	}
	else if (y > targetVertex->y) {
		if (y - speed < targetVertex->y) {
			y = targetVertex->y;
		}
		else {
			y = y - speed;
		}
	}

	// target reached
	if (x == targetVertex->x && y == targetVertex->y) {
		currentVertex == targetVertex;
		targetVertex == NULL;
	}
}

void Ghost::increaseSpeed()
{
	speed = speed * speedModifier;
}

void Ghost::Update(float deltaTime)
{
	SetOffset(x, y, 0);
	ghostState->updateState(wandering, searchPill, chase);

	// verander ghosts van kleur
	/*if (ghostState->currentState == "wandering" && GetTexture() != ghostTextureIdle) {
		SetTexture(ghostTextureIdle);
		SetSize(35, 35);
	} else 	if (ghostState->currentState == "grabPill") {
		SetTexture(ghostTexturePill);
		SetSize(35, 35);
	}*/
}

