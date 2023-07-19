#include "point.h"
point::point(float x, float y) {
	this->x = x;
	this->y = y;
}
float point::dotProduct(point& p) {
	return p.x * x + p.y * y;
}
point point :: operator - (point& p) {
	point temp(0, 0);
	temp.x = this->x - p.x;
	temp.y = this->y - p.y;
	return temp;
}
