#include <iostream>

class Point {
private:
	int x, y;
public:
	Point() {
		x = 0;
		y = 0;
	}
	void set_x(int X) {
		x = X;
	}
	void set_y(int Y) {
		y = Y;
	}
	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}
};

class Rectangle {
private:
	Point top_left_point, bottom_right_point;
public:
	Rectangle(int X1, int Y1, int X2, int Y2) {
		if (X1 < X2 && Y1 > Y2) {
			top_left_point.set_x(X1);
			top_left_point.set_y(Y1);
			bottom_right_point.set_x(X2);
			bottom_right_point.set_y(Y2);
		}
		else if (X1 > X2 && Y1 < Y2) {
			top_left_point.set_x(X2);
			top_left_point.set_y(Y2);
			bottom_right_point.set_x(X1);
			bottom_right_point.set_y(Y1);
		}
		else if (X1 > X2 && Y1 > Y2) {
			top_left_point.set_x(X2);
			top_left_point.set_y(Y1);
			bottom_right_point.set_x(X1);
			bottom_right_point.set_y(Y2);
		}
		else if (X1 < X2 && Y1 < Y2) {
			top_left_point.set_x(X1);
			top_left_point.set_y(Y2);
			bottom_right_point.set_x(X2);
			bottom_right_point.set_y(Y1);
		}
	}
	int get_top_x() {
		return top_left_point.get_x();
	}
	int get_top_y() {
		return top_left_point.get_y();
	}
	int get_bottom_x() {
		return bottom_right_point.get_x();
	}
	int get_bottom_y() {
		return bottom_right_point.get_y();
	}
};

int area_intersection_two_rectangle(Rectangle r1, Rectangle r2) {
	if (r1.get_top_x() <= r2.get_top_x() && r1.get_top_y() >= r2.get_top_y() && r1.get_bottom_x() >= r2.get_top_x() && r1.get_bottom_y() <= r2.get_top_y()) {
		if (r1.get_bottom_x() <= r2.get_bottom_x() && r1.get_bottom_y() >= r2.get_bottom_y())
			return (r1.get_bottom_x() - r2.get_top_x()) * (r2.get_top_y() - r1.get_bottom_y());
		else if (r1.get_bottom_x() <= r2.get_bottom_x() && r1.get_bottom_y() <= r2.get_bottom_y())
			return (r1.get_bottom_x() - r2.get_top_x()) * (r2.get_top_y() - r2.get_bottom_y());
		else if (r1.get_bottom_x() >= r2.get_bottom_x() && r1.get_bottom_y() >= r2.get_bottom_y())
			return (r2.get_bottom_x() - r2.get_top_x()) * (r2.get_top_y() - r1.get_bottom_y());
		else if (r1.get_bottom_x() >= r2.get_bottom_x() && r1.get_bottom_y() <= r2.get_bottom_y())
			return (r2.get_bottom_x() - r2.get_top_x()) * (r2.get_top_y() - r2.get_bottom_y());
	}
	else if (r2.get_top_x() <= r1.get_top_x() && r2.get_top_y() >= r1.get_top_y() && r2.get_bottom_x() >= r1.get_top_x() && r2.get_bottom_y() <= r1.get_top_y()) {
		if (r2.get_bottom_x() <= r1.get_bottom_x() && r2.get_bottom_y() >= r1.get_bottom_y())
			return (r2.get_bottom_x() - r1.get_top_x()) * (r1.get_top_y() - r2.get_bottom_y());
		else if (r2.get_bottom_x() <= r1.get_bottom_x() && r2.get_bottom_y() <= r1.get_bottom_y())
			return (r2.get_bottom_x() - r1.get_top_x()) * (r1.get_top_y() - r2.get_bottom_y());
		else if (r2.get_bottom_x() >= r1.get_bottom_x() && r2.get_bottom_y() >= r1.get_bottom_y())
			return (r1.get_bottom_x() - r1.get_top_x()) * (r1.get_top_y() - r2.get_bottom_y());
		else if (r2.get_bottom_x() >= r1.get_bottom_x() && r2.get_bottom_y() <= r1.get_bottom_y())
			return (r1.get_bottom_x() - r1.get_top_x()) * (r1.get_top_y() - r1.get_bottom_y());
	}
	else if (r1.get_top_x() <= r2.get_top_x() && r1.get_top_y() <= r2.get_top_y() && r1.get_bottom_x() >= r2.get_top_x() && r1.get_bottom_y() <= r2.get_top_y() && r1.get_top_y() >= r2.get_bottom_y()) {
		if (r1.get_bottom_x() >= r2.get_bottom_x() && r1.get_bottom_y() >= r2.get_bottom_y())
			return (r2.get_bottom_x() - r2.get_top_x()) * (r1.get_top_y() - r1.get_bottom_y());
		else if (r1.get_bottom_x() >= r2.get_bottom_x() && r1.get_bottom_y() <= r2.get_bottom_y())
			return (r2.get_bottom_x() - r2.get_top_x()) * (r1.get_top_y() - r2.get_bottom_y());
		else if (r1.get_bottom_x() <= r2.get_bottom_x() && r1.get_bottom_y() >= r2.get_bottom_y())
			return (r1.get_bottom_x() - r2.get_top_x()) * (r1.get_top_y() - r1.get_bottom_y());
		else if (r1.get_bottom_x() <= r2.get_bottom_x() && r1.get_bottom_y() <= r2.get_bottom_y())
			return (r1.get_bottom_x() - r2.get_top_x()) * (r1.get_top_y() - r2.get_bottom_y());
	}
	else if (r2.get_top_x() <= r1.get_top_x() && r2.get_top_y() <= r1.get_top_y() && r2.get_bottom_x() >= r1.get_top_x() && r2.get_bottom_y() <= r1.get_top_y() && r2.get_top_y() >= r1.get_bottom_y()) {
		if (r2.get_bottom_x() >= r1.get_bottom_x() && r2.get_bottom_y() >= r1.get_bottom_y())
			return (r1.get_bottom_x() - r1.get_top_x()) * (r2.get_top_y() - r2.get_bottom_y());
		else if (r2.get_bottom_x() >= r1.get_bottom_x() && r2.get_bottom_y() <= r1.get_bottom_y())
			return (r1.get_bottom_x() - r2.get_top_x()) * (r2.get_top_y() - r1.get_bottom_y());
		else if (r2.get_bottom_x() <= r1.get_bottom_x() && r2.get_bottom_y() >= r1.get_bottom_y())
			return (r2.get_bottom_x() - r1.get_top_x()) * (r2.get_top_y() - r2.get_bottom_y());
		else if (r2.get_bottom_x() <= r1.get_bottom_x() && r2.get_bottom_y() <= r1.get_bottom_y())
			return (r2.get_bottom_x() - r1.get_top_x()) * (r2.get_top_y() - r1.get_bottom_y());
	}
	else
		return 0;
}

int main() {

	int x1, x2, y1, y2;
	std::cout << "Enter first coordinates first rectangle" << std::endl;
	std::cin >> x1 >> y1;
	std::cout << "Enter opposite coordinates first rectangle" << std::endl;
	std::cin >> x2 >> y2;

	Rectangle rect1(x1, y1, x2, y2);

	std::cout << "Enter first coordinates second rectangle" << std::endl;
	std::cin >> x1 >> y1;
	std::cout << "Enter opposite coordinates second rectangle" << std::endl;
	std::cin >> x2 >> y2;

	Rectangle rect2(x1, y1, x2, y2);

	std::cout << "Area intersection two rectangle is: " << area_intersection_two_rectangle(rect1, rect2) << std::endl;

	return 0;
}