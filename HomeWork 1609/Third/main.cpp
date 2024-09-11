#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

struct Point {
	double x, y;
};

double get_angle(Point point_ray, Point point_segment, bool* flag_four_section) {

	double angle;

	if (point_ray.x != point_segment.x && point_ray.y != point_segment.y) {
		angle = atan((point_ray.y - point_segment.y) / (point_ray.x - point_segment.x)) * 180 / M_PI;
		if ((point_segment.x < 0 && point_segment.y > 0) || (point_segment.x < 0 && point_segment.y < 0))
			angle += 180;
		else if (point_segment.x > 0 && point_segment.y < 0)
			angle += 360;
	}	
	else if (point_ray.y == point_segment.y) {
		if (point_ray.x <= point_segment.x && *flag_four_section) {
			angle = 360;
			*flag_four_section = false;
		}
		else if (point_ray.x <= point_segment.x)
			angle = 0;
		else
			angle = 180;
	}
	else if (point_ray.x == point_segment.x){
		if (point_ray.y < point_segment.y)
			angle = 90.0;
		else
			angle = 270.0;
	}

	return angle;
}

bool is_section_and_ray_intersect(Point first_point_segment, Point second_point_segment, Point point_ray, double polar_angle) {

	bool flag_four_section = false; // Костыль

	if (polar_angle <= 360 && polar_angle > 270)
		flag_four_section = true;

	double first_polar_angle_segment, second_polar_angle_segment;
	first_polar_angle_segment = get_angle(point_ray, first_point_segment, &flag_four_section);
	second_polar_angle_segment = get_angle(point_ray, second_point_segment, &flag_four_section);

	if (polar_angle >= std::min(first_polar_angle_segment, second_polar_angle_segment) && polar_angle <= std::max(first_polar_angle_segment, second_polar_angle_segment))
		return true;
	else
		return false;
}

int main() {

	double x, y;
	std::cout << "Enter first coordinate of segment" << std::endl;
	std::cin >> x >> y;
	Point first_point_segment{ x,y };
	std::cout << "Enter second coordinate of segment" << std::endl;
	std::cin >> x >> y;
	Point second_point_segment{ x,y };
	std::cout << "Enter coordinate of ray" << std::endl;
	std::cin >> x >> y;
	Point start_ray{ x,y };
	double polar_angle;
	std::cout << "Enter polar angle of ray [0, 360]" << std::endl;
	std::cin >> polar_angle;

	if (is_section_and_ray_intersect(first_point_segment, second_point_segment, start_ray, polar_angle))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;

	return 0;
}