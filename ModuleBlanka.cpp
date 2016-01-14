#include "ModuleBlanka.h"
#include "ModulePlayerBlanka1.h"


ModuleBlanka::ModuleBlanka(bool start_enabled) : Module(start_enabled)
{
	position.x = 100;
	position.y = 216;

	// idle animation
	idle.frames.push_back({ 5, 34, 64, 84 });
	idle.frames.push_back({ 77, 32, 63, 86 });
	idle.frames.push_back({ 148, 30, 63, 88 });
	idle.frames.push_back({ 219, 32, 63, 86 });
	idle.speed = 0.05f;
}


ModuleBlanka::~ModuleBlanka()
{
}

// Load assets
bool ModuleBlanka::Start()
{
	LOG("Loading character");

	graphics = App->textures->Load("Blanka.png"); // arcade version
	App->collision->addCollider(this);  //Create the player collider
	return true;
}

// Unload assets
bool ModuleBlanka::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}
