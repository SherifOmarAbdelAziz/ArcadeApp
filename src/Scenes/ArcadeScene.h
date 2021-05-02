/*
 * ArcadeScene.h
 *
 *  Created on: Apr 10, 2021
 *      Author: sherif
 */

#ifndef SCENES_ARCADESCENE_H_
#define SCENES_ARCADESCENE_H_
#include "Scene.h"

#include <memory>

enum Game {
	Tetris = 0,
	Pacman
};

class ArcadeScene : public Scene {
public:
	virtual ~ArcadeScene();
	virtual void Init();
	virtual void update(uint32_t dt);
	virtual void draw(Screen& mScreen);
	virtual const string& GetSceneName() const;

private:
	std::unique_ptr<ArcadeScene> GetScene(Game eGame);
};

#endif /* SCENES_ARCADESCENE_H_ */
