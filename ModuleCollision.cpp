#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

using namespace std;

ModuleCollision::ModuleCollision() : Module()
{
	debug = false;

	matrix[COLLIDER_PLAYER1][COLLIDER_PLAYER1] = false;
	matrix[COLLIDER_PLAYER1][COLLIDER_PLAYER2] = true;
	matrix[COLLIDER_PLAYER1][COLLIDER_PLAYER1_SHOT] = false;
	matrix[COLLIDER_PLAYER1][COLLIDER_PLAYER2_SHOT] = true;

	matrix[COLLIDER_PLAYER2][COLLIDER_PLAYER1] = true;
	matrix[COLLIDER_PLAYER2][COLLIDER_PLAYER2] = false;
	matrix[COLLIDER_PLAYER2][COLLIDER_PLAYER1_SHOT] = true;
	matrix[COLLIDER_PLAYER2][COLLIDER_PLAYER2_SHOT] = false;

	matrix[COLLIDER_PLAYER1_SHOT][COLLIDER_PLAYER1] = false;
	matrix[COLLIDER_PLAYER1_SHOT][COLLIDER_PLAYER2] = true;
	matrix[COLLIDER_PLAYER1_SHOT][COLLIDER_PLAYER1_SHOT] = false;
	matrix[COLLIDER_PLAYER1_SHOT][COLLIDER_PLAYER2_SHOT] = false;

	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER1] = true;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER2] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER1_SHOT] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER2_SHOT] = false;
}

// Destructor
ModuleCollision::~ModuleCollision()
{
}

// Called before render is available
update_status ModuleCollision::Update()
{
	const Collider* c1;
	const Collider* c2;

	for (list<Collider*>::iterator it = colliders.begin(); it != colliders.end();)
	{
		c1 = *it;

		for (list<Collider*>::iterator it2 = ++it; it2 != colliders.end(); ++it2)
		{
			c2 = *it2;

			if (c1->CheckCollision(c2->rect) == true)
			{
				if (matrix[c1->type][c2->type] && c1->callback)
					c1->callback->OnCollision(c1, c2);

				if (matrix[c2->type][c1->type] && c2->callback)
					c2->callback->OnCollision(c2, c1);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleCollision::PostUpdate()
{
	if (App->input->GetKey(SDL_SCANCODE_M) == KEY_DOWN)
		debug = !debug;

	if (debug == true)
	{
		for (list<Collider*>::iterator it = colliders.begin(); it != colliders.end(); ++it)
		{
			Collider* col = *it;
			Uint8 alpha = 100;
			switch (col->type)
			{
			case COLLIDER_NONE:
				App->renderer->DrawQuad(col->rect, 255, 255, 255, alpha);
				break;
			case COLLIDER_PLAYER1:
				App->renderer->DrawQuad(col->rect, 0, 255, 0, alpha);
				break;
			case COLLIDER_PLAYER2:
				App->renderer->DrawQuad(col->rect, 255, 0, 0, alpha);
				break;
			case COLLIDER_PLAYER1_SHOT:
				App->renderer->DrawQuad(col->rect, 255, 255, 0, alpha);
				break;
			case COLLIDER_PLAYER2_SHOT:
				App->renderer->DrawQuad(col->rect, 0, 255, 255, alpha);
				break;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleCollision::CleanUp()
{
	LOG("Freeing all colliders");

	for (list<Collider*>::reverse_iterator it = colliders.rbegin(); it != colliders.rend(); ++it)
		RELEASE(*it);

	colliders.clear();
	return true;
}

Collider* ModuleCollision::AddCollider(const SDL_Rect rect, const COLLIDER_TYPE type, Module* callback, const bool body, const bool arm, const bool leg)
{
	Collider* ret = new Collider(rect, type, callback, body, arm, leg);
	colliders.push_back(ret);
	return ret;
}

// -----------------------------------------------------

bool Collider::CheckCollision(const SDL_Rect r) const
{
	if (flip == true){
		return (r.x < rect.x &&
			r.x + r.w > rect.x + rect.w &&
			rect.y < r.y + r.h &&
			rect.h + rect.y > r.y);
	}

	return (r.x > rect.x &&
		r.x + r.w < rect.x + rect.w &&
		rect.y < r.y + r.h &&
		rect.h + rect.y > r.y);
}