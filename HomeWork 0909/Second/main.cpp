#include <iostream>

bool is_multiplication_equally(int first_multiplier_in_first_product, int second_multiplier_in_first_product, int first_multiplier_in_second_product, int second_multiplier_in_second_product) {

	int first_product = first_multiplier_in_first_product * second_multiplier_in_first_product;
	int second_product = first_multiplier_in_second_product * second_multiplier_in_second_product;

	if ((first_multiplier_in_first_product > 0 && second_multiplier_in_first_product > 0 && first_multiplier_in_first_product > first_product / second_multiplier_in_first_product) 
			|| (first_multiplier_in_second_product > 0 && second_multiplier_in_second_product > 0 && first_multiplier_in_second_product > second_product / second_multiplier_in_second_product))
		return false;
	else if ((first_multiplier_in_first_product < 0 && second_multiplier_in_first_product < 0 && first_multiplier_in_first_product < first_product / second_multiplier_in_first_product)
			|| (first_multiplier_in_second_product < 0 && second_multiplier_in_second_product < 0 && first_multiplier_in_second_product < second_product / second_multiplier_in_second_product))
		return false;
	else if (((first_multiplier_in_first_product > 0 && second_multiplier_in_first_product < 0 && second_multiplier_in_first_product < first_product / first_multiplier_in_first_product)
				|| (first_multiplier_in_first_product < 0 && second_multiplier_in_first_product > 0 && first_multiplier_in_first_product < first_product / second_multiplier_in_first_product))
			|| ((first_multiplier_in_second_product > 0 && second_multiplier_in_second_product < 0 && second_multiplier_in_second_product < second_product / first_multiplier_in_second_product)
				|| (first_multiplier_in_second_product < 0 && second_multiplier_in_second_product > 0 && first_multiplier_in_second_product < second_product / second_multiplier_in_second_product)))
		return false;
	
	if (first_product == second_product)
		return true;
	else
		return false;
}

int main() {

	int first_multiplier_in_first_product, second_multiplier_in_first_product, first_multiplier_in_second_product, second_multiplier_in_second_product;

	std::cout << "Enter 4 value: " << std::endl;
	std::cin >> first_multiplier_in_first_product >> second_multiplier_in_first_product >> first_multiplier_in_second_product >> second_multiplier_in_second_product;

	if (is_multiplication_equally(first_multiplier_in_first_product, second_multiplier_in_first_product, first_multiplier_in_second_product, second_multiplier_in_second_product))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;

	return 0;
}