#include <iostream>
#include <stack>


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

	while (src.size() != 0 && src.top() < dest.top()) {
		dest.push(src.top());
		src.pop();
	}

}

//for 1
template <typename stack_t>
void merge_stacks_descending(stack_t& src1, stack_t& src2, stack_t& dest) {
	
	while (src1.size() != 0 || src2.size() != 0) {
		if (src1.top() > src2.top()) {
			dest.push(src1);
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


	} while (count != 1);

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



int main() {

	return 0;
}