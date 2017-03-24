#ifndef __MODULECOLLISION_H__
#define __MODULECOLLISION_H__

#include "Module.h"
#include <list>

enum COLLIDER_TYPE
{
	COLLIDER_NONE = -1,
	COLLIDER_PLAYER1,
	COLLIDER_PLAYER2,
	COLLIDER_PLAYER1_SHOT,
	COLLIDER_PLAYER2_SHOT,

	COLLIDER_MAX
};

struct Collider
{
	SDL_Rect rect;
	const COLLIDER_TYPE type;
	Module* callback;
	bool flip;
	bool body;
	bool arm;
	bool leg;

	// Properties of the colliders
	Collider(SDL_Rect rectangle, COLLIDER_TYPE type, Module* callback = NULL, bool body = false, bool arm = false, bool leg = false) :
		rect(rectangle),
		type(type),
		callback(callback),
		flip(false),
		body(body),
		arm(arm),
		leg(leg)
	{}

	void SetCollider(const SDL_Rect &colliderRect, const int x, const int y, const bool fliped = false)
	{
		flip = fliped;
		if (!flip){
			rect.x = colliderRect.x + x;
			rect.y = colliderRect.y + y;
			rect.w = colliderRect.w;
			rect.h = colliderRect.h;
		}
		else{
			rect.x = x - colliderRect.x;
			rect.y = colliderRect.y + y;
			rect.w = -colliderRect.w;
			rect.h = colliderRect.h;
		}
	}

	bool CheckCollision(const SDL_Rect r) const;
};

class ModuleCollision : public Module
{
public:

	ModuleCollision();
	~ModuleCollision();

	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

	Collider* AddCollider(const SDL_Rect rect, const COLLIDER_TYPE type, Module* callback = NULL, const bool body = false, const bool arm = false, const bool leg = false);

private:

	std::list<Collider*> colliders;
	bool matrix[COLLIDER_MAX][COLLIDER_MAX];
	bool debug;
};

#endif // __MODULECOLLISION_H__
