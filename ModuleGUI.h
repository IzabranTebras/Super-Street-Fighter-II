#ifndef __MODULEGUI_H__
#define __MODULEGUI_H__

#include "Module.h"
#include "Globals.h"
#include "ModuleRender.h"
#include "Animation.h"
#include <time.h>

struct SDL_Texture;

class ModuleGUI :
	public Module
{
public:
	ModuleGUI(bool start_enabled = true);
	~ModuleGUI();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Rect round;
	SDL_Rect fight;
	SDL_Rect battle1;
	SDL_Rect life;
	SDL_Rect aux1;
	SDL_Rect aux2;
	Animation time1;
	Animation time2;
	SDL_Rect player1;
	SDL_Rect player2;
	SDL_Texture* graphic;

private:
	clock_t time;
	bool exit;
	bool roundStart;
	bool fightStart;
	unsigned int fxFight;
	unsigned int fxRound;
	clock_t start;
	int life1;
	int life2;
	SDL_Rect endTime1;
	SDL_Rect endTime2;
	clock_t roundTime;
	clock_t fightTime;
};
#endif
