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
	void extract_min(stack_m<T>& src, stack_m<T>& dest);
	void select_sort(stack_m<T>& src);
	size_t count_occurrences(const T& value);
	size_t count_occurrences(T&& value);
	bool is_two_stack_equel(stack_m<T>& other);
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

template<typename T>
void stack_m<T>::extract_min(stack_m<T>& src, stack_m<T>& dest){

}

template<typename T>
void stack_m<T>::select_sort(stack_m<T>& src){

}

template<typename T>
size_t stack_m<T>::count_occurrences(const T& value){
	size_t c_occurrences = 0;

	for (size_t i = 0; i < count; i++) {
		if (data[i] == value) {
			c_occurrences++;
		}
	}
	return c_occurrences;
}

template <typename T>
size_t stack_m<T>::count_occurrences(T&& value) {
	size_t c_occurrences = 0;

	for (size_t i = 0; i < count; i++) {
		if (data[i] == value) {
			c_occurrences++;
		}
	}

	return c_occurrences;
}

template<typename T>
bool stack_m<T>::is_two_stack_equel(stack_m<T>& other){
	if (count != other.size()) {
		return false;
	}
	for (size_t i = 0; i < count; i++) {
		if (data[i] != other.data[i]) {
			return false;
		}
	}
	return true;
}


int main() {
	stack_m<int> s;
	//int v = 5;
	s.push(5);
	s.push(5);
	s.push(5);
	s.push(5);
	s.push(5);
	s.push(10);
	s.push(10);
	s.push(10);

	stack_m<int> v;
	v.push(5);
	v.push(5);
	v.push(5);
	v.push(5);
	v.push(50);
	v.push(10);
	v.push(10);
	v.push(10);

	std::cout << s.count_occurrences(51) << std::endl;
	std::cout << s.is_two_stack_equel(v) << std::endl;
	/*for (size_t i = s.size(); i > 0; i--) {
		std::cout << s.top() << std::endl;
		s.pop();
	}*/

	return 0;
}