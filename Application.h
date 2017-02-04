#ifndef __APPLICATION_CPP__
#define __APPLICATION_CPP__

#include<list>
#include "Globals.h"
#include "Module.h"

class ModuleRender;
class ModuleWindow;
class ModuleTextures;
class ModuleInput;
class ModuleAudio;
class ModuleFadeToBlack;
class ModulePlayer;
class ModulePlayerBlanka2;
class ModuleSceneKen;
class ModuleSceneHonda;
class ModuleParticleSystem;
class ModuleCollision;
class ModuleSceneSagat;
class ModuleGUI;
class Continue;

class Application
{
public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

public:
	ModuleRender* renderer;
	ModuleWindow* window;
	ModuleTextures* textures;
	ModuleInput* input;
	ModuleAudio* audio;
	ModuleFadeToBlack* fade;
	ModulePlayer* player;
	ModulePlayer* player2;
	ModuleSceneKen* scene_ken;
	ModuleSceneHonda* scene_honda;
	ModuleParticleSystem* particles;
	ModuleCollision* collision;
	ModuleSceneSagat* scene_sagat;
	ModuleGUI* gui;
	Continue* cont;

private:

	std::list<Module*> modules;

};

extern Application* App;

#endif // __APPLICATION_CPP__