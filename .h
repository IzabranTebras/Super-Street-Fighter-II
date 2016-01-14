#ifndef __MODULEBLANKA_H__
#define __MODULEBLANKA_H__

#include "Module.h"
#include "Animation.h"
#include "Point.h"

struct SDL_Texture;

class ModuleBlanka :
	public Module
{
public:
	ModuleBlanka(bool start_enabled = true);
	~ModuleBlanka();

	bool Start();
	bool CleanUp();

public:
	iPoint position;
	Animation idle;
	Animation backward;
	Animation forward;
	SDL_Texture* graphics = nullptr;
};
#endif

