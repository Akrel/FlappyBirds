#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#ifndef POSITIONMENU_H
#define POSITIONMENU_H

using namespace std;
class PositionMenu
{
public:
	PositionMenu(string* text);


	void myDefault() ;
	
private:

	string* text;

	//default color
	static const int dr = 255, dg = 0, db = 255;

	//active color
	static const int ar = 137, ag = 10, ab = 255;




public:
	

};

#endif // !POSITIONMENU_H
