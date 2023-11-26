#pragma once
#include "Player.h"


class Game
{
private:
	sf::RenderWindow window;
	sf::Event ev;
	


	Player* player;
	Player2* player2;
	Ball* ball;

	void initBall();
	void initPlayer();
	void initWindow();
	void initVariables();

public:
	Game();
	~Game();
	
	void updatePlayer();
	void updateBall();
	void updateCollision();

	void update();

	void renderBall();
	void renderPlayer();
	void render();

	const sf::RenderWindow& getWindow() const;
};

