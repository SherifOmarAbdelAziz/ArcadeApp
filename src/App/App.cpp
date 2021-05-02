/*
 * App.cpp
 *
 *  Created on: Apr 3, 2021
 *      Author: sherif
 */

#include "App.h"
#include "memory.h"
#include "ArcadeScene.h"

App& App::Singleton() {
		static App theApp;
		return theApp;
}

bool App::Init(int mWidth, int mHeight, int mag) {

	unique_ptr<ArcadeScene> Arcade = make_unique<ArcadeScene>();
	mWindow = mScreen.init(mWidth, mHeight, mag);
	Arcade->Init();
	PushScene(move(Arcade));
	return mWindow != nullptr;
}

void App::Run() {

	uint32_t dt = 10;
	uint32_t lastTick = SDL_GetTicks();
	uint32_t CurrentTick = lastTick;
	uint32_t FrameTime = 0;
	uint32_t Accumulator = 0;



    bool running = true;
    SDL_Event event;
    while(running) {
    	CurrentTick = SDL_GetTicks();
    	FrameTime = CurrentTick - lastTick;

    	if (FrameTime > 300)
    		FrameTime = 300;
    	lastTick = CurrentTick;
    	Accumulator += FrameTime;

    	Scene *topScene = App::TopScene();
    	if (topScene) {
			// input
			while(SDL_PollEvent(&event)) {
				switch(event.type) {
					case SDL_QUIT:
						running = false;
						break;
				}
			}

			// Update
			if (Accumulator >= dt) {
				topScene->update(dt);
				Accumulator -= dt;
			}

			// Render
			topScene->draw(mScreen);
    	}
    	mScreen.SwapScreen();

    }
	cout << "GAME OVER!!!" << endl; // prints !!!Hello World!!!
}


void App::PushScene (unique_ptr<Scene> scene) {
	scene->Init();
	SceneStack.emplace_back(std::move(scene));
	SDL_SetWindowTitle(mWindow , TopScene()->GetSceneName().c_str());
}

void App::PopScene () {
	if (SceneStack.size() > 1) {
		SceneStack.pop_back();
	}
	SDL_SetWindowTitle(mWindow , TopScene()->GetSceneName().c_str());
}

Scene* App::TopScene() {
	if (SceneStack.empty())
		return nullptr;
	else
		return SceneStack.back().get();
}
