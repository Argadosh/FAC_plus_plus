#include <iostream>
#include <algorithm>

int count_the_parity(int a, int b, int c) {
	int count = 0;
	if (a % 2 == 0) {
		count++;
	}
	if (b % 2 == 0) {
		count++;
	}
	if (c % 2 == 0) {
		count++;
	}
	return count;
}

bool is_triangle(int* a, int* b, int* c) {
	int hypotenuse;
	if (*a >= *b && *a >= *c) {
		hypotenuse = *a;
	}
	else if (*b >= *a && *b >= *c) {
		hypotenuse = *b;
	}
	else {
		hypotenuse = *c;
	}
	int small_catheter;
	if (*a <= *b && *a <= *c) {
		small_catheter = *a;
	}
	else if (*b <= *a && *b <= *c) {
		small_catheter = *b;
	}
	else {
		small_catheter = *c;
	}
	int big_catheter;
	if ((small_catheter == *a && hypotenuse == *c) || (small_catheter == *c && hypotenuse == *a)) {
		big_catheter = *b;
	}
	else if ((small_catheter == *b && hypotenuse == *c) || (small_catheter == *c && hypotenuse == *b)) {
		big_catheter = *a;
	}
	else {
		big_catheter = *c;
	}

	*a = small_catheter;
	*b = big_catheter;
	*c = hypotenuse;

	return (*c < (*b + *a)) || ((*b + *a) < 0);
}

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
		while ((lhs1 % d == 0 || lhs2 % d == 0) && (rhs1 % d == 0 || rhs2 % d == 0)) {
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

bool is_pythagorean_three(int a, int b, int c) {
	
	int count = count_the_parity(a, b, c);

	if (count == 0 || count == 2 || is_triangle(&a, &b, &c) == false || a == b || b == c) {
		return false;
	}

	return is_equal_product(a, a, (c - b), (c + b));
	
}

int main() {
	int a, b, c;
	std::cout << "Enter third value: " << std::endl;
	std::cin >> a >> b >> c;

	if (is_pythagorean_three(a, b, c)) {
		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "False" << std::endl;
	}

	return 0;
}