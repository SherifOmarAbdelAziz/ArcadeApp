/*
 * GameController.h
 *
 *  Created on: May 2, 2021
 *      Author: sherif
 */

#ifndef INPUT_GAMECONTROLLER_H_
#define INPUT_GAMECONTROLLER_H_

#include <vector>
#include "inputAction.h"
using namespace std;

class GameController {
public:
	GameController();
	ButtonAction* GetActionForKey(inputKey Key);
	void AddActionForKey(const ButtonAction& KeyAction);

	static bool IsPressed(inputState state);
	static bool IsReleased(inputState state);
	static inputKey ActionKey();
	static inputKey CancelKey();
	static inputKey left();
	static inputKey right();
	static inputKey up();
	static inputKey down();

private:
	vector<ButtonAction> Actions;
};

#endif /* INPUT_GAMECONTROLLER_H_ */
