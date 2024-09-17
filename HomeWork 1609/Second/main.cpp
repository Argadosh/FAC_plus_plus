#include <iostream>
#include <algorithm>

bool is_equal_product(int lhs1, int lhs2, int rhs1, int rhs2) {

	if ((lhs1 > 0 && lhs2 > 0 && ((rhs1 < 0 && rhs2 > 0) || (rhs1 > 0 && rhs2 < 0)))
		|| (lhs1 < 0 && lhs2 < 0 && ((rhs1 < 0 && rhs2 > 0) || (rhs1 > 0 && rhs2 < 0))) 
		|| (((lhs1 < 0 && lhs2 > 0) || (lhs1 > 0 && lhs2 < 0)) && rhs1 < 0 && rhs2 < 0)
		|| (((lhs1 < 0 && lhs2 > 0) || (lhs1 > 0 && lhs2 < 0)) && rhs1 > 0 && rhs2 > 0)) {
		return false;
	}

	bool was_division = false;
	if ((lhs1 == 0 || lhs2 == 0) xor (rhs1 == 0 || rhs2 == 0)) {
		return false;
	}
	if ((lhs1 == 0 || lhs2 == 0) and (rhs1 == 0 || rhs2 == 0)) {
		return true;
	}

	int mag = std::max({ abs(lhs1),abs(lhs2),abs(rhs1),abs(rhs2) });
	for (int d = 2; d <= sqrt(mag); d++) {
		while((lhs1 % d == 0 || lhs2 % d == 0) && (rhs1 % d == 0 || rhs2 % d == 0)){
			if (lhs1 % d == 0) {
				lhs1 /= d;
			}
			else {
				lhs2 /= d;
			}
			if (rhs1 % d == 0) {
				rhs1 /= d;
			}
			else {
				rhs2 /= d;
			}
			was_division = true;
		}
	}

	if (was_division) {
		return (abs(lhs1 + lhs2) == abs(rhs1 + rhs2));
	}
	else {
		if ((lhs1 < 0 && lhs2 < 0 && rhs1 > 0 && rhs2 > 0) || (lhs1 > 0 && lhs2 > 0 && rhs1 < 0 && rhs2 < 0)) {
			return (abs(lhs1) == abs(rhs1) || abs(lhs1) == abs(rhs2)) && (abs(lhs2) == abs(rhs1) || abs(lhs2) == abs(rhs2));
		}
		else {
			return (lhs1 == rhs1 || lhs1 == rhs2) && (lhs2 == rhs1 || lhs2 == rhs2);
		}
	}
}


int main() {

	int lhs1, lhs2, rhs1, rhs2;
	std::cout << "Enter first two multiplaer: " << std::endl;
	std::cin >> lhs1 >> lhs2;
	std::cout << "Enter second two multiplaer: " << std::endl;
	std::cin >> rhs1 >> rhs2;

	if (is_equal_product(lhs1, lhs2, rhs1, rhs2)) {
		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "False" << std::endl;
	}

	return 0;
}