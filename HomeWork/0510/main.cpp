#include <iostream>

template <typename T>
class stack_m { //Realization on array
private:
	T* data;
	size_t capacity, count;
public:
	stack_m(size_t _capacity = 50000);
	~stack_m();
	void push(const T& new_top);
	void push(T&& new_top);
	void pop();
	T& top();
	const T& top() const;
	size_t size() const;
	stack_m(const stack_m<T>& obj);
	stack_m(stack_m<T>&& obj);
	stack_m<T>& operator= (const stack_m<T>& obj);
	stack_m<T>& operator= (stack_m<T>&& obj);
};

template <typename T>
stack_m<T>::stack_m(size_t _capacity) {
	count = 0;
	capacity = _capacity;
	data = new T[capacity];
}

template <typename T>
stack_m<T>::~stack_m() {
	delete[]data;
}

template <typename T>
void stack_m<T>::push(const T& new_top) {
	if (count == capacity) {
		throw std::overflow_error("Error: Stack is filled");
	}
	data[count++] = new_top;
}

template <typename T>
void stack_m<T>::push(T&& new_top) {
	if (count == capacity) {
		throw std::overflow_error("Error: Stack is filled");
	}
	data[count++] = new_top;
}

template <typename T>
void stack_m<T>::pop() {
	if (count == 0) {
		throw std::out_of_range("Error: Stack is empty. Cannot delete element");
	}
	count--;
}

template <typename T>
T& stack_m<T>::top() {
	if (count == 0) {
		throw std::out_of_range("Error: stack is empty. Cannot retrieve element");
	}
	return data[count - 1];
}

template <typename T>
const T& stack_m<T>::top() const {
	if (count == 0) {
		throw std::out_of_range("Error: Stack is empty. Cannot retrieve element");
	}
	return data[count - 1];
}

template <typename T>
size_t stack_m<T>::size() const {
	return count;
}

template <typename T>
stack_m<T>::stack_m(const stack_m<T>& obj) {
	delete[] data;
	capacity = obj.capacity;
	count = obj.count;
	data = new T[capacity];
	for (size_t i = 0; i < count; i++) {
		data[i] = obj.data[i];
	}
}

template <typename T>
stack_m<T>::stack_m(stack_m<T>&& obj) {
	delete[] data;
	data = obj.data;
	capacity = obj.capacity;
	count = obj.count;
	obj.data = nullptr;
	obj.capacity = 0;
	obj.count = 0;
}

template<typename T>
stack_m<T>& stack_m<T>::operator=(const stack_m<T>& obj) {
	if (this != &obj) {
		if (data != nullptr) {
			delete[] data;
		}
		capacity = obj.capacity;
		count = obj.count;
		data = new T[capacity];
		for (size_t i = 0; i < count; i++) {
			data[i] = obj.data[i];
		}
	}
	return *this;
}

template<typename T>
stack_m<T>& stack_m<T>::operator=(stack_m<T>&& obj) {
	if (this != &obj) {
		if (data != nullptr) {
			delete[] data;
		}
		data = obj.data;
		capacity = obj.capacity;
		count = obj.count;
		obj.data = nullptr;
		obj.capacity = 0;
		obj.count = 0;
	}
	return *this;
}

template<typename stack_t> // task 2
void extract_min(stack_t& src, stack_t& dest){
	if (src.size() == 0) {
		return;
	}

	while (dest.size() != 0) {
		dest.pop();
	}

	auto min_element = src.top();

	stack_t tmp_1 = src;

	for (size_t i = 0; i < src.size(); i++) {
		if (tmp_1.top() < min_element) {
			min_element = tmp_1.top();
		}
		tmp_1.pop();
	}

	tmp_1 = src;

	stack_t tmp;

	for (size_t i = 0; i < src.size(); i++) {
		if (tmp_1.top() == min_element) {
			dest.push(min_element);
		}
		else {
			tmp.push(tmp_1.top());
		}
		tmp_1.pop();
	}

	src = tmp;
}

template<typename stack_t> // task 3
void select_sort(stack_t& src){

	stack_t tmp;
	stack_t min;

	while (src.size() != 0) {
		extract_min(src, min);
		while (min.size() != 0) {
			tmp.push(min.top());
			min.pop();
		}
	}

	src = tmp;

}

template<typename stack_t> // task 5
size_t count_occurrences(stack_t& stack, const decltype(stack.top())& value){
	size_t c_occurrences = 0;

	stack_t tmp = stack;

	for (size_t i = 0; i < stack.size(); i++) {
		if (tmp.top() == value) {
			c_occurrences++;
		}
		tmp.pop();
	}
	return c_occurrences;
}

//template <typename stack_t> // task 5
//size_t count_occurrences(stack_t& stack, const decltype(stack.top())&& value) {
//	size_t c_occurrences = 0;
//
//	stack_t tmp = stack;
//
//	for (size_t i = 0; i < stack.size(); i++) {
//		if (tmp.top() == value) {
//			c_occurrences++;
//		}
//		tmp.pop();
//	}
//
//	return c_occurrences;
//}

template<typename stack_t> // task 5
bool is_two_stack_equel(stack_t& f_stack, stack_t& s_stack){
	if (f_stack.size() != s_stack.size()) {
		return false;
	}

	stack_t tmp_f = f_stack;
	stack_t tmp_s = s_stack;

	for (size_t i = 0; i < f_stack.size(); i++) {
		if (tmp_f.top() != tmp_s.top()) {
			return false;
		}
		tmp_f.pop();
		tmp_s.pop();
	}
	return true;
}


int main() {
	stack_m<int> s;
	//int v = 5;
	s.push(8);
	s.push(8);
	s.push(2);
	s.push(3);
	s.push(2);
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);

	count_occurrences(s, 2);

	stack_m<int> v = s;
	//int v = 5;
	//extract_min(s, v);

	size_t size = v.size();
	for (size_t i = 0; i < size; i++) {
		std::cout << v.top() << std::endl;
		v.pop();
	}

	std::cout << " " << std::endl;
	select_sort(s);
	size = s.size();
	for (size_t i = 0; i < size; i++) {
		std::cout << s.top() << std::endl;
		s.pop();
	}
	

	return 0;
}