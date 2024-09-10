#include <iostream>

int arithmetic_mean_three_numrers(int first_number, int second_number, int third_numbers) {

	int average = 0;
	int remainder_of_division = 0;

	average += first_number / 3;
	remainder_of_division += first_number % 3;

	average += second_number / 3;
	remainder_of_division += second_number % 3;

	average += third_numbers / 3;
	remainder_of_division += third_numbers % 3;

	if (remainder_of_division > 0)
		for (int i = remainder_of_division; i >= 2; i -= 3)
			average++;
	else
		for (int i = remainder_of_division; i <= -2; i += 3)
			average--;

	return average;
}

int main() {

	int first, second, third;
	std::cout << "Enter three integers" << std::endl;
	std::cin >> first >> second >> third;

	std::cout << "Arithmetic mean: " << arithmetic_mean_three_numrers(first, second, third) << std::endl;

	return 0;
}