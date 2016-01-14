#include "Globals.h"
#include "Application.h"
#include "ModulePlayerBlanka2.h"
#include "ModulePlayerBlanka1.h"
#include "ModuleSceneSagat.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleParticleSystem.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"

ModulePlayerBlanka2::ModulePlayerBlanka2(bool start_enabled) : Module(start_enabled)
{
	// add animation frames and box colliders to once frame
	// idle animation
	idle.frames.push_back({ 0, 10, 71, 108 });
	idle.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	idle.armColliderFrame.push_back({ 50, 40, 20, 20 });
	idle.legColliderFrame.push_back({ 50, 70, 20, 20 });
	idle.frames.push_back({ 72, 10, 71, 108 });
	idle.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	idle.armColliderFrame.push_back({ 50, 40, 20, 20 });
	idle.legColliderFrame.push_back({ 50, 70, 20, 20 });
	idle.frames.push_back({ 143, 10, 71, 108 });
	idle.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	idle.armColliderFrame.push_back({ 50, 40, 20, 20 });
	idle.legColliderFrame.push_back({ 50, 70, 20, 20 });
	idle.frames.push_back({ 214, 10, 71, 108 });
	idle.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	idle.armColliderFrame.push_back({ 50, 40, 20, 20 });
	idle.legColliderFrame.push_back({ 50, 70, 20, 20 });
	idle.speed = 0.08f;

	// shadow
	shadow = { 712, 75, 60, 44 };

	// walk backward and forward animation
	walk.frames.push_back({ 288, 10, 71, 108 });
	walk.bodyColliderFrame.push_back({ 55, 45, 30, 65 });
	walk.armColliderFrame.push_back({ 75, 50, 20, 20 });
	walk.legColliderFrame.push_back({ 55, 70, 20, 20 });
	walk.frames.push_back({ 359, 10, 71, 108 });
	walk.bodyColliderFrame.push_back({ 55, 45, 30, 65 });
	walk.armColliderFrame.push_back({ 75, 50, 20, 20 });
	walk.legColliderFrame.push_back({ 55, 70, 20, 20 });
	walk.frames.push_back({ 430, 10, 71, 108 });
	walk.bodyColliderFrame.push_back({ 55, 45, 30, 65 });
	walk.armColliderFrame.push_back({ 75, 50, 20, 20 });
	walk.legColliderFrame.push_back({ 55, 70, 20, 20 });
	walk.frames.push_back({ 501, 10, 71, 108 });
	walk.bodyColliderFrame.push_back({ 55, 45, 30, 65 });
	walk.armColliderFrame.push_back({ 75, 50, 20, 20 });
	walk.legColliderFrame.push_back({ 55, 70, 20, 20 });
	walk.frames.push_back({ 572, 10, 71, 108 });
	walk.bodyColliderFrame.push_back({ 50, 45, 30, 65 });
	walk.armColliderFrame.push_back({ 75, 40, 20, 20 });
	walk.legColliderFrame.push_back({ 55, 70, 20, 20 });
	walk.speed = 0.1f;

	// crouch down animation
	crouchDown.frames.push_back({ 938, 10, 71, 108 });
	crouchDown.bodyColliderFrame.push_back({ 50, 55, 30, 50 });
	crouchDown.armColliderFrame.push_back({ 65, 50, 20, 20 });
	crouchDown.legColliderFrame.push_back({ 55, 70, 20, 20 });
	crouchDown.speed = 0.03f;

	// crouch up animation
	crouchUp.frames.push_back({ 1012, 10, 71, 108 });
	crouchUp.bodyColliderFrame.push_back({ 50, 60, 30, 45 });
	crouchUp.armColliderFrame.push_back({ 65, 55, 20, 20 });
	crouchUp.legColliderFrame.push_back({ 55, 70, 20, 20 });
	crouchUp.speed = 0.05f;

	// jump animation
	jump.frames.push_back({ 646, 10, 68, 108 });
	jump.bodyColliderFrame.push_back({ 50, 55, 30, 50 });
	jump.armColliderFrame.push_back({ 65, 50, 20, 20 });
	jump.legColliderFrame.push_back({ 50, 70, 20, 20 });
	jump.frames.push_back({ 771, 12, 54, 108 });
	jump.bodyColliderFrame.push_back({ 40, 10, 30, 95 });
	jump.armColliderFrame.push_back({ 70, 15, 10, 50 });
	jump.legColliderFrame.push_back({ 50, 70, 20, 20 });
	jump.frames.push_back({ 829, 12, 54, 108 });
	jump.bodyColliderFrame.push_back({ 45, 10, 30, 50 });
	jump.armColliderFrame.push_back({ 50, 40, 20, 20 });
	jump.legColliderFrame.push_back({ 50, 50, 20, 20 });
	jump.frames.push_back({ 883, 12, 54, 108 });
	jump.bodyColliderFrame.push_back({ 40, 10, 30, 95 });
	jump.armColliderFrame.push_back({ 70, 15, 10, 50 });
	jump.legColliderFrame.push_back({ 50, 70, 20, 20 });
	jump.speed = 0.03f;
	jump.jumpAnim = true;

	// Low Punch animation
	LPunch.frames.push_back({ 3, 137, 70, 108 });
	LPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	LPunch.armColliderFrame.push_back({ 70, 40, 15, 20 });
	LPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	LPunch.frames.push_back({ 3, 137, 70, 108 });
	LPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	LPunch.armColliderFrame.push_back({ 70, 40, 15, 20 });
	LPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	LPunch.frames.push_back({ 73, 137, 90, 108 });
	LPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	LPunch.armColliderFrame.push_back({ 70, 45, 50, 10 });
	LPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	LPunch.frames.push_back({ 73, 137, 90, 108 });
	LPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	LPunch.armColliderFrame.push_back({ 70, 45, 50, 10 });
	LPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	LPunch.frames.push_back({ 73, 137, 90, 108 });
	LPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	LPunch.armColliderFrame.push_back({ 70, 45, 50, 10 });
	LPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	LPunch.frames.push_back({ 166, 137, 76, 108 });
	LPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	LPunch.armColliderFrame.push_back({ 70, 35, 30, 20 });
	LPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	LPunch.frames.push_back({ 166, 137, 76, 108 });
	LPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	LPunch.armColliderFrame.push_back({ 70, 35, 30, 20 });
	LPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	LPunch.frames.push_back({ 166, 137, 76, 108 });
	LPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	LPunch.armColliderFrame.push_back({ 70, 35, 30, 20 });
	LPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	LPunch.frames.push_back({ 166, 137, 76, 108 });
	LPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	LPunch.armColliderFrame.push_back({ 70, 35, 30, 20 });
	LPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	LPunch.frames.push_back({ 243, 137, 90, 108 });
	LPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	LPunch.armColliderFrame.push_back({ 70, 45, 50, 10 });
	LPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	LPunch.frames.push_back({ 243, 137, 90, 108 });
	LPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	LPunch.armColliderFrame.push_back({ 70, 45, 50, 10 });
	LPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	LPunch.frames.push_back({ 243, 137, 90, 108 });
	LPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	LPunch.armColliderFrame.push_back({ 70, 45, 50, 10 });
	LPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	LPunch.frames.push_back({ 337, 137, 70, 108 });
	LPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	LPunch.armColliderFrame.push_back({ 70, 40, 15, 20 });
	LPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	LPunch.frames.push_back({ 337, 137, 70, 108 });
	LPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	LPunch.armColliderFrame.push_back({ 70, 40, 15, 20 });
	LPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	LPunch.frames.push_back({ 337, 137, 70, 108 });
	LPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	LPunch.armColliderFrame.push_back({ 70, 40, 15, 20 });
	LPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	LPunch.speed = 0.4f;

	// Medium Punch Animation
	MPunch.frames.push_back({ 417, 136, 94, 108 });
	MPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	MPunch.armColliderFrame.push_back({ 70, 30, 45, 15 });
	MPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	MPunch.frames.push_back({ 417, 136, 94, 108 });
	MPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	MPunch.armColliderFrame.push_back({ 70, 30, 45, 15 });
	MPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	MPunch.frames.push_back({ 523, 135, 94, 108 });
	MPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	MPunch.armColliderFrame.push_back({ 70, 45, 55, 15 });
	MPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	MPunch.frames.push_back({ 523, 135, 94, 108 });
	MPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	MPunch.armColliderFrame.push_back({ 70, 45, 55, 15 });
	MPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	MPunch.frames.push_back({ 637, 137, 94, 108 });
	MPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	MPunch.armColliderFrame.push_back({ 70, 40, 15, 20 });
	MPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	MPunch.frames.push_back({ 637, 137, 94, 108 });
	MPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	MPunch.armColliderFrame.push_back({ 70, 40, 15, 20 });
	MPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	MPunch.frames.push_back({ 637, 137, 94, 108 });
	MPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	MPunch.armColliderFrame.push_back({ 70, 40, 15, 20 });
	MPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	MPunch.speed = 0.3f;

	// High Punch Animation
	HPunch.frames.push_back({ 750, 140, 83, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 60, 40, 20, 20 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 750, 140, 83, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 60, 40, 20, 20 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 750, 140, 83, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 60, 40, 20, 20 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 833, 140, 91, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 70, 45, 50, 15 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 833, 140, 91, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 70, 45, 50, 15 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 833, 140, 91, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 70, 45, 50, 15 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 833, 140, 91, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 70, 45, 50, 15 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 924, 140, 82, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 90, 10, 20, 40 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 924, 140, 82, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 90, 10, 20, 40 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 924, 140, 82, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 90, 10, 20, 40 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1010, 140, 90, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 70, 45, 50, 15 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1010, 140, 90, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 70, 45, 50, 15 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1010, 140, 90, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 70, 45, 50, 15 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1010, 140, 90, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 70, 45, 50, 15 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1010, 140, 90, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 70, 45, 50, 15 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1010, 140, 90, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 70, 45, 50, 15 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1010, 140, 90, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 70, 45, 50, 15 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1010, 140, 90, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 70, 45, 50, 15 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1010, 140, 90, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 70, 45, 50, 15 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1010, 140, 90, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 70, 45, 50, 15 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1101, 140, 76, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 60, 40, 20, 20 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1101, 140, 76, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 60, 40, 20, 20 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1101, 140, 76, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 60, 40, 20, 20 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1101, 140, 76, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 60, 40, 20, 20 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1101, 140, 76, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 60, 40, 20, 20 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1101, 140, 76, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 60, 40, 20, 20 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.frames.push_back({ 1101, 140, 76, 108 });
	HPunch.bodyColliderFrame.push_back({ 60, 30, 25, 75 });
	HPunch.armColliderFrame.push_back({ 60, 40, 20, 20 });
	HPunch.legColliderFrame.push_back({ 70, 70, 20, 35 });
	HPunch.speed = 0.5f;

	// L-M Kick Animation
	LMKick.frames.push_back({ 2, 385, 70, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 70, 20, 30 });
	LMKick.frames.push_back({ 2, 385, 70, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 70, 20, 30 });
	LMKick.frames.push_back({ 2, 385, 70, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 70, 20, 30 });
	LMKick.frames.push_back({ 2, 385, 70, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 70, 20, 30 });
	LMKick.frames.push_back({ 2, 385, 70, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 70, 20, 30 });
	LMKick.frames.push_back({ 2, 385, 70, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 70, 20, 30 });
	LMKick.frames.push_back({ 2, 385, 70, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 70, 20, 30 });
	LMKick.frames.push_back({ 72, 385, 94, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 60, 50, 20 });
	LMKick.frames.push_back({ 72, 385, 94, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 60, 50, 20 });
	LMKick.frames.push_back({ 72, 385, 94, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 60, 50, 20 });
	LMKick.frames.push_back({ 72, 385, 94, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 60, 50, 20 });
	LMKick.frames.push_back({ 167, 385, 70, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 70, 20, 30 });
	LMKick.frames.push_back({ 167, 385, 70, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 70, 20, 30 });
	LMKick.frames.push_back({ 167, 385, 70, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 70, 20, 30 });
	LMKick.frames.push_back({ 167, 385, 70, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 70, 20, 30 });
	LMKick.frames.push_back({ 167, 385, 70, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 70, 20, 30 });
	LMKick.frames.push_back({ 167, 385, 70, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 70, 20, 30 });
	LMKick.frames.push_back({ 167, 385, 70, 108 });
	LMKick.bodyColliderFrame.push_back({ 50, 35, 30, 70 });
	LMKick.armColliderFrame.push_back({ 65, 50, 20, 20 });
	LMKick.legColliderFrame.push_back({ 75, 70, 20, 30 });
	LMKick.speed = 0.6f;

	// High Kick Animation
	HKick.frames.push_back({ 240, 385, 64, 108 });
	HKick.bodyColliderFrame.push_back({ 45, 20, 45, 45 });
	HKick.armColliderFrame.push_back({ 45, 20, 5, 5 });
	HKick.legColliderFrame.push_back({ 45, 30, 5, 5 });
	HKick.frames.push_back({ 308, 385, 102, 108 });
	HKick.bodyColliderFrame.push_back({ 50, 25, 80, 30 });
	HKick.armColliderFrame.push_back({ 35, 30, 10, 40 });
	HKick.legColliderFrame.push_back({ 50, 25, 5, 5 });
	HKick.frames.push_back({ 411, 385, 84, 108 });
	HKick.bodyColliderFrame.push_back({ 50, 20, 60, 30 });
	HKick.armColliderFrame.push_back({ 60, 40, 10, 60 });
	HKick.legColliderFrame.push_back({ 50, 25, 5, 5 });
	HKick.frames.push_back({ 501, 385, 91, 108 });
	HKick.bodyColliderFrame.push_back({ 40, 30, 50, 30 });
	HKick.armColliderFrame.push_back({ 80, 50, 20, 60 });
	HKick.legColliderFrame.push_back({ 40, 30, 5, 5 });
	HKick.frames.push_back({ 589, 385, 83, 108 });
	HKick.bodyColliderFrame.push_back({ 45, 40, 60, 60 });
	HKick.armColliderFrame.push_back({ 50, 40, 5, 5 });
	HKick.legColliderFrame.push_back({ 50, 40, 5, 5 });
	HKick.frames.push_back({ 678, 385, 63, 108 });
	HKick.bodyColliderFrame.push_back({ 50, 55, 40, 50 });
	HKick.armColliderFrame.push_back({ 50, 55, 5, 5 });
	HKick.legColliderFrame.push_back({ 50, 55, 5, 5 });
	HKick.speed = 0.15f;

	// Forward Low Punch Animation
	FLPunch.frames.push_back({ 2, 248, 80, 120 });
	FLPunch.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	FLPunch.armColliderFrame.push_back({ 60, 55, 45, 20 });
	FLPunch.legColliderFrame.push_back({ 50, 70, 20, 20 });
	FLPunch.frames.push_back({ 2, 248, 80, 120 });
	FLPunch.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	FLPunch.armColliderFrame.push_back({ 60, 55, 45, 20 });
	FLPunch.legColliderFrame.push_back({ 50, 70, 20, 20 });
	FLPunch.frames.push_back({ 85, 248, 100, 120 });
	FLPunch.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	FLPunch.armColliderFrame.push_back({ 60, 40, 70, 15 });
	FLPunch.legColliderFrame.push_back({ 50, 70, 20, 20 });
	FLPunch.frames.push_back({ 85, 248, 100, 120 });
	FLPunch.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	FLPunch.armColliderFrame.push_back({ 60, 40, 70, 15 });
	FLPunch.legColliderFrame.push_back({ 50, 70, 20, 20 });
	FLPunch.frames.push_back({ 194, 248, 92, 120 });
	FLPunch.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	FLPunch.armColliderFrame.push_back({ 60, 35, 70, 15 });
	FLPunch.legColliderFrame.push_back({ 50, 70, 20, 20 });
	FLPunch.frames.push_back({ 194, 248, 92, 120 });
	FLPunch.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	FLPunch.armColliderFrame.push_back({ 60, 35, 70, 15 });
	FLPunch.legColliderFrame.push_back({ 50, 70, 20, 20 });
	FLPunch.frames.push_back({ 194, 248, 92, 120 });
	FLPunch.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	FLPunch.armColliderFrame.push_back({ 60, 35, 70, 15 });
	FLPunch.legColliderFrame.push_back({ 50, 70, 20, 20 });
	FLPunch.frames.push_back({ 194, 248, 92, 120 });
	FLPunch.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	FLPunch.armColliderFrame.push_back({ 60, 35, 70, 15 });
	FLPunch.legColliderFrame.push_back({ 50, 70, 20, 20 });
	FLPunch.frames.push_back({ 294, 248, 100, 120 });
	FLPunch.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	FLPunch.armColliderFrame.push_back({ 60, 40, 70, 15 });
	FLPunch.legColliderFrame.push_back({ 50, 70, 20, 20 });
	FLPunch.frames.push_back({ 294, 248, 100, 120 });
	FLPunch.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	FLPunch.armColliderFrame.push_back({ 60, 40, 70, 15 });
	FLPunch.legColliderFrame.push_back({ 50, 70, 20, 20 });
	FLPunch.frames.push_back({ 394, 248, 82, 120 });
	FLPunch.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	FLPunch.armColliderFrame.push_back({ 60, 55, 45, 20 });
	FLPunch.legColliderFrame.push_back({ 50, 70, 20, 20 });
	FLPunch.frames.push_back({ 394, 248, 82, 120 });
	FLPunch.bodyColliderFrame.push_back({ 50, 30, 30, 75 });
	FLPunch.armColliderFrame.push_back({ 60, 55, 45, 20 });
	FLPunch.legColliderFrame.push_back({ 50, 70, 20, 20 });
	FLPunch.speed = 0.5f;

	// Forward Medium Punch Animation
	FMPunch.frames.push_back({ 577, 249, 65, 108 });
	FMPunch.bodyColliderFrame.push_back({ 40, 30, 30, 75 });
	FMPunch.armColliderFrame.push_back({ 45, 30, 25, 20 });
	FMPunch.legColliderFrame.push_back({ 60, 70, 20, 30 });
	FMPunch.frames.push_back({ 641, 249, 84, 108 });
	FMPunch.bodyColliderFrame.push_back({ 50, 50, 30, 55 });
	FMPunch.armColliderFrame.push_back({ 60, 45, 55, 30 });
	FMPunch.legColliderFrame.push_back({ 80, 70, 20, 20 });
	FMPunch.frames.push_back({ 724, 249, 82, 108 });
	FMPunch.bodyColliderFrame.push_back({ 50, 50, 30, 55 });
	FMPunch.armColliderFrame.push_back({ 60, 55, 55, 40 });
	FMPunch.legColliderFrame.push_back({ 80, 70, 20, 20 });
	FMPunch.frames.push_back({ 807, 249, 83, 108 });
	FMPunch.bodyColliderFrame.push_back({ 50, 50, 30, 55 });
	FMPunch.armColliderFrame.push_back({ 60, 45, 55, 30 });
	FMPunch.legColliderFrame.push_back({ 80, 70, 20, 20 });
	FMPunch.frames.push_back({ 893, 249, 65, 108 });
	FMPunch.bodyColliderFrame.push_back({ 40, 30, 30, 75 });
	FMPunch.armColliderFrame.push_back({ 45, 30, 25, 20 });
	FMPunch.legColliderFrame.push_back({ 60, 70, 20, 30 });
	FMPunch.speed = 0.2f;

	// Forward L-M Kick Animation
	FLMKick.frames.push_back({ 744, 390, 70, 112 });
	FLMKick.bodyColliderFrame.push_back({ 55, 5, 30, 95 });
	FLMKick.armColliderFrame.push_back({ 60, 15, 20, 20 });
	FLMKick.legColliderFrame.push_back({ 60, 30, 20, 20 });
	FLMKick.frames.push_back({ 814, 390, 62, 112 });
	FLMKick.bodyColliderFrame.push_back({ 55, 5, 30, 80 });
	FLMKick.armColliderFrame.push_back({ 60, 15, 20, 20 });
	FLMKick.legColliderFrame.push_back({ 75, 50, 20, 35 });
	FLMKick.frames.push_back({ 878, 390, 70, 112 });
	FLMKick.bodyColliderFrame.push_back({ 55, 5, 30, 80 });
	FLMKick.armColliderFrame.push_back({ 60, 15, 20, 20 });
	FLMKick.legColliderFrame.push_back({ 80, 30, 20, 45 });
	FLMKick.frames.push_back({ 950, 390, 62, 112 });
	FLMKick.bodyColliderFrame.push_back({ 55, 5, 30, 80 });
	FLMKick.armColliderFrame.push_back({ 60, 15, 20, 20 });
	FLMKick.legColliderFrame.push_back({ 75, 50, 20, 35 });
	FLMKick.frames.push_back({ 1017, 390, 71, 112 });
	FLMKick.bodyColliderFrame.push_back({ 55, 5, 30, 95 });
	FLMKick.armColliderFrame.push_back({ 60, 15, 20, 20 });
	FLMKick.legColliderFrame.push_back({ 60, 30, 20, 20 });
	FLMKick.speed = 0.1f;

	// Crouch Low Punch Animation
	CLPunch.frames.push_back({ 2, 494, 80, 110 });
	CLPunch.bodyColliderFrame.push_back({ 45, 60, 50, 40 });
	CLPunch.armColliderFrame.push_back({ 85, 70, 20, 20 });
	CLPunch.legColliderFrame.push_back({ 55, 70, 20, 20 });
	CLPunch.frames.push_back({ 83, 494, 96, 110 });
	CLPunch.bodyColliderFrame.push_back({ 45, 70, 50, 40 });
	CLPunch.armColliderFrame.push_back({ 85, 70, 40, 20 });
	CLPunch.legColliderFrame.push_back({ 55, 70, 20, 20 });
	CLPunch.frames.push_back({ 179, 494, 91, 110 });
	CLPunch.bodyColliderFrame.push_back({ 40, 70, 60, 40 });
	CLPunch.armColliderFrame.push_back({ 85, 85, 35, 15 });
	CLPunch.legColliderFrame.push_back({ 55, 70, 20, 20 });
	CLPunch.frames.push_back({ 270, 494, 97, 110 });
	CLPunch.bodyColliderFrame.push_back({ 45, 70, 50, 40 });
	CLPunch.armColliderFrame.push_back({ 85, 70, 40, 20 });
	CLPunch.legColliderFrame.push_back({ 55, 70, 20, 20 });
	CLPunch.frames.push_back({ 367, 494, 80, 110 });
	CLPunch.bodyColliderFrame.push_back({ 45, 60, 50, 40 });
	CLPunch.armColliderFrame.push_back({ 85, 70, 20, 20 });
	CLPunch.legColliderFrame.push_back({ 55, 70, 20, 20 });
	CLPunch.speed = 0.2f;

	// Crouch Medium - High Punch Animation
	CMHPunch.frames.push_back({ 450, 495, 72, 110 });
	CMHPunch.bodyColliderFrame.push_back({ 45, 60, 50, 50 });
	CMHPunch.armColliderFrame.push_back({ 80, 80, 20, 15 });
	CMHPunch.legColliderFrame.push_back({ 55, 70, 20, 20 });
	CMHPunch.frames.push_back({ 522, 495, 112, 110 });
	CMHPunch.bodyColliderFrame.push_back({ 45, 50, 70, 50 });
	CMHPunch.armColliderFrame.push_back({ 115, 35, 30, 40 });
	CMHPunch.legColliderFrame.push_back({ 55, 70, 20, 20 });
	CMHPunch.frames.push_back({ 636, 501, 72, 110 });
	CMHPunch.bodyColliderFrame.push_back({ 45, 60, 50, 50 });
	CMHPunch.armColliderFrame.push_back({ 80, 80, 20, 15 });
	CMHPunch.legColliderFrame.push_back({ 55, 70, 20, 20 });
	CMHPunch.speed = 0.1f;

	// Crouch Low - Medium Kick Animation
	CLMKick.frames.push_back({ 710, 500, 67, 110 });
	CLMKick.bodyColliderFrame.push_back({ 45, 45, 40, 60 });
	CLMKick.armColliderFrame.push_back({ 45, 45, 5, 5 });
	CLMKick.legColliderFrame.push_back({ 70, 75, 20, 30 });
	CLMKick.frames.push_back({ 777, 500, 93, 110 });
	CLMKick.bodyColliderFrame.push_back({ 45, 45, 40, 60 });
	CLMKick.armColliderFrame.push_back({ 45, 45, 5, 5 });
	CLMKick.legColliderFrame.push_back({ 75, 80, 50, 15 });
	CLMKick.frames.push_back({ 871, 500, 67, 110 });
	CLMKick.bodyColliderFrame.push_back({ 45, 45, 40, 60 });
	CLMKick.armColliderFrame.push_back({ 45, 45, 5, 5 });
	CLMKick.legColliderFrame.push_back({ 70, 75, 20, 30 });
	CLMKick.speed = 0.2f;

	// Crouch High Kick Animation
	CHKick.frames.push_back({ 944, 499, 72, 110 });
	CHKick.bodyColliderFrame.push_back({ 55, 45, 30, 60 });
	CHKick.armColliderFrame.push_back({ 55, 45, 5, 5 });
	CHKick.legColliderFrame.push_back({ 70, 85, 30, 20 });
	CHKick.frames.push_back({ 1015, 499, 100, 110 });
	CHKick.bodyColliderFrame.push_back({ 55, 45, 30, 60 });
	CHKick.armColliderFrame.push_back({ 55, 45, 5, 5 });
	CHKick.legColliderFrame.push_back({ 70, 80, 60, 25 });
	CHKick.frames.push_back({ 1115, 499, 71, 110 });
	CHKick.bodyColliderFrame.push_back({ 55, 45, 30, 60 });
	CHKick.armColliderFrame.push_back({ 55, 45, 5, 5 });
	CHKick.legColliderFrame.push_back({ 70, 85, 30, 20 });
	CHKick.speed = 0.1f;

	// Jump Punch Animation
	JPunch.frames.push_back({ 0, 605, 56, 90 });
	JPunch.bodyColliderFrame.push_back({ 40, 20, 30, 60 });
	JPunch.armColliderFrame.push_back({ 70, 20, 20, 30 });
	JPunch.legColliderFrame.push_back({ 50, 40, 5, 5 });
	JPunch.frames.push_back({ 58, 605, 75, 90 });
	JPunch.bodyColliderFrame.push_back({ 40, 20, 30, 60 });
	JPunch.armColliderFrame.push_back({ 75, 40, 30, 20 });
	JPunch.legColliderFrame.push_back({ 50, 40, 5, 5 });
	JPunch.frames.push_back({ 133, 605, 58, 90 });
	JPunch.bodyColliderFrame.push_back({ 40, 20, 30, 60 });
	JPunch.armColliderFrame.push_back({ 70, 20, 20, 30 });
	JPunch.legColliderFrame.push_back({ 50, 40, 5, 5 });
	JPunch.speed = 0.15f;

	// Jump Forward Punch Animation
	FJPunch.frames.push_back({ 192, 605, 80, 90 });
	FJPunch.bodyColliderFrame.push_back({ 40, 20, 30, 60 });
	FJPunch.armColliderFrame.push_back({ 70, 20, 40, 20 });
	FJPunch.legColliderFrame.push_back({ 50, 40, 5, 5 });
	FJPunch.frames.push_back({ 272, 605, 64, 90 });
	FJPunch.bodyColliderFrame.push_back({ 40, 20, 30, 60 });
	FJPunch.armColliderFrame.push_back({ 75, 40, 20, 40 });
	FJPunch.legColliderFrame.push_back({ 50, 40, 5, 5 });
	FJPunch.frames.push_back({ 337, 605, 52, 90 });
	FJPunch.bodyColliderFrame.push_back({ 40, 20, 30, 70 });
	FJPunch.armColliderFrame.push_back({ 60, 20, 20, 30 });
	FJPunch.legColliderFrame.push_back({ 50, 40, 5, 5 });
	FJPunch.speed = 0.15f;

	// Jump Low-Medium Kick Animation
	JLMKick.frames.push_back({ 390, 605, 68, 90 });
	JLMKick.bodyColliderFrame.push_back({ 40, 20, 40, 60 });
	JLMKick.armColliderFrame.push_back({ 40, 20, 5, 5 });
	JLMKick.legColliderFrame.push_back({ 60, 50, 35, 30 });
	JLMKick.frames.push_back({ 459, 605, 83, 90 });
	JLMKick.bodyColliderFrame.push_back({ 40, 20, 30, 60 });
	JLMKick.armColliderFrame.push_back({ 40, 20, 5, 5 });
	JLMKick.legColliderFrame.push_back({ 70, 70, 40, 20 });
	JLMKick.frames.push_back({ 541, 605, 68, 90 });
	JLMKick.bodyColliderFrame.push_back({ 40, 20, 40, 60 });
	JLMKick.armColliderFrame.push_back({ 40, 20, 5, 5 });
	JLMKick.legColliderFrame.push_back({ 60, 50, 35, 30 });
	JLMKick.speed = 0.15f;

	// Jump High Kick Animation
	JHKick.frames.push_back({ 610, 610, 92, 90 });
	JHKick.bodyColliderFrame.push_back({ 40, 20, 60, 40 });
	JHKick.armColliderFrame.push_back({ 55, 10, 30, 20 });
	JHKick.legColliderFrame.push_back({ 90, 50, 30, 35 });
	JHKick.frames.push_back({ 704, 610, 107, 90 });
	JHKick.bodyColliderFrame.push_back({ 40, 20, 40, 60 });
	JHKick.armColliderFrame.push_back({ 40, 20, 5, 5 });
	JHKick.legColliderFrame.push_back({ 60, 50, 35, 30 });
	JHKick.frames.push_back({ 810, 610, 92, 90 });
	JHKick.bodyColliderFrame.push_back({ 40, 20, 60, 40 });
	JHKick.armColliderFrame.push_back({ 55, 10, 30, 20 });
	JHKick.legColliderFrame.push_back({ 90, 50, 30, 35 });
	JHKick.speed = 0.15f;

	// Electric Shock Animation
	ElectricShock.frames.push_back({ 5, 695, 60, 108 });
	ElectricShock.bodyColliderFrame.push_back({ 40, 40, 50, 65 });
	ElectricShock.armColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.legColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.frames.push_back({ 67, 695, 57, 108 });
	ElectricShock.bodyColliderFrame.push_back({ 40, 40, 50, 65 });
	ElectricShock.armColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.legColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.frames.push_back({ 129, 695, 61, 108 });
	ElectricShock.bodyColliderFrame.push_back({ 40, 40, 50, 65 });
	ElectricShock.armColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.legColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.frames.push_back({ 193, 695, 57, 108 });
	ElectricShock.bodyColliderFrame.push_back({ 40, 40, 50, 65 });
	ElectricShock.armColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.legColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.frames.push_back({ 255, 695, 79, 108 });
	ElectricShock.bodyColliderFrame.push_back({ 35, 35, 70, 70 });
	ElectricShock.armColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.legColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.frames.push_back({ 337, 695, 55, 108 });
	ElectricShock.bodyColliderFrame.push_back({ 40, 40, 50, 65 });
	ElectricShock.armColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.legColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.frames.push_back({ 395, 695, 79, 108 });
	ElectricShock.bodyColliderFrame.push_back({ 35, 35, 70, 70 });
	ElectricShock.armColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.legColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.frames.push_back({ 477, 695, 55, 108 });
	ElectricShock.bodyColliderFrame.push_back({ 40, 40, 50, 65 });
	ElectricShock.armColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.legColliderFrame.push_back({ 40, 40, 5, 5 });
	ElectricShock.speed = 0.1f;

	// Roll Attack Animation
	RollAttack.frames.push_back({ 565, 700, 53, 108 });
	RollAttack.bodyColliderFrame.push_back({ 35, 35, 50, 45 });
	RollAttack.armColliderFrame.push_back({ 40, 40, 5, 5 });
	RollAttack.legColliderFrame.push_back({ 40, 40, 5, 5 });
	RollAttack.frames.push_back({ 628, 700, 57, 108 });
	RollAttack.bodyColliderFrame.push_back({ 35, 35, 50, 45 });
	RollAttack.armColliderFrame.push_back({ 40, 40, 5, 5 });
	RollAttack.legColliderFrame.push_back({ 40, 40, 5, 5 });
	RollAttack.frames.push_back({ 700, 700, 55, 108 });
	RollAttack.bodyColliderFrame.push_back({ 35, 35, 50, 45 });
	RollAttack.armColliderFrame.push_back({ 40, 40, 5, 5 });
	RollAttack.legColliderFrame.push_back({ 40, 40, 5, 5 });
	RollAttack.frames.push_back({ 770, 700, 59, 108 });
	RollAttack.bodyColliderFrame.push_back({ 40, 35, 50, 45 });
	RollAttack.armColliderFrame.push_back({ 40, 40, 5, 5 });
	RollAttack.legColliderFrame.push_back({ 40, 40, 5, 5 });
	RollAttack.frames.push_back({ 843, 700, 72, 115 });
	RollAttack.bodyColliderFrame.push_back({ 45, 20, 45, 75 });
	RollAttack.armColliderFrame.push_back({ 40, 40, 5, 5 });
	RollAttack.legColliderFrame.push_back({ 40, 40, 5, 5 });
	RollAttack.frames.push_back({ 923, 701, 63, 115 });
	RollAttack.bodyColliderFrame.push_back({ 40, 30, 50, 55 });
	RollAttack.armColliderFrame.push_back({ 40, 40, 5, 5 });
	RollAttack.legColliderFrame.push_back({ 40, 40, 5, 5 });
	RollAttack.speed = 0.15f;

	// Vertical Rolling Attack Animation
	VRollAttack.frames.push_back({ 9, 801, 65, 108 });
	VRollAttack.frames.push_back({ 81, 801, 53, 108 });
	VRollAttack.frames.push_back({ 140, 801, 55, 108 });
	VRollAttack.frames.push_back({ 211, 801, 47, 108 });
	VRollAttack.frames.push_back({ 275, 801, 51, 108 });
	VRollAttack.frames.push_back({ 339, 801, 102, 108 });
	VRollAttack.frames.push_back({ 463, 801, 79, 108 });
	VRollAttack.frames.push_back({ 570, 801, 80, 108 });
	VRollAttack.frames.push_back({ 673, 801, 81, 108 });
	VRollAttack.frames.push_back({ 770, 801, 50, 108 });
	VRollAttack.speed = 0.1f;

	// Beast Leap Animation
	BeastLeap.frames.push_back({ 0, 917, 65, 108 });
	BeastLeap.frames.push_back({ 67, 917, 40, 108 });
	BeastLeap.frames.push_back({ 115, 917, 101, 108 });
	BeastLeap.frames.push_back({ 221, 917, 80, 108 });
	BeastLeap.frames.push_back({ 303, 917, 101, 108 });
	BeastLeap.frames.push_back({ 406, 917, 40, 108 });
	BeastLeap.frames.push_back({ 447, 917, 69, 108 });
	BeastLeap.frames.push_back({ 516, 917, 68, 108 });
	BeastLeap.frames.push_back({ 585, 917, 52, 108 });
	BeastLeap.frames.push_back({ 637, 917, 55, 108 });
	BeastLeap.frames.push_back({ 693, 917, 53, 108 });
	BeastLeap.frames.push_back({ 745, 917, 55, 108 });
	BeastLeap.frames.push_back({ 801, 917, 63, 108 });
	BeastLeap.speed = 0.1f;

	// Head Bite Grab Animation
	HeadBiteGrab.frames.push_back({ 115, 1046, 67, 108 });
	HeadBiteGrab.frames.push_back({ 187, 1046, 70, 108 });
	HeadBiteGrab.frames.push_back({ 259, 1046, 63, 108 });
	HeadBiteGrab.frames.push_back({ 323, 1046, 69, 108 });
	HeadBiteGrab.frames.push_back({ 403, 1046, 62, 108 });
	HeadBiteGrab.frames.push_back({ 481, 1046, 103, 108 });
	HeadBiteGrab.frames.push_back({ 597, 1046, 84, 108 });
	HeadBiteGrab.frames.push_back({ 697, 1046, 88, 108 });
	HeadBiteGrab.frames.push_back({ 798, 1046, 66, 108 });
	HeadBiteGrab.speed = 0.1f;

	// Hit Animation
	Hit.frames.push_back({ 4, 1155, 64, 108 });
	Hit.frames.push_back({ 71, 1155, 71, 108 });
	Hit.speed = 0.12f;
	Hit.colisionable = false;

	// Head Hit Animation
	HeadHit.frames.push_back({ 4, 1155, 64, 108 });
	HeadHit.frames.push_back({ 71, 1155, 71, 108 });
	HeadHit.frames.push_back({ 144, 1155, 84, 108 });
	HeadHit.frames.push_back({ 229, 1155, 61, 108 });
	HeadHit.speed = 0.12f;
	HeadHit.colisionable = false;

	// Heavy Hit Animation
	HeavyHit.frames.push_back({ 300, 1155, 67, 108 });
	HeavyHit.frames.push_back({ 370, 1155, 68, 108 });
	HeavyHit.frames.push_back({ 438, 1155, 67, 108 });
	HeavyHit.speed = 0.12f;
	HeavyHit.colisionable = false;

	// Stunned Animation
	Stunned.frames.push_back({ 507, 1155, 57, 108 });
	Stunned.frames.push_back({ 563, 1155, 60, 108 });
	Stunned.frames.push_back({ 625, 1155, 60, 108 });
	Stunned.speed = 0.12f;

	// Block Animation
	Block.frames.push_back({ 1009, 249, 63, 108 });
	Block.frames.push_back({ 1074, 249, 63, 108 });
	Block.speed = 0.1f;
	Block.colisionable = false;

	// Knockdown Animation
	Knockdown.frames.push_back({ 2, 1265, 61, 112 });
	Knockdown.frames.push_back({ 61, 1265, 67, 112 });
	Knockdown.frames.push_back({ 133, 1265, 82, 112 });
	Knockdown.frames.push_back({ 215, 1265, 99, 112 });
	Knockdown.frames.push_back({ 313, 1265, 110, 112 });
	Knockdown.speed = 0.12f;
	Knockdown.colisionable = false;


	// Recover Animation
	Recover.frames.push_back({ 424, 1268, 62, 112 });
	Recover.frames.push_back({ 497, 1268, 102, 112 });
	Recover.frames.push_back({ 602, 1268, 83, 112 });
	Recover.frames.push_back({ 687, 1268, 90, 112 });
	Recover.frames.push_back({ 780, 1268, 84, 112 });
	Recover.frames.push_back({ 868, 1268, 63, 112 });
	Recover.speed = 0.12f;
	Recover.colisionable = false;

	// KO Animation
	KO.frames.push_back({ 2, 1378, 66, 112 });
	KO.frames.push_back({ 68, 1378, 82, 112 });
	KO.frames.push_back({ 150, 1378, 98, 112 });
	KO.frames.push_back({ 248, 1378, 82, 112 });
	KO.frames.push_back({ 331, 1378, 110, 112 });
	KO.speed = 0.12f;
	KO.colisionable = false;

	// Time over Animation
	TimeOver.frames.push_back({ 1119, 1378, 63, 112 });
	TimeOver.speed = 0.12f;
	TimeOver.colisionable = false;

	// Victory 1 Animation
	Victory1.frames.push_back({ 442, 1379, 63, 112 });
	Victory1.frames.push_back({ 504, 1379, 64, 112 });
	Victory1.frames.push_back({ 570, 1379, 69, 112 });
	Victory1.frames.push_back({ 639, 1379, 65, 112 });
	Victory1.frames.push_back({ 704, 1379, 70, 112 });
	Victory1.frames.push_back({ 773, 1379, 63, 112 });
	Victory1.frames.push_back({ 836, 1379, 61, 112 });
	Victory1.frames.push_back({ 897, 1379, 61, 112 });
	Victory1.frames.push_back({ 959, 1379, 84, 112 });
	Victory1.frames.push_back({ 1043, 1379, 70, 112 });
	Victory1.speed = 0.12f;
	Victory1.colisionable = false;

	// Victory 2 Animation
	Victory2.frames.push_back({ 5, 1640, 68, 140 });
	Victory2.frames.push_back({ 77, 1640, 71, 140 });
	Victory2.frames.push_back({ 157, 1640, 71, 140 });
	Victory2.frames.push_back({ 232, 1640, 72, 140 });
	Victory2.frames.push_back({ 312, 1640, 71, 140 });
	Victory2.colisionable = false;
	Victory2.speed = 0.12f;
}

ModulePlayerBlanka2::~ModulePlayerBlanka2()
{
}

// Load assets
bool ModulePlayerBlanka2::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("Blanka.png");
	SDL_SetTextureColorMod(graphics, 50, 50, 255);
	fxPunch = App->audio->LoadFx("Big_Punch.wav");
	fxKick = App->audio->LoadFx("short_kick.wav");
	fxLose = App->audio->LoadFx("39H.wav");

	position.x = 380;
	position.y = 110;
	life = 262;
	typeAnim = LOOP;
	time = clock();
	bodyCollider = App->collision->AddCollider({ 0, 0, 30, 75 }, COLLIDER_PLAYER2, this, true);
	armCollider = App->collision->AddCollider({ 0, 0, 20, 20 }, COLLIDER_PLAYER2, this, false, true);
	legCollider = App->collision->AddCollider({ 0, 0, 20, 20 }, COLLIDER_PLAYER2, this, false, false, true);
	return true;
}

// Unload assets
bool ModulePlayerBlanka2::CleanUp()
{
	LOG("Unloading player");
	App->textures->Unload(graphics);

	return true;
}

// Update
update_status ModulePlayerBlanka2::Update()
{

	/*
	^ - Up
	v - Down
	< - Left
	> - Right
	L - High Punch
	X - Middle Punch
	Y - Low Punch
	R - High Kick
	A - Middle Kick
	B - Low Kick
	Start - Pause
	Select - Unused
	*/

	if (clock() - time < 6000){
		texture = idle.GetCurrentFrame(loopAnim, body, arm, leg);
		if (position.x < App->player->position.x){
			flip = SDL_FLIP_NONE;
			App->renderer->Blit(graphics, position.x, position.y, &texture, flip);
		}
		else{
			flip = SDL_FLIP_HORIZONTAL;
			App->renderer->Blit(graphics, position.x - texture.w + 75, position.y, &texture, flip);
		}
	}else{

		switch (typeAnim){
		case LOOP:
			
			jumpDirection = 0;
			block = false;
			if ((App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_AXIS_RIGHTY) == KEY_DOWN)){
				damage = NONE;
				punchAttacks = 0;
				typeAnim = JUMPING;
				loopAnim = false;
				endJump = false;
				move = &jump;
				move->current_frame = 0;
				if ((App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT) || (App->input->GetKey(SDL_CONTROLLER_AXIS_RIGHTX) == KEY_REPEAT)){
					jumpDirection = 1;
				}
				else{
					if ((App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT) || (App->input->GetKey(SDL_CONTROLLER_AXIS_LEFTX) == KEY_REPEAT)){
						jumpDirection = -1;
					}
				}
			}
			else{
				if ((App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT) || (App->input->GetKey(SDL_CONTROLLER_AXIS_LEFTX) == KEY_REPEAT)){
					punchAttacks = 0;
					if (abs(position.x - App->player->position.x) <= 40){
						if (((App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_AXIS_RIGHTX) == KEY_DOWN)) && ((App->input->GetKey(SDL_SCANCODE_KP_4) == KEY_DOWN) || (App->input->GetKey(SDL_SCANCODE_KP_8) == KEY_DOWN) || (App->input->GetKey(SDL_SCANCODE_KP_7) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_X) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_Y) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_LEFTSHOULDER) == KEY_DOWN)) && counterBack > 10){
							loopAnim = false;
							typeAnim = SINGLE;
							move = &RollAttack;
							counterBack = 0;
							damage = HIGH_DAMAGE;
						}
						if ((App->input->GetKey(SDL_SCANCODE_KP_4) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_X) == KEY_DOWN)){
							damage = LOW_DAMAGE;
							loopAnim = false;
							typeAnim = SINGLE;
							move = &FLPunch;
							counterBack = 0;
						}
						else{
							if ((App->input->GetKey(SDL_SCANCODE_KP_8) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_Y) == KEY_DOWN)){
								damage = MEDIUM_DAMAGE;
								loopAnim = false;
								typeAnim = SINGLE;
								move = &FMPunch;
								counterBack = 0;
							}
							else{
								if ((App->input->GetKey(SDL_SCANCODE_KP_5) == KEY_DOWN) || (App->input->GetKey(SDL_SCANCODE_KP_9) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_A) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_B) == KEY_DOWN)){
									damage = HIGH_DAMAGE;
									loopAnim = false;
									typeAnim = SINGLE;
									move = &FLMKick;
									counterBack = 0;
								}
								else{
									damage = NONE;
									counterBack++;
									move = &walk;
									if (flip == SDL_FLIP_NONE){
										block = true;
									}
								}
							}
						}
					}
					else{
							if (((App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_AXIS_RIGHTX) == KEY_DOWN)) && ((App->input->GetKey(SDL_SCANCODE_KP_4) == KEY_DOWN) || (App->input->GetKey(SDL_SCANCODE_KP_8) == KEY_DOWN) || (App->input->GetKey(SDL_SCANCODE_KP_7) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_X) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_Y) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_LEFTSHOULDER) == KEY_DOWN)) && counterBack > 10){
								loopAnim = false;
								typeAnim = SINGLE;
								move = &RollAttack;
								counterBack = 0;
								damage = HIGH_DAMAGE;
							}
							else{
								damage = NONE;
								counterBack++;
								move = &walk;
								if (flip == SDL_FLIP_NONE){
									block = true;
								}
							}
						}

					if ((position.x - 1 > 65) && (abs((position.x - App->player->position.x - 40)*SCREEN_SIZE) < App->renderer->camera.w) && (move == &walk)) {
						if (flip == SDL_FLIP_HORIZONTAL){
							if (position.x - 15 > App->player->position.x + 15){
								--position.x;
							}
						}
						else{
							--position.x;
						}
					}
				}
				else{
					counterBack = 0;
					if ((App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT) || (App->input->GetKey(SDL_CONTROLLER_AXIS_LEFTY) == KEY_REPEAT)){
						punchAttacks = 0;

						if ((App->input->GetKey(SDL_SCANCODE_KP_4) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_X) == KEY_DOWN)){
							damage = LOW_DAMAGE;
							move = &CLPunch;
							typeAnim = SINGLE;
							loopAnim = false;
						}
						else{
							if ((App->input->GetKey(SDL_SCANCODE_KP_8) == KEY_DOWN) || (App->input->GetKey(SDL_SCANCODE_KP_7) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_Y) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_LEFTSHOULDER) == KEY_DOWN)){
								damage = HIGH_DAMAGE;
								move = &CMHPunch;
								typeAnim = SINGLE;
								loopAnim = false;
							}
							else{
								if ((App->input->GetKey(SDL_SCANCODE_KP_5) == KEY_DOWN) || (App->input->GetKey(SDL_SCANCODE_KP_9) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_A) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_B) == KEY_DOWN)){
									damage = LOW_DAMAGE;
									move = &CLMKick;
									typeAnim = SINGLE;
									loopAnim = false;
								}
								else{
									if ((App->input->GetKey(SDL_SCANCODE_KP_PLUS) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) == KEY_DOWN)){
										damage = HIGH_DAMAGE;
										move = &CHKick;
										typeAnim = SINGLE;
										loopAnim = false;
									}
									else{
										damage = NONE;
										move = &crouchDown;
									}
								}
							}
						}
					}
					else{
						if ((App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_UP) || (App->input->GetKey(SDL_CONTROLLER_AXIS_LEFTY) == KEY_UP)){
							damage = NONE;
							typeAnim = SINGLE;
							loopAnim = false;
							move = &crouchUp;
						}
						else{
							if ((App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT) || (App->input->GetKey(SDL_CONTROLLER_AXIS_RIGHTX) == KEY_REPEAT)){
								punchAttacks = 0;
								if (abs(position.x - App->player->position.x) <= 20){
									if ((App->input->GetKey(SDL_SCANCODE_KP_8) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_Y) == KEY_DOWN)){
										loopAnim = false;
										typeAnim = SINGLE;
										move = &FMPunch;
										counterBack = 0;
										damage = MEDIUM_DAMAGE;
									}
									else{
										if ((App->input->GetKey(SDL_SCANCODE_KP_5) == KEY_DOWN) || (App->input->GetKey(SDL_SCANCODE_KP_9) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_B) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_A) == KEY_DOWN)){
											loopAnim = false;
											typeAnim = SINGLE;
											move = &FLMKick;
											counterBack = 0;
											damage = LOW_DAMAGE;
										}
										else{
											if ((App->input->GetKey(SDL_SCANCODE_KP_4) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_X) == KEY_DOWN)){
												loopAnim = false;
												typeAnim = SINGLE;
												move = &FLPunch;
												counterBack = 0;
												damage = LOW_DAMAGE;
											}
											else{
												damage = NONE;
												move = &walk;
												counterBack = 0;
												if (flip != SDL_FLIP_NONE){
													block = true;
												}
											}
										}
									}
								}
								else{
									damage = NONE;
									move = &walk;
									counterBack = 0;
									if (flip != SDL_FLIP_NONE){
										block = true;
									}
								}

								if ((position.x + 1 < 480) && (abs((position.x - App->player->position.x + 50)*SCREEN_SIZE) < App->renderer->camera.w) && (move == &walk)) {
									if (flip == SDL_FLIP_NONE){
										if (position.x + 15 < App->player->position.x - 15){
											++position.x;
										}
									}
									else{
										++position.x;
									}
								}
							}
							else{
								if ((App->input->GetKey(SDL_SCANCODE_KP_4) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_X) == KEY_DOWN)){
									if (punchAttacks > 2){
										damage = HIGH_DAMAGE;
										typeAnim = ELECTRIC;
										move = &ElectricShock;
									}
									else{
										damage = LOW_DAMAGE;
										++punchAttacks;
										typeAnim = SINGLE;
										loopAnim = false;
										move = &LPunch;
									}
								}
								else{
									if ((App->input->GetKey(SDL_SCANCODE_KP_8) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_Y) == KEY_DOWN)){
										if (punchAttacks == 3){
											damage = HIGH_DAMAGE;
											typeAnim = ELECTRIC;
											move = &ElectricShock;
										}
										else{
											damage = MEDIUM_DAMAGE;
											++punchAttacks;
											typeAnim = SINGLE;
											loopAnim = false;
											move = &MPunch;
										}
									}
									else{
										if (counter > 20){		//change to timer
											punchAttacks = 0;
											counter = 0;
										}
										++counter;
										if ((App->input->GetKey(SDL_SCANCODE_KP_7) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_LEFTSHOULDER) == KEY_DOWN)){
											damage = HIGH_DAMAGE;
											typeAnim = SINGLE;
											loopAnim = false;
											move = &HPunch;
										}
										else{
											if ((App->input->GetKey(SDL_SCANCODE_KP_5) == KEY_DOWN) || (App->input->GetKey(SDL_SCANCODE_KP_9) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_A) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_B) == KEY_DOWN)){
												damage = MEDIUM_DAMAGE;
												typeAnim = SINGLE;
												loopAnim = false;
												move = &LMKick;
											}
											else{
												if ((App->input->GetKey(SDL_SCANCODE_KP_PLUS) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) == KEY_DOWN)){
													damage = HIGH_DAMAGE;
													typeAnim = SINGLE;
													loopAnim = false;
													move = &HKick;
												}
												else{
													damage = NONE;
													move = &idle;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			break;


		case SINGLE:
			if ((move == &RollAttack) && (texture.x != 843) && (texture.x != 923)){
				if (flip == SDL_FLIP_NONE){
					position.x = position.x + 2;
				}
				else{
					position.x = position.x - 2;
				}
			}

			if (move == &Recover){
				if (flip == SDL_FLIP_NONE){
					position.x = position.x - 2;
				}
				else{
					position.x = position.x + 2;
				}
			}

			if (move == &KO){
				if (texture.x != 331){
					texture = move->GetCurrentFrame(loopAnim, body, arm, leg);
				}

				if (flip == SDL_FLIP_NONE){
					if (texture.x != 331){
						position.x = position.x - 3;
					}
					App->renderer->Blit(graphics, position.x, position.y, &texture, flip);
				}
				else{
					if (texture.x != 331){
						position.x = position.x + 3;
					}
					App->renderer->Blit(graphics, position.x - texture.w + 75, position.y, &texture, flip);
				}
			}

			if ((loopAnim == true) && (move != &KO) && (move != &Victory1)){
				typeAnim = LOOP;
			}
			break;


		case JUMPING:
			jumpMove = move->GetCurrentFrame(loopAnim, body, arm, leg);

			if (jumpAttack == false){
				if ((App->input->GetKey(SDL_SCANCODE_KP_4) == KEY_DOWN) || (App->input->GetKey(SDL_SCANCODE_KP_8) == KEY_DOWN) || (App->input->GetKey(SDL_SCANCODE_KP_7) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_X) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_Y) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_LEFTSHOULDER) == KEY_DOWN)){
					damage = MEDIUM_DAMAGE;
					jumpAttack = true;
					loopAnim = false;
					if ((abs(position.x - App->player->position.x) <= 20) && (abs(position.y - App->player->position.y) <= 80)){
						move = &FJPunch;
					}
					else{
						move = &JPunch;
					}
				}
				else{
					if ((App->input->GetKey(SDL_SCANCODE_KP_5) == KEY_DOWN) || (App->input->GetKey(SDL_SCANCODE_KP_9) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_A) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_B) == KEY_DOWN)){
						damage = MEDIUM_DAMAGE;
						jumpAttack = true;
						loopAnim = false;
						move = &JLMKick;
					}
					else{
						if ((App->input->GetKey(SDL_SCANCODE_KP_PLUS) == KEY_DOWN) || (App->input->GetKey(SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) == KEY_DOWN)){
							damage = HIGH_DAMAGE;
							jumpAttack = true;
							loopAnim = false;
							move = &JHKick;
						}
					}
				}
			}

			if (jumpMove.x != 646){
				// control jump (up and down)
				if ((position.y > 10) && (endJump == false)){
					position.y = position.y - 4;
				}
				else{
					if (position.y < 115){
						endJump = true;
						position.y = position.y + 4;
					}
				}

				// control jump (left and right)
				if ((jumpDirection != 0) && ((position.x + 1 < 480) && (position.x - 1 > 65)) && (abs((position.x - App->player->position.x - 40)*SCREEN_SIZE) < App->renderer->camera.w) && (abs((position.x - App->player->position.x + 50)*SCREEN_SIZE) < App->renderer->camera.w)) {
					position.x = position.x + jumpDirection;
				}
			}

			// control the render according to animations
			if (loopAnim == true){
				if (position.y <= 110){
					move = &jump;
				}
				else{
					typeAnim = LOOP;
					jumpAttack = false;
					endJump = false;
				}
			}


			//render the jump and shadow
			texture = move->GetCurrentFrame(loopAnim, body, arm, leg);
			if (position.x < App->player->position.x){
				flip = SDL_FLIP_NONE;
				App->renderer->Blit(graphics, position.x, position.y, &texture, flip);
				if (jumpMove.x != 646){
					App->renderer->Blit(graphics, position.x, 175, &shadow, flip);
				}
			}
			else{
				flip = SDL_FLIP_HORIZONTAL;
				App->renderer->Blit(graphics, position.x - texture.w + 75, position.y, &texture, flip);
				if (jumpMove.x != 646){
					App->renderer->Blit(graphics, position.x - texture.w + 75, 175, &shadow, flip);
				}
			}

			break;


		case ELECTRIC:
			if (counter > 50){			// change to timer
				if ((App->input->GetKey(SDL_SCANCODE_KP_4) != KEY_DOWN) && (App->input->GetKey(SDL_SCANCODE_KP_8) != KEY_DOWN) && (App->input->GetKey(SDL_CONTROLLER_BUTTON_X) != KEY_DOWN) && (App->input->GetKey(SDL_CONTROLLER_BUTTON_Y) != KEY_DOWN)){
					typeAnim = LOOP;
				}
				counter = 0;
			}
			++counter;
			break;
		}

		//render if is not a jump because the jump has a special animation
		if ((typeAnim != JUMPING) && (move != &KO)){
			texture = move->GetCurrentFrame(loopAnim, body, arm, leg);

			if (position.x < App->player->position.x){
				flip = SDL_FLIP_NONE;
				App->renderer->Blit(graphics, position.x, position.y, &texture, flip);
			}
			else{
				flip = SDL_FLIP_HORIZONTAL;
				App->renderer->Blit(graphics, position.x - texture.w + 75, position.y, &texture, flip);
			}
		}

		if ((App->renderer->camera.x) < -(position.x*SCREEN_SIZE)){
			++App->renderer->camera.x;
		}
		else{
			if ((App->renderer->camera.x - App->renderer->camera.w) >  -((position.x + 50)*SCREEN_SIZE)){
				--App->renderer->camera.x;
			}
		}

		//Update of colliders depending if the texture is flip or not
		if (flip == SDL_FLIP_NONE){
			bodyCollider->SetCollider(body, position.x - 30, position.y);
			armCollider->SetCollider(arm, position.x - 30, position.y);
			legCollider->SetCollider(leg, position.x - 30, position.y);
		}
		else{
			bodyCollider->SetCollider(body, position.x + texture.w + 30, position.y, true);
			armCollider->SetCollider(arm, position.x + texture.w + 30, position.y, true);
			legCollider->SetCollider(leg, position.x + texture.w + 30, position.y, true);
		}
	}
	return UPDATE_CONTINUE;
}

void ModulePlayerBlanka2::OnCollision(const Collider* colliderA, const Collider* colliderB){
	if (colliderB->type == PLAYER1){
		if (damage == NONE){
			if (App->player->damage != NONE){
				if (block == false){
					if (move == &jump){
						position.y = 110;
					}
					if (App->player->damage == LOW_DAMAGE){
						if ((App->player->move == &CLPunch) || (App->player->move == &CLMKick)){
							life = life - 12;
						}
						else{
							life = life - 14;
						}
						App->audio->PlayFx(fxKick);
						typeAnim = SINGLE;
						loopAnim = false;
						move = &Hit;
					}
					else{
						if (App->player->damage == MEDIUM_DAMAGE){
							if (App->player->move == &FMPunch){
								life = life - 18;
							}
							else{
								if (App->player->move == &MPunch){
									life = life - 20;
								}
								else{
									if (App->player->move == &JLMKick){
										life = life - 24;
									}
									else{
										life = life - 26;
									}
								}
							}
							App->audio->PlayFx(fxPunch);
							typeAnim = SINGLE;
							loopAnim = false;
							move = &Hit;
						}
						else{
							if (App->player->damage == HIGH_DAMAGE){
								if ((App->player->move == &FJPunch) || (App->player->move == &JHKick)){
									life = life - 30;
								}
								else{
									life = life - 28;
								}
								App->audio->PlayFx(fxPunch, 1);
								typeAnim = SINGLE;
								loopAnim = false;
								move = &HeavyHit;
							}
						}
					}
				}
				else{
					typeAnim = SINGLE;
					loopAnim = false;
					move = &Block;
				}
				App->player->damage = NONE;
			}
		}
		else{
			if (move == &RollAttack){
				typeAnim = SINGLE;
				loopAnim = false;
				move = &Recover;
			}
		}

		if ((life < 1) && (move != &KO)){
			CombatEnd(false);
			App->player->CombatEnd(false);
			App->audio->PlayFx(fxLose);
		}
	}
}

void ModulePlayerBlanka2::CombatEnd(const bool time){
	bodyCollider->SetCollider(body, 0, 0);
	armCollider->SetCollider(arm, 0, 0);
	legCollider->SetCollider(leg, 0, 0);
	if (time == true){
		typeAnim = SINGLE;
		loopAnim = false;
		if (life > App->player->life){
			move = &Victory1;
		}
		else{
			move = &TimeOver;
		}
	}
	else{
		if (life > 0){
			typeAnim = SINGLE;
			loopAnim = false;
			move = &Victory1;
		}
		else{
			typeAnim = SINGLE;
			loopAnim = false;
			move = &KO;
		}
	}
}