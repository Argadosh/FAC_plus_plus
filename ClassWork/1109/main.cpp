#include <iostream>
#include <algorithm>

bool is_zero_sum(int* mas, size_t count) {
	return false;
}

bool are_equel_products(int lhs1, int lhs2, int rhs1, int rhs2) {
	if ((lhs1 == 0 || lhs2 == 0) xor (rhs1 == 0 || rhs2 == 0))
		return false;
	if ((lhs1 == 0 || lhs2 == 0) and (rhs1 == 0 || rhs2 == 0))
		return true;

	int mag = std::max({ abs(lhs1), abs(lhs2), abs(rhs1), abs(rhs2) });

	for (int d = 2; d <= mag; d++) {
		while ((lhs1 % d == 0 || lhs2 % d == 0) and (rhs1 % d == 0 || rhs2 % d == 0)) {
			if (lhs1 % d == 0)
				lhs1 /= d;
			else
				lhs2 /= d;

			if (rhs1 % d == 0)
				rhs1 /= d;
			else
				rhs2 /= d;
		}
	}

	return abs(lhs1) == 1 && abs(lhs2) == 1 && abs(rhs1) == 1 && abs(rhs2) == 1 && lhs1 * lhs2 == rhs1 * rhs2;
}

enum circles_state {intersect, out_tangent, inner_tangent,  inside, outside, coincide, concentric};

circles_state get_circles_state(double x1, double y1, double r1, double x2, double y2, double r2) {
	if (...)
		return intersect;
	...
}

int main() {

	std::cout << are_equel_products(3, 4, 6, 2) << std::endl;

	return 0;
}