#include <iostream>
#include <vector>

struct Point {
	int x, y;
	Point() {
		x = 0;
		y = 0;
	}
};

class Rectangle {
public:
	Point p1, p2;
	Rectangle(int X1, int X2, int Y1, int Y2) {
		if(X1 < X2 && Y1 > Y2) {
			p1.x = X1;
			p1.y = Y1;
			p2.x = X2;
			p2.y = Y2;
		}
		else if (X1 > X2 && Y1 < Y2) {
			p1.x = X2;
			p1.y = Y2;
			p2.x = X1;
			p2.y = Y1;
		}
		else if (X1 > X2 && Y1 > Y2) {
			p1.x = X2;
			p1.y = Y1;
			p2.x = X1;
			p2.y = Y2;
		}
		else if (X1 < X2 && Y1 < Y2) {
			p1.x = X1;
			p1.y = Y2;
			p2.x = X2;
			p2.y = Y1;
		}
	}
};


int squre_intersection_rectangles(std::vector<Rectangle> v) {

	Rectangle area_intersect(v[0].p1.x, v[0].p2.x, v[0].p1.y, v[0].p2.y);

	for (int i = 1; i < v.size(); i++) {
		if (v[i].p1.x >= area_intersect.p2.x || v[i].p2.y >= area_intersect.p1.y || area_intersect.p1.x >= v[i].p2.x || area_intersect.p2.y >= v[i].p1.y) {
			return 0;
		}
		if (v[i].p1.x == area_intersect.p1.x && v[i].p1.y == area_intersect.p1.y && v[i].p2.x == area_intersect.p2.x && v[i].p2.y == area_intersect.p2.y) {
			continue;
		}

		if (v[i].p2.x < area_intersect.p2.x) {
			area_intersect.p2.x = v[i].p2.x;
			if (v[i].p1.y < area_intersect.p1.y) {
				area_intersect.p1.y = v[i].p1.y;
			}
		}

		if (area_intersect.p2.y < v[i].p2.y) {
			area_intersect.p2.y = v[i].p2.y;
		}

		if (area_intersect.p1.x < v[i].p1.x) {
			area_intersect.p1.x = v[i].p1.x;
		}

	}

	int squre = (area_intersect.p2.x - area_intersect.p1.x) * (area_intersect.p1.y - area_intersect.p2.y);

	return squre;
}

int main() {

	std::vector<Rectangle> v;
	int x1, y1, x2, y2;
	int count = 0;
	std::cout << "Enter count rectangles: " << std::endl;
	std::cin >> count;
	for (int i = 0; i < count; i++) {
		std::cout << "Enter coordinate rectangle: " << std::endl;
		std::cin >> x1 >> y1 >> x2 >> y2;
		Rectangle r(x1, x2, y1, y2);
		v.push_back(r);
	}
	std::cout << "Squre intersection: " << squre_intersection_rectangles(v) << std::endl;

	return 0;
}