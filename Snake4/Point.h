#ifndef POINT_H
#define POINT_H

//Define the coordinate of a point on console screen
struct Point {
	int x = 0;
	int y = 0;
};

struct SpecialFood {
	Point pos;
	int func;
};

#endif