#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "SDL/include/SDL_rect.h"

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);

void log(const char file[], int line, const char* format, ...);

enum animation_type_player
{
	LOOP,
	JUMPING,
	ELECTRIC,
	SINGLE,
	PAUSE
};

enum attack_damage
{
	LOW_DAMAGE,
	MEDIUM_DAMAGE,
	HIGH_DAMAGE,
	NONE
};

enum collider_type
{
	PLAYER1,
	PLAYER2,
	PARTICLE
};

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};

// Deletes a buffer
#define RELEASE( x ) \
    {\
       if( x != nullptr )\
       {\
         delete x;\
	     x = nullptr;\
       }\
    }

// Deletes an array of buffers
#define RELEASE_ARRAY( x ) \
	{\
       if( x != nullptr )\
       {\
           delete[] x;\
	       x = nullptr;\
		 }\
	 }

// Configuration -----------
#define SCREEN_WIDTH 384
#define SCREEN_HEIGHT 224
#define SCREEN_SIZE 2
#define FULLSCREEN false
#define VSYNC true
#define TITLE "Super Street Fighter 2"

#endif //__GLOBALS_H__