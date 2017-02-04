#include "Application.h"
#include "ModuleSceneSagat.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleGUI.h"
#include "ModuleFadeToBlack.h"
#include "Continue.h"
#include "ModuleCollision.h"
#include "SDL/include/SDL.h"

ModuleSceneSagat::ModuleSceneSagat(bool start_enabled) : Module(start_enabled)
{
	//Background texture
	background.x = 0;
	background.w = 512;
	background.y = 0;
	background.h = 179;

	//Foreground texture
	foreground.x = 0;
	foreground.w = 464;
	foreground.y = 292;
	foreground.h = 112;

	//Ground texture
	ground.x = 0;
	ground.w = 464;
	ground.y = 180;
	ground.h = 112;

	//Rocks texture
	rocks.x = 0;
	rocks.w = 512;
	rocks.y = 403;
	rocks.h = 112;
}


ModuleSceneSagat::~ModuleSceneSagat()
{
}

// Load assets
bool ModuleSceneSagat::Start()
{
	LOG("Loading ken scene");

	graphics = App->textures->Load("Sagat stage.png");
	exit = false;

	// Enable the player and gui module
	App->player->Enable();
	App->player2->Enable();
	App->gui->Enable();
	App->collision->Enable();

	// Trigger background music
	App->audio->PlayMusic("Sagat.wav");
	return true;
}

// UnLoad assets
bool ModuleSceneSagat::CleanUp()
{
	LOG("Unloading Sagat scene");

	App->textures->Unload(graphics);
	App->collision->Disable();
	App->player->Disable();
	App->player2->Disable();
	App->gui->Disable();

	return true;
}

update_status ModuleSceneSagat::Update()
{
	// Draw everything --------------------------------------
	App->renderer->Blit(graphics, 0, -30, &background, SDL_FLIP_NONE, 0.3f); // background
	App->renderer->Blit(graphics, 65, 6, &foreground); // Foreground
	App->renderer->Blit(graphics, 65, 118, &ground); // Ground
	App->renderer->Blit(graphics, 65, 118, &rocks); // Rocks

	if (((App->player->life < 1) || (App->player2->life < 1) || ((App->gui->aux1.x == 174)) && (App->gui->aux2.x == 174))){
		if (exit == false){
			time = clock();
			exit = true;
		}

		if ((exit == true) && (clock() - time < 2000)){
			App->fade->FadeToBlack(App->cont, this, 3.0f);
		}
	}

	return UPDATE_CONTINUE;
}