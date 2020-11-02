#pragma once
#include "Object.h"
class Bird : public Object
{

public:
	Bird();
	void addPoint();
	int getPoints();
	void stop();
	void jump();
	void update();
	void init();
private: 
	ALLEGRO_BITMAP* image1;
	ALLEGRO_BITMAP* image2;
	int punkty;

	void switchFrame();
};

