#ifndef ASTEROIDS_CONFIG_H_
#define ASTEROIDS_CONFIG_H_

#pragma warning (disable : 4305)
#pragma warning (disable: 4244)

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 700;

const int FRAMES_PER_SECOND = 60;

const int PLAYER_ROTATION_AMOUNT = 8;
const float PLAYER_MAX_SPEED = 10.0f;
const int PLAYER_FIRE_DELAY = 300;
const float PLAYER_DRAG = 0.975;

const int BULLET_SPEED = 20.0f;
const unsigned int BULLET_FLIGHT_TIME = 500;

enum ASTEROID_SIZE { LARGE = 1, MEDIUM, SMALL };
const unsigned int ASTEROID_BASE_SPEED = 2;
const unsigned int ASTEROID_BASE_RADIUS = 30;

#endif
