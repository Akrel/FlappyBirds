#include "Engine.h"


Engine* Engine::instance = NULL;



Engine* Engine::getInstane(int mouse,int keyboard)
{
	if (instance == NULL)
		instance = new Engine(mouse,keyboard);

	return instance;
}



void Engine::setDisplay(int fullscreen)
{
	
	if (fullscreen != 1)
		return;

	ALLEGRO_MONITOR_INFO info;


	al_get_monitor_info(0, &info);
	
	int w = info.x2 - info.x1;
	int h = info.y2 - info.y1;
	
	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	
	display = al_create_display(w, h);
	
	al_set_window_title(display, "Flappy_Bird");
}

void Engine::setDisplay(int width, int height, int fullscreen)
{
	if (fullscreen != 0)
		return;
	al_set_new_display_flags(ALLEGRO_WINDOWED);

	display = al_create_display(width, height);
	al_set_window_title(display, "Flappy_Bird");
}



/*Konstruktor */
Engine::Engine(int mouse, int keyboard)
{
	al_init();

	if (mouse != 0)
		al_install_mouse();

	if (mouse != 0)
		al_install_keyboard();
}
ALLEGRO_DISPLAY* Engine::getDisplay() {
	return display;
}
;








