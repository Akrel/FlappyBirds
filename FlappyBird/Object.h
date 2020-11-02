#pragma once

#include <allegro5/allegro.h>
#include <cmath>

class Object 
{
public:
	int getWidth();
	int getHeight();
	int getX();
	int getY();

	bool collsion(const Object&) const;

	virtual void init();
	virtual void update();
	
	virtual void render();

	Object();
	virtual ~Object();

protected:

	float timer;
	float posX, posY;
	float aX, aY;
	int width, height;
	int degreeRotation;
	float scaleX;
	float scaleY;
	float velX, velY;
	ALLEGRO_BITMAP* bitmapa;

	int ID;


};

