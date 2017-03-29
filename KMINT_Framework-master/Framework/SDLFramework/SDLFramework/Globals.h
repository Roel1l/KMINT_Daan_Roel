#pragma once

//Behaviour
const bool STAY_NEAR_OTHERS = true;
const double STICK_RADIUS = 100;
const double STICK_INTENSITY = 0.01;

const bool AVOID_COLLISION = true;
const double COLLISION_RADIUS = 40;
const double COLLISION_INTENSITY = 1;

const bool MIMIC_DIRECTION = true;
const double MIMIC_RADIUS = 100;
const double MIMIC_INTENSITY = 0.1;

const bool RANDOM_STEERING = true;
const bool STEER_INTENSITY = 0.1;

//
const bool RANDOM_SPAWN = true;
const double SPEED = 1;
const int AMOUNT_OF_BIRDS = 30;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGTH = 600;

// ghost en pacman specifieke globals
const double PACMAN_BASE_SPEED = 3;