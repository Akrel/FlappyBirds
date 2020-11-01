#include "PositionMenu.h"



PositionMenu::PositionMenu(string* text)
{
	this->text = text;


	if (text)
	{
		default;
	}

}

void PositionMenu::myDefault()
{

}

void default() {
	text->setColor(dr, dg, db);
}
