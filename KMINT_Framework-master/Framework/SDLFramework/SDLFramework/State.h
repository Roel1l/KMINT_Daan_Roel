#pragma once
#include <random>

class State
{
public:
	State();
	~State();

	std::string currentState;

	std::string updateState(double wander, double pill, double chase);
private:
};

