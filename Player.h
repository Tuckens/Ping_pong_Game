#pragma once
#include "Ball.h"

class Player
{
private:

	float velocity;

	sf::RectangleShape shape;
	sf::Vector2f position;


	void initVariables();
public:

	Player();
	~Player();

	const sf::FloatRect getPlayerBounds() const;
	const sf::Vector2f getPosition() const;

	void setPosition(float x, float y);
	void setVelocity(float vel);


	void resetVelocity();
	void updateMovement();
	void update();
	void render(sf::RenderTarget& target);
};

