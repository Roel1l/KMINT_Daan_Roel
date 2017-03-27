#include "State.h"

State::State()
{
}


State::~State()
{
}

void State::doStuff()
{
	switch (currentState)
	{
	case wandering:
		break;
	case grabPill:
		break;
	case chasePacman:
		break;
	default:
		break;
	}
}

void State::updateState(double wander, double pill, double chase)
{
	double low = 0;
	double up = 100;

	std::uniform_real_distribution<double> unif(low, up);
	std::default_random_engine re;
	double randomNumber = unif(re);

	if (randomNumber <= wander) {
		currentState = wandering;
	}
	else if (randomNumber > wander && randomNumber <= wander + pill) {
		currentState = grabPill;
	}
	else if (randomNumber > wander + pill) {
		currentState = chasePacman;
	}
}

