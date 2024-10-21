#include <iostream>
#include <vector>
#include <stack>


//1.1
template <typename stack_t>
void extract_nodecreasing(stack_t& src, stack_t& dest) {

	auto perv = src.top();

	while (src.size() != 0 && src.top() >= perv) {
		perv = src.top();
		dest.push(perv);
		src.pop();
	}

}

//1.2
template <typename stack_t, typename template_stack>
void union_two_stack(stack_t& src_1, stack_t& src_2, template_stack& dest) {

	while (src_1.size() != 0 && src_2.size() != 0) {
		if (src_1.top() <= src_2.top()) {
			dest.push(src_1.top());
			src_1.pop();
		}
		else {
			dest.push(src_2.top());
			src_2.pop();
		}
	}

	if (src_1.size() == 0) {
		while (src_2.size() != 0) {
			dest.push(src_2.top());
			src_2.pop();
		}
	}
	if (stc_2.size() == 0) {
		while (src_1.size() != 0) {
			dest.push(src_1.top());
			src_1.pop();
		}
	}

}

//for 2.1
bool is_one_type_bracket(char a, char b) {
	return (a == '[' && b == ']') || (a == '{' && b == '}') || (a == '(' && b == ')');
}

//for 2.1
bool is_openning_bracket(char a) {
	return (a == '[') || (a == '(') || (a == '{');
}

//2.1
bool is_correct_bracket_sequence(std::vector<char> b_sequence, int index) {

	if (b_sequence.size() == 0) {
		return true;
	}

	index = -1;

	std::stack<char> s;

	for (size_t i = 0; i < b_sequence.size(); i++) {
		if (is_openning_bracket(b_sequence[i])) {
			s.push(b_sequence[i]);
		}
		else {
			if (s.size() == 0) {
				return false;
			}

			if (is_one_type_bracket(s.top(), b_sequence[i])) {
				s.pop();
			}
			else {
				index = i;
				return false;
			}
		}
	}

	return (s.size() == 0);

}

//3.1
template <typename vector_t>
void who_is_major(vector_t v, auto major) {

	std::stack<auto> s

	for (size_t i = 0; i < v.size(); i++) {
		if (s.size() == 0) {
			s.push(v[i]);
		}
		else {
			if (s.top() == v[i]) {
				s.push(v[i]);
			}
			else {
				s.pop();
			}
		}
	}

	if (s.size() == 0) {
		major = -1;
	}
	else {
		size_t count = 0;
		for (size_t i = 0; i < v.size(); i++) {
			if (s.top() == v[i]) {
				count++;
			}
		}
		if (count > v.size() / 2) {
			major = s.top();
		}
		else {
			major = -1;
		}
	}

}

int main() {



	return 0;
}