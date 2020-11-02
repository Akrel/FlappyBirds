#include "Bird.h"

void Bird::update()
{
	Object::update();
	if (velX < 0 && degreeRotation > -45.0) 
		degreeRotation -= 1.0;
	if (velY > 0 && degreeRotation < 45.0)
		degreeRotation += 1.0;
	const float delay = 0.1;
	static float frameSwitch = al_current_time();
	if (al_current_time() - frameSwitch >= delay)
	{
		frameSwitch = al_current_time();
		switchFrame();
	}
}

void Bird::init()
{
	scaleX = scaleY = 0.07;



	Object::init();
	posX = 800 / 2 - width / 2;
	posY = 1200 / 2 - height / 2;
}

void Bird::addPoint()
{
	this->punkty+=1;
}

int Bird::getPoints()
{
	return this->punkty;
}

void Bird::stop()
{
	velY = 0;
	aY = 0;
	velX = 0;
	aX = 0;
}

void Bird::jump()
{
	velY = -500;
	aY = 1200;
}

void Bird::switchFrame()
{
	bitmapa = (bitmapa == image1) ? image1 : image2;
}
