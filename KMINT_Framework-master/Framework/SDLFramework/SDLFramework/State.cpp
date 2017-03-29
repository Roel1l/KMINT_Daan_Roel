#include "State.h"

State::State()
{
}


State::~State()
{
}

std::string State::updateState(double wander, double pill, double chase)
{
	double low = 0;
	double up = 100;

	std::random_device rd;
	std::mt19937 rng(rd());

	std::uniform_real_distribution<double> unif(low, up);
	double randomNumber = unif(rng);
	 
	if (randomNumber <= wander) {
		return "wandering";
	}
	else if (randomNumber > wander && randomNumber <= wander + pill) {
		return "grabPill";
	}
	else if (randomNumber > wander + pill) {
		return "chasePacman";
	}
}

