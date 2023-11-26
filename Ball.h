#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <time.h>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "Player2.h"

class Ball
{

private:
	sf::CircleShape ball;

	void initBall();
public:

	Ball();
	~Ball();

	void update();
	void render(sf::RenderTarget& target);
};

