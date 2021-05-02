/*
 * ArcadeScene.cpp
 *
 *  Created on: Apr 10, 2021
 *      Author: sherif
 */

#include "ArcadeScene.h"

ArcadeScene::~ArcadeScene() {
	// TODO Auto-generated destructor stub
}

void ArcadeScene::Init() {

}

void ArcadeScene::update(uint32_t dt) {

}

void ArcadeScene::draw(Screen& mScreen) {
	Circle Circ(Vec2D(mScreen.width()/2+50,mScreen.height()/2+50), 50.0);
	AARectangle rect(Vec2D(mScreen.width()/2-25,mScreen.height()/2-25), 50, 50);

	mScreen.draw(rect, Color::Blue(), true, Color::Blue());
	mScreen.draw(Circ, Color(0,255,0,150), true, Color(0,255,0,150));
}

const string& ArcadeScene::GetSceneName() const {
	static string ArcadeSceneName = "Sherif's Arcade App";
	return ArcadeSceneName;
}

unique_ptr<ArcadeScene> ArcadeScene::GetScene(Game eGame) {
	switch (eGame) {
		case Tetris: {} break;

		case Pacman: {} break;
	}
	return nullptr;
}

