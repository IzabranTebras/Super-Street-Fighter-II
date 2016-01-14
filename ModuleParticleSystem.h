#ifndef __MODULEPARTICLESYSTEM_H__
#define __MODULEPARTICLESYSTEM_H__
#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModulePlayerBlanka1.h"
#include "ModuleCollision.h"
#include "Point.h"
#include "SDL\include\SDL.h"
#include <time.h>
#include <vector>

struct SDL_Texture;
struct Particle{
	SDL_Texture* particleGraphic;
	Animation particleAnimation;
	iPoint position;
	float speed;
	int timeToLive;
	int startTime;
};

class ModuleParticleSystem :
	public Module
{
public:
	ModuleParticleSystem();
	~ModuleParticleSystem();

	update_status Update();
	void addParticle(SDL_Texture* particleGraphic, Animation particleAnimation, iPoint position, float speed, int timeToLive);
	void removeParticle(int i);
	bool CleanUp();

	vector<Particle*> particlesVector;
	int currentTime;
	//TEST CODE
	Particle* particleCol;
	//TEST CODE
};
#endif