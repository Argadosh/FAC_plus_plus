#include <iostream>
#include <vector>
#include <algorithm>

bool is_polygon(std::vector<float> f_v) {
	float max = 0.0;

	double sum = 0.0;

	for (int i = 0; i < f_v.size(); i++) {
		sum += f_v[i];
		max = std::max(f_v[i], max);
	}

	if ((sum - max) > max) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	std::vector<float> f_v;
	float value;
	std::cout << "Enter sequence length of some polygon(Enter 'q' for end sequence): " << std::endl;
	while (std::cin >> value) {
		if (value < 0) {
			std::cout << "Value in sequence do not less zero!" << std::endl;
			return 0;
		}
		f_v.push_back(value);
	}

	std::system("cls");

	if (is_polygon(f_v)) {
		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "False" << std::endl;
	}

	return 0;
}