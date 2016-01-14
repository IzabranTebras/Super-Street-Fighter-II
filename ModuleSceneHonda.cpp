#include "Globals.h"
#include "Application.h"
#include "ModuleSceneHonda.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayerBlanka1.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"


ModuleSceneHonda::ModuleSceneHonda(bool start_enabled) : Module(start_enabled)
{
	//Scene setup from honda_stage.png

	//ground
	ground.x = 7;
	ground.y = 377;
	ground.w = 850;
	ground.h = 65;

	//background
	background.x = 118;
	background.y = 68;
	background.w = 883;
	background.h = 202;
}


ModuleSceneHonda::~ModuleSceneHonda()
{
}

// Load assets
bool ModuleSceneHonda::Start()
{
	LOG("Loading Honda scene");

	graphics = App->textures->Load("honda_stage.png");

	// TODO 7: Enable the player module
	App->player->Enable();
	// TODO 0: trigger background music
	App->audio->PlayMusic("honda.ogg");
	return true;
}

// UnLoad assets
bool ModuleSceneHonda::CleanUp()
{
	LOG("Unloading Honda scene");

	App->textures->Unload(graphics);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneHonda::Update()
{
	// Draw everything --------------------------------------
	App->renderer->Blit(graphics, 0, 170, &ground);
	App->renderer->Blit(graphics, 0, 0, &background);

	return UPDATE_CONTINUE;
}