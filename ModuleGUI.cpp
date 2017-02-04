#include "Application.h"
#include "ModuleGUI.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "Continue.h"


ModuleGUI::ModuleGUI(bool start_enabled) : Module(start_enabled)
{
	// Life bar
	life = { 0, 2, 293, 21 };

	// Player 1
	player1 = { 3, 33, 60, 15};

	// Player 2
	player2 = { 3, 33, 60, 15 };

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
	time1.speed = 0.002f;

	// Time 2
	time2.frames.push_back({ 0, 58, 12, 21 });
	time2.frames.push_back({ 19, 58, 13, 21 });
	time2.frames.push_back({ 41, 58, 11, 21 });
	time2.frames.push_back({ 59, 58, 12, 21 });
	time2.frames.push_back({ 77, 58, 12, 21 });
	time2.frames.push_back({ 97, 58, 12, 21 });
	time2.frames.push_back({ 117, 58, 12, 21 });
	time2.frames.push_back({ 135, 58, 12, 21 });
	time2.frames.push_back({ 157, 60, 9, 21 });
	time2.frames.push_back({ 174, 60, 12, 21 });
	time2.colisionable = false;
	time2.speed = 0.02f;

	// Round
	round = {205, 46, 72, 40};

	// Battle
	battle1 = {75, 36, 104, 12};

	// Fight
	fight = {4, 90, 60, 43};
}


ModuleGUI::~ModuleGUI()
{
}

// Load assets
bool ModuleGUI::Start()
{
	LOG("Loading GUI");
	graphic = App->textures->Load("GUI2.png");
	fxRound = App->audio->LoadFx("StartBattle.wav");
	fxFight = App->audio->LoadFx("Fight.wav");
	life1 = 132;
	life2 = 132;
	time1.current_frame = 0;
	time2.current_frame = 0;
	aux1 = { 0, 0, 0, 0 };
	aux2 = { 0, 0, 0, 0 };
	endTime1 = { 0, 0, 0, 0 };
	start = clock();
	exit = false;
	roundStart = false;
	fightStart = false;
	roundTime = 4000;
	fightTime = 3000;

	return true;
}

// UnLoad assets
bool ModuleGUI::CleanUp()
{
	LOG("Unloading GUI");

	App->textures->Unload(graphic);

	return true;
}

update_status ModuleGUI::Update()
{
	bool loop = false;
	SDL_Rect col;

	// Draw GUI --------------------------------------
	App->renderer->Blit(graphic, 45, 10, &life, SDL_FLIP_NONE, 0.0f);
	App->renderer->Blit(graphic, 45, 32, &player1, SDL_FLIP_NONE, 0.0f);
	App->renderer->Blit(graphic, 277, 32, &player2, SDL_FLIP_NONE, 0.0f);

	if ((clock() - start) < fightTime){
		App->renderer->Blit(graphic, 150, 80, &round, SDL_FLIP_NONE, 0.0f);
		App->renderer->Blit(graphic, 135, 125, &battle1, SDL_FLIP_NONE, 0.0f);
		if (roundStart == false){
			App->audio->PlayFx(fxRound);
			roundStart = true;
		}
	}
	else{
		if ((clock() - start) < roundTime){
			App->renderer->Blit(graphic, 155, 80, &fight, SDL_FLIP_NONE, 0.0f);
			App->renderer->Blit(graphic, 135, 125, &battle1, SDL_FLIP_NONE, 0.0f);
			if (fightStart == false){
				App->audio->PlayFx(fxFight);
				fightStart = true;
			}
		}
		else{

			if (aux1.x != 174){
				aux1 = time1.GetCurrentFrame(loop, col, col, col);
			}
			if ((((aux1.x != 174) || (aux1.x == 174)) && (aux2.x != 174)) || ((aux1.x != 174) && (aux2.x == 174))){
				aux2 = time2.GetCurrentFrame(loop, col, col, col);
			}

			if (endTime1.y == 0){
				if (aux1.x == 174){
					App->renderer->Blit(graphic, 178, 35, &time1.frames[9], SDL_FLIP_NONE, 0.0f);
				}
				else{
					App->renderer->Blit(graphic, 178, 35, &aux1, SDL_FLIP_NONE, 0.0f);
				}

				if ((aux1.x == 174) && (aux2.x == 174)){
					App->renderer->Blit(graphic, 192, 35, &time2.frames[9], SDL_FLIP_NONE, 0.0f);
				}
				else{
					App->renderer->Blit(graphic, 192, 35, &aux2, SDL_FLIP_NONE, 0.0f);
				}

				if ((aux1.x == 174) && (aux2.x == 174)){
					App->player->CombatEnd(true);
					App->player2->CombatEnd(true);
				}
			}
			else{
				App->renderer->Blit(graphic, 178, 35, &endTime1, SDL_FLIP_NONE, 0.0f);
				App->renderer->Blit(graphic, 192, 35, &endTime2, SDL_FLIP_NONE, 0.0f);
			}

			if (((App->player->life < 1) || (App->player2->life < 1)) && (endTime1.y == 0)){
				endTime1 = aux1;
				endTime2 = aux2;
			}

			life1 = 262 - App->player->life;
			life2 = 262 - App->player2->life;

			if (life1 > 262){
				life1 = 262;
			}

			if (life2 > 262){
				life2 = 262;
			}

			// bar have 132 units
			App->renderer->DrawQuad({ 97, 30, life1, 24 }, 230, 0, 0, 255, false);
			App->renderer->DrawQuad({ 670 - life2, 30, life2, 24 }, 230, 0, 0, 255, false);
		}
	}

	

	return UPDATE_CONTINUE;
}
