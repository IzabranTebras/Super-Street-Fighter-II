#ifndef __MODULESCENESAGAT_H__
#define __MODULESCENESAGAT_H__

#include "Module.h"
#include "Globals.h"
#include <time.h>

struct SDL_Texture;

class ModuleSceneSagat : public Module
{
public:
	ModuleSceneSagat(bool start_enabled = true);
	~ModuleSceneSagat();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* graphics = nullptr;
	SDL_Rect ground;
	SDL_Rect foreground;
	SDL_Rect background;
	SDL_Rect rocks;
	clock_t time;
	bool exit;
};
#endif

