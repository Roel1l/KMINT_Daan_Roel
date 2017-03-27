#pragma once
#include <random>

class State
{
public:
	State();
	~State();

	enum state {
		wandering,
		grabPill,
		chasePacman
	};

	void doStuff();

	void updateState(double wander, double pill, double chase);
private:
	state currentState;
};

