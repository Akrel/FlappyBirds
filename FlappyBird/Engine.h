#pragma once
#include <allegro5/display.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#ifndef ENGINE_H
#define ENGINE_H


class Engine
{
public:
	static Engine* getInstane(int mouse, int keyboard);
private:
	ALLEGRO_DISPLAY* display;
	Engine();
	~Engine();
	static Engine* instance;

public:


void setDisplay(int = 0);
 
void setDisplay(int width,int height, int = 0);


ALLEGRO_DISPLAY* getDisplay();


private:
	Engine(int mouse, int keyboard);


};




#endif // !ENGINE_H
