#include "Player.h"

void Player::initVariables()
{
	shape.setSize(sf::Vector2f(30.f, 200.f));
	
	position = sf::Vector2f(50.f, 450 - shape.getSize().y / 2.f);

	shape.setPosition(position);
	shape.setFillColor(sf::Color::Green);

	velocity = 10.f;

}

Player::Player()
{
	initVariables();
}

Player::~Player()
{

}

void Player::resetVelocity()
{
	velocity = 0.f;
}

const sf::FloatRect Player::getPlayerBounds() const
{
	return shape.getGlobalBounds();
}

const sf::Vector2f Player::getPosition() const
{
	return position;
}

void Player::setPosition(float x, float y)
{
	shape.setPosition(x, y);
}

void Player::setVelocity(float vel)
{
	velocity = vel;
}


void Player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		position.y -= velocity;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		position.y += velocity;
	}

	shape.setPosition(position);
}


void Player::update()
{
	updateMovement();
}


void Player::render(sf::RenderTarget& target)
{
	
	target.draw(shape);
}

