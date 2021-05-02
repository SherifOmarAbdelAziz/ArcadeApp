/*
 * AARectangle.cpp
 *
 *  Created on: Feb 13, 2021
 *      Author: sherif
 */

#include <AARectangle.h>
#include <vector>
using namespace std;

void AARectangle::MoveTo(const Vec2D &p) {
	setTopLeftPoint(p);
	setBottomRightPoint(Vec2D(p.GetVec2Dx()+GetWidth()-1, p.GetVec2Dy()+GetHeight()-1));
}

bool AARectangle::ContainsPoint(const Vec2D &p) {
	return (
			(p.GetVec2Dx() >= GetTopLeftPoint().GetVec2Dx()) &&
			(p.GetVec2Dx() <= GetBottomRightPoint().GetVec2Dx()) &&
			(p.GetVec2Dy() >= GetTopLeftPoint().GetVec2Dy()) &&
			(p.GetVec2Dy() <= GetBottomRightPoint().GetVec2Dy())
					);
}

bool AARectangle::intersects(const AARectangle& rect) const {
	return !(
		(GetTopLeftPoint().GetVec2Dx() >  rect.GetBottomRightPoint().GetVec2Dx()) ||
		(GetBottomRightPoint().GetVec2Dx() <  rect.GetTopLeftPoint().GetVec2Dx()) ||
		(GetTopLeftPoint().GetVec2Dy() >  rect.GetBottomRightPoint().GetVec2Dy()) ||
		(GetBottomRightPoint().GetVec2Dy() <  rect.GetTopLeftPoint().GetVec2Dy())
	);
}

Vec2D AARectangle::GetCenterPoint() const {
	return Vec2D(0.5*(GetTopLeftPoint().GetVec2Dx()+GetWidth())
		,0.5*(GetTopLeftPoint().GetVec2Dy()+GetHeight()));
}

vector<Vec2D> AARectangle::GetPoints() {
	vector<Vec2D> rect_points;
	rect_points.push_back(GetTopLeftPoint());

	rect_points.push_back(Vec2D(GetTopLeftPoint().GetVec2Dx(),
			GetBottomRightPoint().GetVec2Dy()));

	rect_points.push_back(GetBottomRightPoint());

	rect_points.push_back(Vec2D(GetBottomRightPoint().GetVec2Dx(),
			GetTopLeftPoint().GetVec2Dy()));

	return rect_points;
}

AARectangle AARectangle::inset(const AARectangle& rect, const Vec2D& p) {
	return AARectangle(rect.GetTopLeftPoint()+p, rect.GetWidth()- (2*p.GetVec2Dx()),
			rect.GetHeight()- (2*p.GetVec2Dy())
	);
}




