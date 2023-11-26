#include "Player2.h"


void Player2::initVariables()
{
	shape.setSize(sf::Vector2f(30.f, 200.f));

	position = sf::Vector2f(1520.f, 450 - shape.getSize().y / 2.f);

	shape.setPosition(position);
	shape.setFillColor(sf::Color::Blue);

	velocity = 10.f;

}

Player2::Player2()
{
	initVariables();
}

Player2::~Player2()
{

}

void Player2::resetVelocity()
{
	velocity = 0.f;
}

const sf::FloatRect Player2::getPlayerBounds() const
{
	return shape.getGlobalBounds();
}

const sf::Vector2f Player2::getPosition() const
{
	return position;
}

void Player2::setPosition(float x, float y)
{
	shape.setPosition(x, y);
}

void Player2::setVelocity(float vel)
{
	velocity = vel;
}


void Player2::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		position.y -= velocity;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		position.y += velocity;
	}

	shape.setPosition(position);
}


void Player2::update()
{
	updateMovement();
}


void Player2::render(sf::RenderTarget& target)
{

	target.draw(shape);
}

