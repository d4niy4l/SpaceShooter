#pragma once
struct point {
public:
	float x, y;
	point(float x, float y);
	float dotProduct(point& p);
	point operator - (point& p);
};

