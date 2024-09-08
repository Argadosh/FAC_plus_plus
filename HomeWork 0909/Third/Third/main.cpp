#include <iostream>
#include <string>
#include <cmath>

class Circle {
private:
	double x, y;
	double radius;
public:
	Circle() {
		x = 0;
		y = 0;
		radius = 1;
	}
	Circle(double X, double Y, double R) {
		x = X;
		y = Y;
		radius = R;
	}
	double get_x() {
		return x;
	}
	double get_y() {
		return y;
	}
	double get_r() {
		return radius;
	}
};

std::string mutual_position_two_circles(Circle c1, Circle c2) {

	std::string ans;

	double d;
	d = sqrt(pow((c2.get_x() - c1.get_x()), 2) + pow((c2.get_y() - c1.get_y()), 2));

	if (c1.get_r() + c2.get_r() < d || c1.get_r() - c2.get_r() > d)
		ans = "No common points";
	else if (c1.get_r() + c2.get_r() == d || c1.get_r() - c2.get_r() == d)
		ans = "Circles touch at one point";
	else
		ans = "Circles have common chord";

	return ans;
}

int main() {

	double x1, x2, r1, y1, y2, r2;
	std::cout << "Enter coordinates center first circle and her radius" << std::endl;
	std::cin >> x1 >> y1 >> r1;
	Circle c1(x1, y1, r1);
	std::cout << "Enter coordinates center second circle and her radius" << std::endl;
	std::cin >> x2 >> y2 >> r2;
	Circle c2(x2, y2, r2);

	std::cout << mutual_position_two_circles(c1, c2) << std::endl;

	return 0;
}