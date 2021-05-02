/*
 * Shape.cpp
 *
 *  Created on: Feb 13, 2021
 *      Author: sherif
 */

#include <Shape.h>

void Shape::MoveBy(const Vec2D &mypoint) {

	for (auto i : mPoints)
		i = i + mypoint;
	//for (auto it = mPoints.begin(); it != mPoints.end(); it++)
		//*it++;
}
