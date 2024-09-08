#include <iostream>
#include <algorithm>

struct Point {
	double x, y;
};

double Direction(Point pi, Point pj, Point pk) {
	return ((pi.x - pk.x) * (pj.y - pk.y) - (pj.x - pk.x) * (pi.y - pk.y));
}

bool On_Segment(Point pi, Point pj, Point pk) {
	if (std::min(pi.x, pj.x) <= pk.x && pk.x <= std::max(pi.x, pj.x) && std::min(pi.y, pj.y) <= pk.y && pk.y <= std::max(pi.y, pj.y))
		return true;
	else
		return false;
}

bool is_two_sections_intersect(Point start_point_first_section, Point end_point_first_section, Point start_point_second_section, Point end_point_second_section) {

	double d1, d2, d3, d4;
	d1 = Direction(start_point_second_section, end_point_second_section, start_point_first_section);
	d2 = Direction(start_point_second_section, end_point_second_section, end_point_first_section);
	d3 = Direction(start_point_first_section, end_point_first_section, start_point_second_section);
	d4 = Direction(start_point_first_section, end_point_first_section, end_point_second_section);
	
	if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
		return true;
	else if (d1 == 0 && On_Segment(start_point_second_section, end_point_second_section, start_point_first_section))
		return true;
	else if (d2 == 0 && On_Segment(start_point_second_section, end_point_second_section, end_point_first_section))
		return true;
	else if (d3 == 0 && On_Segment(start_point_first_section, end_point_first_section, start_point_second_section))
		return true;
	else if (d4 == 0 && On_Segment(start_point_first_section, end_point_first_section, end_point_second_section))
		return true;
	else
		return false;
}

bool is_three_points_lying_on_one_line(Point start_section, Point end_section, Point random_point) {

	double alfa = (random_point.x - end_section.x) / (start_section.x - end_section.x);
	if (0 <= alfa && alfa <= 1)
		return true;
	else {
		alfa = (random_point.y - end_section.y) / (start_section.y - end_section.y);
		if (0 <= alfa && alfa <= 1)
			return true;
		return false;
	}
}

int main() {

	int choice;
	std::cout << "Choice func:\n0) Is two sections intersect?\n1) Is three points lying on one line?" << std::endl;
	std::cin >> choice;

	double x, y;

	switch (choice){
		case 0: {
			std::cout << "Enter coordinates start first section" << std::endl;
			std::cin >> x >> y;
			Point start_first_point{ x, y };
			std::cout << "Enter coordinates end first section" << std::endl;
			std::cin >> x >> y;
			Point end_first_point{ x, y };
			std::cout << "Enter coordinates start second section" << std::endl;
			std::cin >> x >> y;
			Point start_second_point{ x, y };
			std::cout << "Enter coordinates end second section" << std::endl;
			std::cin >> x >> y;
			Point end_second_point{ x, y };
			if (is_two_sections_intersect(start_first_point, end_first_point, start_second_point, end_second_point))
				std::cout << "True" << std::endl;
			else
				std::cout << "False" << std::endl;
			break;
		}
		case 1: {
			std::cout << "Enter coordinates first point" << std::endl;
			std::cin >> x >> y;
			Point first_point{ x, y };
			std::cout << "Enter coordinates second point" << std::endl;
			std::cin >> x >> y;
			Point second_point{ x, y };
			std::cout << "Enter coordinates third point" << std::endl;
			std::cin >> x >> y;
			Point third_point{ x, y };
			if (is_three_points_lying_on_one_line(first_point, second_point, third_point))
				std::cout << "True" << std::endl;
			else
				std::cout << "False" << std::endl;
			break;
		}
		default: {
			std::cout << "ERROR: Incorrect data" << std::endl;
			break;
		}
	}

	return 0;
}