#include "Globals.h"
#include "Application.h"
#include "ModuleSceneKen.h"
#include "ModuleSceneHonda.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayerBlanka1.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneKen::ModuleSceneKen(bool start_enabled) : Module(start_enabled)
{
	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// TODO 2 : setup the foreground (red ship) with
	// coordinates x,y,w,h from ken_stage.png
	foreground.x = 8;
	foreground.y = 8;
	foreground.w = 520;
	foreground.h = 200;

	// Background / sky
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	// flag animation
	flag.frames.push_back({848, 208, 40, 40});
	flag.frames.push_back({848, 256, 40, 40});
	flag.frames.push_back({848, 304, 40, 40});
	flag.speed = 0.08f;

	// TODO 4: Setup Girl Animation from coordinates from ken_stage.png
	girl.frames.push_back({ 624, 16, 32, 56 });
	girl.frames.push_back({ 624, 80, 32, 56 });
	girl.frames.push_back({ 624, 144, 32, 56 });
	girl.frames.push_back({ 624, 80, 32, 56 });
	girl.speed = 0.08f;

	// two men
	men.frames.push_back({ 552, 16, 65, 56 });
	men.frames.push_back({ 552, 80, 65, 56 });
	men.frames.push_back({ 552, 144, 65, 56 });
	men.speed = 0.08f;

	// man with a blue jersey
	manBlueJersey.frames.push_back({ 664, 16, 32, 56 });
	manBlueJersey.frames.push_back({ 664, 80, 32, 56 });
	manBlueJersey.speed = 0.08f;

	// man with raincoat
	raincoat.frames.push_back({ 703, 16, 49, 56 });
	raincoat.frames.push_back({ 703, 80, 49, 56 });
	raincoat.frames.push_back({ 703, 144, 49, 56 });
	raincoat.speed = 0.08f;
}

ModuleSceneKen::~ModuleSceneKen()
{}

// Load assets
bool ModuleSceneKen::Start()
{
	LOG("Loading ken scene");
	
	graphics = App->textures->Load("ken_stage.png");

	// TODO 7: Enable the player module
	App->player->Enable();
	// TODO 0: trigger background music
	App->audio->PlayMusic("ken.ogg");
	return true;
}

// UnLoad assets
bool ModuleSceneKen::CleanUp()
{
	LOG("Unloading ken scene");

	App->textures->Unload(graphics);
	App->player->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleSceneKen::Update()
{
	bool loopAnim = false;
	//with a counter to avoid extreme speed
	if ((counter%20) != 0){
		counter++;
	}
	else{
		if (down == true){
			height++;
		}
		else{
			height--;
		}
		counter++;
		if (counter >= 140){
			if (down == true){
				down = false;
			}
			else{
				down = true;
			}
			counter = 1;
			}
	}

	// Draw everything --------------------------------------
	// TODO 1: Tweak the movement speed of the sea&sky + flag to your taste
	App->renderer->Blit(graphics, 0, 0, &background, 0.75f); // sea and sky
	App->renderer->Blit(graphics, 560, 8, &(flag.GetCurrentFrame(loopAnim, nullptr, nullptr, nullptr)), 0.75f); // flag animation

	// TODO 3: Draw the ship. Be sure to tweak the speed.
	App->renderer->Blit(graphics, 0, height, &foreground, 0.75f);

	// TODO 6: Draw the girl. Make sure it follows the ship movement!
	App->renderer->Blit(graphics, 192, height + 120, &(girl.GetCurrentFrame(loopAnim)), 0.75f);
	App->renderer->Blit(graphics, 128, height + 120, &(men.GetCurrentFrame(loopAnim)), 0.75f);
	App->renderer->Blit(graphics, 224, height + 120, &(manBlueJersey.GetCurrentFrame(loopAnim)), 0.75f);
	App->renderer->Blit(graphics, 287, height + 112, &(raincoat.GetCurrentFrame(loopAnim)), 0.75f);

	App->renderer->Blit(graphics, 0, 170, &ground);

	// TODO 10: Build an entire new scene "honda", you can find its
	// and music in the Game/ folder

	// TODO 11: Make that pressing space triggers a switch to honda logic module
	// using FadeToBlack module
	if (App->input->GetKey(SDL_SCANCODE_SPACE)){
		App->fade->FadeToBlack(App->scene_honda, App->scene_ken, 3.0f);
	}

	return UPDATE_CONTINUE;
}