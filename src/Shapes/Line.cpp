/*
 * Line.cpp
 *
 *  Created on: Jan 16, 2021
 *      Author: sherif
 */

#include <Line.h>

Vec2D Line::ClosestPoint(const Vec2D &v) {
	float temp =  mp0.Dot(v);
	Vec2D mp0tov = v - mp0;
	Vec2D mp0tomp1 = mp1 - mp0;
	float t = temp/mp0tov.mag();

	return mp0 + (mp0tomp1 * t);
}

