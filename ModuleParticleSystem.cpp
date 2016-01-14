#include "ModuleParticleSystem.h"

ModuleParticleSystem::ModuleParticleSystem()
{
}


ModuleParticleSystem::~ModuleParticleSystem()
{
}

update_status ModuleParticleSystem::Update(){
	bool loopAnim = false;

	//The life of the particles is controlled with SDL_GetTicks 
	currentTime = SDL_GetTicks();
	for (int i = 0; i < particlesVector.size(); i++){
		particlesVector[i]->position.x += 1;
		App->renderer->Blit(particlesVector[i]->particleGraphic, particlesVector[i]->position.x, particlesVector[i]->position.y, &(particlesVector[i]->particleAnimation.GetCurrentFrame(loopAnim)), 1.0f);
		if ((currentTime - particlesVector[i]->startTime) > particlesVector[i]->timeToLive){
			removeParticle(i);
		}
	}
	return UPDATE_CONTINUE;
}

void ModuleParticleSystem::addParticle(SDL_Texture* particleGraphic, Animation particleAnimation, iPoint position, float speed, int timeToLive)
{
	LOG("Creating particle System");
	Particle* newParticle = new Particle();
	newParticle->particleAnimation = particleAnimation;
	newParticle->particleGraphic = particleGraphic;
	newParticle->position = position;
	newParticle->speed = speed;
	newParticle->timeToLive = timeToLive;
	newParticle->startTime = currentTime;
	particlesVector.push_back(newParticle);
}

void ModuleParticleSystem::removeParticle(int i){
	particlesVector.erase(particlesVector.begin()+i);
}

bool ModuleParticleSystem::CleanUp(){
	LOG("Unloading particle system");
	
	return true;
}
