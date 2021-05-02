/*
 * Utils.cpp
 *
 *  Created on: Apr 3, 2021
 *      Author: sherif
 */


#include "Utils.h"

bool IsEqual(float one, float two) {
	if (fabsf(one-two) < EPSILON)
		return true;
	else return false;
}
