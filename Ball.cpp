#include "Ball.h"

void Ball::initBall()
{
	ball.setRadius(20.f);
	ball.setFillColor(sf::Color::Yellow);
	float x = 800.f - ball.getRadius();
	float y = 450.f - ball.getRadius();

	ball.setPosition(x, y);
}

Ball::Ball()
{
	initBall();
}

Ball::~Ball()
{

}

void Ball::update()
{

}

void Ball::render(sf::RenderTarget& target)
{
	target.draw(ball);
}
