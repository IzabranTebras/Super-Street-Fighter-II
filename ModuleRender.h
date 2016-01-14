#ifndef __MODULERENDER_H__
#define __MODULERENDER_H__

#include "Module.h"
#include "Globals.h"
#include "SDL/include/SDL.h"

struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

	bool Blit(SDL_Texture* texture, const int x, const int y, const SDL_Rect* section, const SDL_RendererFlip flip = SDL_FLIP_NONE, const float speed = 1.0f);
	bool DrawQuad(const SDL_Rect& rect, const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a, bool use_camera = true);

public:
	SDL_Renderer* renderer = nullptr;
	SDL_Rect camera;
};

#endif // __MODULERENDER_H__