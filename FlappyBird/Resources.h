#pragma once
#include <allegro5/allegro.h>
#include <iostream>
#include <unordered_map>
#include <string>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

using namespace std;


struct ResourceFontStruct {
	string key_;
	int sizeFont_;
	string nameFont_;


	ResourceFontStruct(string key, int size, string name )
	{
		key_ = key;
		sizeFont_ = size;
		nameFont_ = name;
	}
};



struct ResourceSoundStruct {
	string key_;
	string nameFile_;

	ResourceSoundStruct(string key, string nameFile)
	{
		key_ = key;
		nameFile_ = nameFile;
	}
};


struct ResourceBitmapStruct {
	string key_;
	string nameFile_;

	ResourceBitmapStruct(string key, string nameFile)
	{
		key_ = key;
		nameFile_ = nameFile;

	}
};




class Resources
{
public:
	ALLEGRO_BITMAP* getBitmap(string name);
	ALLEGRO_FONT* getFont(string name);
	ALLEGRO_SAMPLE* getSample(string name);
	~Resources();

	static Resources* getInstance(list<ResourceBitmapStruct> bitmapRes, list<ResourceFontStruct> fontRes, list<ResourceFontStruct> soundRes,string resourceFolder);
	
	static Resources* getInstance();
private:
	unordered_map<string, ALLEGRO_BITMAP*> bitmapResource;
	unordered_map<string, ALLEGRO_FONT*> fontResource;
	unordered_map<string, ALLEGRO_SAMPLE*> soundResorce;
	Resources(list<ResourceBitmapStruct> bitmapRes, list<ResourceFontStruct> fontRes, list<ResourceFontStruct> soundRes,string resourceFolder);
	static Resources* instance;

	void loadBitmap(string key, string nameFile);
	void loadFont(string key, string nameFile, int size);
	void loadSample(string key, string nameFile);
	void loadAllResources(list<ResourceBitmapStruct> bitmapRes, list<ResourceFontStruct> fontRes, list<ResourceFontStruct> soundRes);
};

