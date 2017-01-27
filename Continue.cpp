#include "Application.h"
#include "Continue.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneSagat.h"


Continue::Continue(bool start_enabled) : Module(start_enabled)
{
	// Continue
	continua = {77, 102, 127, 16};

	// Time 1
	time1.frames.push_back({ 0, 58, 12, 21 });
	time1.frames.push_back({ 19, 58, 13, 21 });
	time1.frames.push_back({ 41, 58, 11, 21 });
	time1.frames.push_back({ 59, 58, 12, 21 });
	time1.frames.push_back({ 77, 58, 12, 21 });
	time1.frames.push_back({ 97, 58, 12, 21 });
	time1.frames.push_back({ 117, 58, 12, 21 });
	time1.frames.push_back({ 135, 58, 12, 21 });
	time1.frames.push_back({ 157, 60, 9, 21 });
	time1.frames.push_back({ 174, 60, 12, 21 });
	time1.colisionable = false;
	time1.speed = 0.02f;
}


Continue::~Continue()
{
}

// Load assets
bool Continue::Start()
{
	LOG("Preparing Continue Screen");
	App->audio->PlayMusic("Continue.wav");
	graphics = App->textures->Load("GUI2.png");
	time1.current_frame = 0;
	pressButton = false;
	return true;
}

update_status Continue::Update(){
	bool loop = false;
	SDL_Rect col;

	if (!pressButton) 
	{
		aux1 = time1.GetCurrentFrame(loop, col, col, col);
	}

	if (aux1.x != 174) {
		App->renderer->Blit(graphics, 150, 100, &continua, SDL_FLIP_NONE, 0.0f);
		App->renderer->Blit(graphics, 150, 150, &aux1, SDL_FLIP_NONE, 0.0f);
	}
	else {
		return UPDATE_STOP;
	}

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		pressButton = true;
		App->fade->FadeToBlack(App->scene_sagat, this, 3.0f);
	}
	return UPDATE_CONTINUE;
}

// UnLoad assets
bool Continue::CleanUp()
{
	LOG("Unloading Continue");

	App->textures->Unload(graphics);

	return true;
}
