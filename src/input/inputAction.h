/*
 * inputAction.h
 *
 *  Created on: May 2, 2021
 *      Author: sherif
 */

#ifndef INPUT_INPUTACTION_H_
#define INPUT_INPUTACTION_H_


#include <functional>

using inputKey = uint8_t;
using inputState = uint8_t;

using inputAction = std::function<void(uint32_t dt, inputState state)>;

struct ButtonAction {
	inputKey Key;
	inputAction Action;
};

#endif /* INPUT_INPUTACTION_H_ */
