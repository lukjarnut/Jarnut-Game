#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void onColiision(sf::Vector2f direction);
	void foundKey(bool red, bool green, bool blue);

	Collider GetCollider()
	{
		return Collider(body);
	}
public:
	bool inAir;
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRigth;
	sf::Vector2f velocity;
	sf::Vector2f position = body.getPosition();
	bool canJump;
	float jumpHeight;
	bool redKey;
	bool blueKey;
	bool greenKey;
};

