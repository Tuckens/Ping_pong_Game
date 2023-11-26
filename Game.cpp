#include "Game.h"

void Game::initBall()
{
	ball = new Ball();
}

void Game::initPlayer()
{
	player = new Player();
	player2 = new Player2();
}

void Game::initWindow()
{
	window.create(sf::VideoMode(1600, 900), "Game", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);

}

void Game::initVariables()
{
	//
}

Game::Game()
{
	initWindow();
	initPlayer();
	initBall();
}

Game::~Game()
{
	delete player;
	delete ball;
}

void Game::updatePlayer()
{
	player->update();
	player2->update();
}

void Game::updateBall()
{
	ball->update();
}

void Game::updateCollision()
{
	if (player->getPosition().y + player->getPlayerBounds().height >= window.getSize().y) {
		player->resetVelocity();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			player->setVelocity(10.f);
		}

	}

	if (player->getPosition().y <= 0) {
		player->resetVelocity();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			player->setVelocity(10.f);
		}

	}

	if (player2->getPosition().y + player2->getPlayerBounds().height >= window.getSize().y) {
		player2->resetVelocity();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			player2->setVelocity(10.f);
		}

	}

	if (player2->getPosition().y <= 0) {
		player2->resetVelocity();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			player2->setVelocity(10.f);
		}

	}
}

void Game::update()
{
	while (window.pollEvent(ev)) {
		if (ev.type == sf::Event::Closed) {
			window.close();
		}
		else if (sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape) {
			window.close();
		}
	}

	updatePlayer();
	updateCollision();
}

void Game::renderBall()
{
	ball->render(window);
}

void Game::renderPlayer()
{
	player->render(window);
	player2->render(window);
}

void Game::render()
{
	window.clear();


	renderPlayer();
	renderBall();
	

	window.display();
}

const sf::RenderWindow& Game::getWindow() const
{
	return window;
}
