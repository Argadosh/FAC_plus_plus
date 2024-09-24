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
		if (X1 < X2 && Y1 > Y2) {
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

int squre_rectangle(Rectangle r) {
	return (r.p2.x - r.p1.x) * (r.p1.y - r.p2.y);
}

int squre_intersection_two_rectangles(Rectangle first, Rectangle second) {

	if (second.p1.x >= first.p2.x || second.p2.y >= first.p1.y || first.p1.x >= second.p2.x || first.p2.y >= second.p1.y) {
		return 0;
	}
	if (second.p1.x == first.p1.x && second.p1.y == first.p1.y && second.p2.x == first.p2.x && second.p2.y == first.p2.y) {
		return 0;
	}

	if (second.p2.x < first.p2.x) {
		first.p2.x = second.p2.x;
		if (second.p1.y < first.p1.y) {
			first.p1.y = second.p1.y;
		}
	}

	if (first.p2.y < second.p2.y) {
		first.p2.y = second.p2.y;
	}

	if (first.p1.x < second.p1.x) {
		first.p1.x = second.p1.x;
	}

	return squre_rectangle(first);
}

int squre_unification_rectangles(std::vector<Rectangle> v) {

	int squre_unification = 0;

	for (int i = 0; i < v.size(); i++) {
		int squre_some_rectangle = squre_rectangle(v[i]);
		for (int j = i + 1; j < v.size(); j++) {
			squre_some_rectangle -= squre_intersection_two_rectangles(v[i], v[j]);
		}
		squre_unification += squre_some_rectangle;
	}

	return squre_unification;

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
	std::cout << "Squre intersection: " << squre_unification_rectangles(v) << std::endl;

	return 0;
}