#ifndef __CONTINUE_H__
#define __CONTINUE_H__

#include "Module.h"
#include "Globals.h"
#include "ModuleRender.h"
#include "Animation.h"
#include <time.h>

struct SDL_Texture;

class Continue : public Module
{
public:
	Continue(bool start_enabled = true);
	~Continue();

	bool Start();
	update_status Update();
	bool CleanUp();

	Animation time1;
	SDL_Rect aux1;
	SDL_Rect continua;
	SDL_Texture* graphics = nullptr;

private:
	bool pressButton = false;
};
#endif

