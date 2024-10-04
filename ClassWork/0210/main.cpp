#include <iostream>
#include <vector>
#include <random>

struct Circle {
	int x, y;
};

bool is_zero_cubes_sum(const std::vector<int>& a) { // first
	for (int d = 2; d < 130; d++) { 
		int sum = 0;
		for (auto x : a) {
			x %= d;
			sum += x * x * x;
			sum %= d;
		}
		if (sum != 0)
			return false;
	}
	return true;
}

double intersection_area(std::vector<Circle> v) { // firth метод Монте-Карло
	
	std::random_device rd;
	std::mt19937_64 mtrand(rd());

	std::uniform_real_distribution<double> xdist(2.0, 10.0); // вместо 2.0 и 10.0 границы по иксу, а затем по игрику

	auto x = xdist(mtrand);
}


int main() {

	return 0;
}