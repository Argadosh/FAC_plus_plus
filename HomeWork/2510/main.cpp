#include <iostream>
#include <stack>
#include <random>
#include <chrono> //for 3.3


//for 1
template <typename stack_t>
void extract_nodecreasing(stack_t& src, stack_t& dest) {

	if (src.size() == 0) {
		return;
	}

	while (dest.size() != 0) {
		dest.pop();
	}

	dest.push(src.top());
	src.pop();

	while (src.size() != 0 && src.top() > dest.top()) {
		dest.push(src.top());
		src.pop();
	}

}

//for 1
template <typename stack_t>
void merge_stacks_descending(stack_t& src1, stack_t& src2, stack_t& dest) {
	
	while (src1.size() != 0 && src2.size() != 0) {
		if (src1.top() > src2.top()) {
			dest.push(src1.top());
			src1.pop();
		}
		else {
			dest.push(src2.top());
			src2.pop();
		}
	}

	while (src1.size() != 0) {
		dest.push(src1.top());
		src1.pop();
	}

	while (src2.size() != 0) {
		dest.push(src2.top());
		src2.pop();
	}

}

//task 1 efficient stack sorting by merging
template <typename stack_t>
void sort_merge_stack(stack_t &src) {

	stack_t tmp1;
	stack_t tmp2;
	stack_t tmp3;

	size_t count = 0;

	do {

		count = 0;

		while (src.size() != 0) {
			extract_nodecreasing(src, tmp1);
			extract_nodecreasing(src, tmp2);

			merge_stacks_descending(tmp1, tmp2, tmp3);
		}

		while (tmp3.size() != 0) {
			extract_nodecreasing(tmp3, tmp1);
			extract_nodecreasing(tmp3, tmp2);

			merge_stacks_descending(tmp1, tmp2, src);
			count++;
		}


	} while (count > 1);

}


//task 3.1 Quick Sort with 1 support element
template <typename stack_t>
void quick_sort_stack(stack_t& src) {
	if (src.size() <= 1) {
		return;
	}

	stack_t great, less, equal;

	auto s_el = src.top();
	src.pop();

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


//for 3.2
template <typename stack_t>
void reverse_stack(stack_t& src) {
	stack_t tmp;
	while (src.size() != 0) {
		tmp.push(src.top());
		src.pop();
	}
	src = tmp;
}

//task 3.2 Quick Sort with 2 support elenemts
template <typename stack_t>
void quick_sort_stack_two(stack_t& src) {

	if (src.size() <= 1) {
		return;
	}

	auto s_el_1 = src.top();
	src.pop();
	auto s_el_2 = src.top();
	src.pop();

	if (s_el_1 > s_el_2) {
		auto tmp = s_el_2;
		s_el_2 = s_el_1;
		s_el_1 = tmp;
	}

	stack_t great, less, between;

	while (src.size() != 0) {
		auto cur_el = src.top();
		src.pop();

		if (cur_el < s_el_1) {
			less.push(cur_el);
		}
		else if (cur_el > s_el_2) {
			great.push(cur_el);
		}
		else {
			between.push(cur_el);
		}
	}

	quick_sort_stack_two(great);
	quick_sort_stack_two(less);
	quick_sort_stack_two(between);

	reverse_stack(great);
	reverse_stack(between);
	reverse_stack(less);

	while (great.size() != 0) {
		src.push(great.top());
		great.pop();
	}

	src.push(s_el_2);

	while (between.size() != 0) {
		src.push(between.top());
		between.pop();
	}

	src.push(s_el_1);

	while (less.size() != 0) {
		src.push(less.top());
		less.pop();
	}

}

int main() {

	std::stack<int> s;

	std::mt19937 engine;
	engine.seed(std::time(nullptr));

	for (size_t i = 0; i < 10; i++) {
		int val = engine();
		s.push(val);
	}

	std::stack<int> tmp = s;

	while (tmp.size() != 0) {
		std::cout << tmp.top() << std::endl;
		tmp.pop();
	}

	//tmp = s;

	std::cout << "\n\n\n" << std::endl;

	sort_merge_stack(s);

	while (s.size() != 0) {
		std::cout << s.top() << std::endl;
		s.pop();
	}

	/*auto start = std::chrono::high_resolution_clock::now();

	quick_sort_stack(tmp);

	auto end = std::chrono::high_resolution_clock::now();

	auto res_1 = end - start;

	start = std::chrono::high_resolution_clock::now();

	quick_sort_stack_two(s);

	end = std::chrono::high_resolution_clock::now();

	auto res_2 = end - start;

	while (s.size() != 0) {
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << "\n\n\n" << std::endl;

	std::cout << "Time first method: " << res_1.count() << std::endl;
	std::cout << "Time second method: " << res_2.count() << std::endl;*/

	return 0;
}