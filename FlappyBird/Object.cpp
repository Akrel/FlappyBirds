#include "Object.h"



Object::Object() {
	posX = 0.0;  //pozycja obiektu x na mapie
	posY = 0.0; //pozycja obiektu y na mapie
 	velX = velY = 0.0; //predkosc 
	width = height = 0; //wysokosc oraz szerokosc obiektu
	degreeRotation = 0; //kat rotacji 
	scaleX = scaleY = 0; // skala 
	aX = aY = 0.0;
	ID = -1;
	bitmapa = NULL;  //
	timer = al_current_time();
}


/*
* Getter do pobrania wartosci X obeiktu 
*/
int Object::getX(){
	return this->posX;
}


/*
* Getter do pobrania watoœci Y obiektu
*/
int Object::getY() {
	return this->posY;
}


/*
* Getter do pobrania szerokosci obiektu
*/
int Object::getWidth() {
	return this->width;
}


/*
* Getter wysokosci obiektu
*/
int Object::getHeight()
{
	return this->height;
}

/*
* Metoda do renederowania obiektu
*/
void Object::render()
{
	//al_draw_scaled_rotated_bitmap(this->bitmap, 0, 0, posX, posY, scaleX, scaleY, (degreeRotation * 3, 14) / 180, 0);
}


/*
* Wykrywanie kolizji
*/
bool Object::collsion(const Object& obiekt) const {
	if ((posX < obiekt.posX + obiekt.width) && (posX + width) > obiekt.posX) // jesli pozycja X jest mniejsza/mniejsza od obiektu pozycja X 
		if (posY < (obiekt.posY + obiekt.height) && ((posY + height) > obiekt.posY)) // jesli pozycjaY jest mniejsza/mniejsza od obiektu pozycja Y 
			return true;
	return false;

}

/*
* Aktualizacja obiektu na mapie
*/
void Object::update()
{
	//aktualizacja predkosc
	float currentTime = al_current_time();
	velX += aX*(currentTime - timer);
	velY += aY * (currentTime - timer);
	
	//aktualizacja pozycji na mapie 
	posX += velX * (currentTime - timer);
	posY += velY * (currentTime - timer);

	timer = currentTime;
}

/*
* Inizcjalizacja bitmapy
*/
void Object::init() {
	width = al_get_bitmap_width(bitmapa) * scaleX;
	height = al_get_bitmap_height(bitmapa) * scaleY;
}




Object::~Object()
{

}