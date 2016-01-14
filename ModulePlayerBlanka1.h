#ifndef __MODULEPLAYERBLANKA1_H__
#define __MODULEPLAYERBLANKA1_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "ModuleCollision.h"
#include "Point.h"
#include <time.h>
#include "SDL/include/SDL.h"

struct SDL_Texture;

class ModulePlayerBlanka1 : public Module
{
public:
	ModulePlayerBlanka1(bool start_enabled = true);
	~ModulePlayerBlanka1();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(const Collider* colliderA, const Collider* colliderB);
	void CombatEnd(const bool time);

public:
	SDL_Texture* graphics = nullptr;
	Collider* bodyCollider = nullptr;
	Collider* armCollider = nullptr;
	Collider* legCollider = nullptr;
	SDL_RendererFlip flip;
	SDL_Rect body;
	SDL_Rect arm;
	SDL_Rect leg;
	SDL_Rect shadow;
	SDL_Rect texture;
	Animation idle;
	Animation walk;
	Animation crouchDown;
	Animation crouchUp;
	Animation jump;
	Animation LPunch;
	Animation MPunch;
	Animation HPunch;
	Animation LMKick;
	Animation HKick;
	Animation FLPunch;
	Animation FMPunch;
	Animation FLMKick;
	Animation CLPunch;
	Animation CMHPunch;
	Animation CLMKick;
	Animation CHKick;
	Animation JPunch;
	Animation FJPunch;
	Animation JLMKick;
	Animation JHKick;
	Animation ElectricShock;
	Animation RollAttack;
	Animation VRollAttack;
	Animation BeastLeap;
	Animation HeadBiteGrab;
	Animation Hit;
	Animation HeadHit;
	Animation HeavyHit;
	Animation Stunned;
	Animation Knockdown;
	Animation Recover;
	Animation Block;
	Animation KO;
	Animation Victory1;
	Animation Victory2;
	Animation TimeOver;
	iPoint position;
	Animation* move = nullptr;
	int life;
	attack_damage damage;
	animation_type_player typeAnim;
	bool loopAnim = true;	// flag to control end of single animation
	SDL_Rect jumpMove;

private:
	clock_t time;
	int jumpDirection = 0;
	int counter = 0;
	int counterBack = 0;
	bool endJump = false;	// if endJump is true the player is falling
	bool jumpAttack = false;	// flag to control only one jump attack
	bool block = false;		// boolean to know if is blocking
	int punchAttacks = 0;	// variable to control followed punch attacks and do electric combo
	unsigned int fxPunch;
	unsigned int fxKick;
	unsigned int fxLose;
};

#endif // __MODULEPLAYERBLANKA1_H__