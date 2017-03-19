#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <vector>

using namespace std;

class Animation
{
public:
	float speed;
	bool colisionable = true;
	bool jumpAnim = false;
	vector<SDL_Rect> frames;
	vector<SDL_Rect> bodyColliderFrame;
	vector<SDL_Rect> armColliderFrame;
	vector<SDL_Rect> legColliderFrame;
	float current_frame;

public:
	Animation() : frames(), speed(1.0f), current_frame(0.0f)
	{}

	SDL_Rect& GetCurrentFrame(bool &loopAnim, SDL_Rect &body, SDL_Rect &arm, SDL_Rect &leg)
	{
		current_frame += speed;
		if (current_frame >= frames.size()){
			loopAnim = true;
			if (jumpAnim == false){
				current_frame = 0.0f;
			}
			else{
				current_frame = (float)(frames.size()-1);
			}
		}

		if (colisionable == true){
			body = bodyColliderFrame[(int)current_frame];
			arm = armColliderFrame[(int)current_frame];
			leg = legColliderFrame[(int)current_frame];
		}

		return frames[(int)current_frame];
	}

	~Animation(){
		frames.clear();
		bodyColliderFrame.clear();
		armColliderFrame.clear();
		legColliderFrame.clear();
	}
};
#endif // __ANIMATION_H__