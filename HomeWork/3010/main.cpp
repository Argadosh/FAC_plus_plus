#include <iostream>
#include <stack>
#include <random>
#include <chrono>


//for task 1
template <typename stack_t>
auto getRandomElement(stack_t &src) {
	if (src.size() == 0) {
		throw std::overflow_error("Error: stack is empty");
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, src.size() - 1);

	size_t index = dist(gen);

	stack_t tmp;
	for (size_t i = 0; i < index; i++) {
		tmp.push(src.top());
		src.pop();
	}

	auto r_element = src.top();
	src.pop();

	while (tmp.size() != 0) {
		src.push(tmp.top());
		tmp.pop();
	}

	return r_element;
}

//task 1
template <typename stack_t>
void quick_sort_stack(stack_t& src) {
	if (src.size() <= 1) {
		return;
	}

	stack_t great, less, equal;

	auto s_el = getRandomElement(src);

	equal.push(s_el);

	while (src.size() != 0) {
		auto cur_el = src.top();
		src.pop();

		if (cur_el > s_el) {
			great.push(cur_el);
		}
		else if (cur_el < s_el) {
			less.push(cur_el);
		}
		else {
			equal.push(cur_el);
		}
	}

	quick_sort_stack(great);
	quick_sort_stack(less);

	while (great.size() != 0) {
		equal.push(great.top());
		great.pop();
	}

	while (equal.size() != 0) {
		src.push(equal.top());
		equal.pop();
	}

	while (less.size() != 0) {
		great.push(less.top());
		less.pop();
	}

	while (great.size() != 0) {
		src.push(great.top());
		great.pop();
	}

}

int main() {

	std::stack<int> s;
	for (int i = 0; i < 50000; i++) {
		s.push(50000 - i);
	}

	auto start = std::chrono::high_resolution_clock::now();
	quick_sort_stack(s);
	auto end = std::chrono::high_resolution_clock::now();

	auto res1 = end - start;

	std::cout << res1.count() << std::endl;

	return 0;
}