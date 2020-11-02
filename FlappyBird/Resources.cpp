#include "Resources.h"

Resources* Resources::instance = NULL;




Resources::~Resources()
{
}

Resources* Resources::getInstance(list<ResourceBitmapStruct> bitmapRes, list<ResourceFontStruct> fontRes, list<ResourceFontStruct> soundRes,string resourceFolder)
{
    if (instance == NULL) instance = new Resources(bitmapRes,fontRes,soundRes,resourceFolder);
       return instance;
}

Resources* Resources::getInstance() {
    if (instance != NULL)
    return instance;
}


Resources::Resources(list<ResourceBitmapStruct> bitmapRes, list<ResourceFontStruct> fontRes, list<ResourceFontStruct> soundRes, string resourceFolder)
{
    ALLEGRO_PATH* path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_append_path_component(path,resourceFolder.c_str());
    al_change_directory(al_path_cstr(path, '/'));
    al_destroy_path(path);

    loadAllResources(bitmapRes, fontRes, soundRes);

}

void Resources::loadBitmap(string key, string nameFile)
{

    ALLEGRO_BITMAP* bitmap = al_load_bitmap(nameFile.c_str());
    if (bitmap == NULL)
        cout << "Nie mozna zaladowac tekstury " << key << ", nazwa pliku" << nameFile;
 
    bitmapResource.insert(make_pair(key, bitmap));

}

 void Resources::loadFont(string key, string nameFile, int size)
{
    ALLEGRO_FONT* font = al_load_font(nameFile.c_str(),size,0);
    if (font == NULL)
        cout << "Nie mozna zaladowac czcionki " << key << ", nazwa pliku" << nameFile;

    fontResource.insert(make_pair(key, font));
   
}

void Resources::loadSample(string key, string nameFile)
{
    ALLEGRO_SAMPLE* sound = al_load_sample(nameFile.c_str());
    if (sound == NULL)
        cout << "Nie mozna zaladowac dzwieku " << key << ", nazwa pliku" << nameFile;
   
    soundResorce.insert(make_pair(key, sound));
}

void Resources::loadAllResources(list<ResourceBitmapStruct> bitmapRes, list<ResourceFontStruct> fontRes, list<ResourceFontStruct> soundRes)
{
    for (auto it = bitmapRes.begin(); it != bitmapRes.end(); ++it)
    {
        loadBitmap(it->key_, it->nameFile_);
    }

    for (auto it = bitmapRes.begin(); it != bitmapRes.end(); ++it)
    {
        loadBitmap(it->key_, it->nameFile_);
    }

    for (auto it = bitmapRes.begin(); it != bitmapRes.end(); ++it)
    {
        loadBitmap(it->key_, it->nameFile_);
    }
}




