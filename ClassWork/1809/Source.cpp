#include <iostream>
#include <stack>
#include <numeric>

using namespace std;

bool is_zero_sum(int* mas, size_t n) {
	stack<int> pos, neg;
	for (size_t i = 0; i < n; i++) {
		if (mas[i] > 0) pos.push(mas[i]);
		else
			if (mas[i] < 0) neg.push(mas[i]);
	}

	while (pos.size() && neg.size()) {
		auto sum = pos.top() + neg.top();
		pos.pop();
		neg.pop();
		if (sum > 0)
			pos.push(sum);
		else if (sum < 0)
			neg.push(sum);

	}
	return pos.size() == 0 && neg.size() == 0;
}

int gcd(int a, int b) {
	if (a == 0 || b == 0) {
		return abs(a + b);
	}
	else {
		return gcd(b, a % b);
	}
}
bool is_equal_product(int lhs1, int lhs2, int rhs1, int rhs2) {
	if ((lhs1 == 0 || lhs2 == 0) xor (rhs1 == 0 || rhs2 == 0))
		return false;
	if ((lhs1 == 0 || lhs2 == 0) and (rhs1 == 0 || rhs2 == 0))
		return true;
	auto nod = gcd(lhs1, rhs1);
	lhs1 /= nod;
	rhs1 /= nod;
	nod = gcd(lhs1, lhs2);
	lhs1 /= nod;
	rhs2 /= nod;
	if (abs(lhs1) != 1) return false;

	lhs2 /= nod;
	rhs1 /= nod;
	nod = gcd(lhs1, lhs2);
	lhs2 /= nod;
	rhs2 /= nod;
	if (abs(lhs2) != 1 || abs(rhs1)!=1 || abs(rhs2)!= 1) return false;
	return  lhs1 * lhs2 == rhs1 * rhs2;
	/*int mag = std::max({ abs(lhs1),abs(lhs2),abs(rhs1),abs(rhs2) });
	for (int d = 2; d <= mag; d++) {
		if ((lhs1 % d == 0 || lhs2 % d == 0) && (rhs1 % d == 0 || rhs2 % d == 0)) {
			if (lhs1 % d == 0) lhs1 /= d;
			else lhs2 /= d;
			if (rhs1 % d == 0) rhs1 /= d;
			else rhs2 /= d;
			--d;
		}
	}*/
}

int main() {

}