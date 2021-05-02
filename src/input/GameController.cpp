/*
 * GameController.cpp
 *
 *  Created on: May 2, 2021
 *      Author: sherif
 */

#include "GameController.h"

GameController::GameController() {
	// TODO Auto-generated constructor stub

}

ButtonAction* GameController::GetActionForKey(inputKey Key) {
	if (Actions.empty()) {
		return [](uint32_t dt, inputState state){};
	}
}
void GameController::AddActionForKey(const ButtonAction& KeyAction) {

}

bool GameController::IsPressed(inputState state) {

}

bool GameController::IsReleased(inputState state) {

}

inputKey GameController::ActionKey() {

}

inputKey GameController::left() {

}

inputKey GameController::right() {

}

inputKey GameController::up() {

}

inputKey GameController::down() {

}
