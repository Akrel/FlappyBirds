
#include <iostream>
#include "Engine.h"
#include "FlappyBird.h"

#include "Resources.h"
	
	int main()
	{
		Engine* myEngine = Engine::getInstane(0,0);

		
		myEngine->setDisplay(1060, 720, 0);
		

		
		//std::cout << myEngine << std::endl;
		al_rest(5.0);
		return 0;
	}


