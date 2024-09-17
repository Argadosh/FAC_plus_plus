#include <iostream>

bool is_sum_all_value_in_range_equel_to_zero(int min_value_in_range, int max_value_in_range) {

	if (max_value_in_range * -1 == min_value_in_range)
		return true;
	else
		return false;
}

int main() {

	int min_value_in_range, max_value_in_range;

	std::cout << "Enter range boundaries: [min, max]" << std::endl;
	std::cin >> min_value_in_range >> max_value_in_range;

	if (is_sum_all_value_in_range_equel_to_zero(min_value_in_range, max_value_in_range))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;

	return 0;
}