#include <iostream>
#include <stdexcept>

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
		delete[] data;
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
		delete[] data;
		data = obj.data;
		capacity = obj.capacity;
		count = obj.count;
		obj.data = nullptr;
		obj.capacity = 0;
		obj.count = 0;
	}
	return *this;
}

template <typename T>
class stack_l { //Realization on list
private:
	struct Node {
		T data;
		Node* next;
		Node(const T& _data, Node* _next = nullptr) {
			data = _data;
			next = _next;
		}
		Node(T&& _data, Node* _next = nullptr) {
			data = _data;
			next = _next;
		}
	};

	Node* head;
	size_t count;
public:
	stack_l();
	~stack_l();
	void push(const T& new_top);
	void push(T&& new_top);
	void pop();
	T& top();
	const T& top() const;
	size_t size() const;
	stack_l(const stack_l<T>& obj);
	stack_l(stack_l<T>&& obj);
	stack_l<T>& operator= (const stack_l<T>& obj);
	stack_l<T>& operator= (stack_l<T>&& obj);
};

template<typename T>
stack_l<T>::stack_l() {
	head = nullptr;
	count = 0;
}

template<typename T>
stack_l<T>::~stack_l() {
	while (head != nullptr) {
		this->pop();
	}
}

template<typename T>
void stack_l<T>::push(const T& new_top) {
	head = new Node(new_top, head);
	count++;
}

template<typename T>
void stack_l<T>::push(T&& new_top) {
	head = new Node(new_top, head);
	count++;
}

template<typename T>
void stack_l<T>::pop() {
	if (count == 0) {
		throw std::out_of_range("Error: Stack is empty. Cannot delete element");
	}
	Node* tmp = head;
	head = head->next;
	delete tmp;
	count--;
}

template<typename T>
T& stack_l<T>::top() {
	if (count == 0) {
		throw std::out_of_range("Error: Stack is empty. Cannot retrieve element");
	}
	return head->data;
}

template<typename T>
const T& stack_l<T>::top() const {
	if (count == 0) {
		throw std::out_of_range("Error: Stack is empty. Cannot retrieve element");
	}
	return head->data;
}

template<typename T>
size_t stack_l<T>::size() const {
	return count;
}

template<typename T>
stack_l<T>::stack_l(const stack_l<T>& obj) {
	head = nullptr;
	count = 0;

	Node* obj_current = obj.head;

	while (obj_current != nullptr) {
		this->push(obj_current->data);
		obj_current = obj_current->next;
	}
}

template<typename T>
stack_l<T>::stack_l(stack_l<T>&& obj) {
	head = obj.head;
	count = obj.count;
	obj.head = nullptr;
	obj.count = 0;
}

template<typename T>
stack_l<T>& stack_l<T>::operator=(const stack_l<T>& obj) {
	if (this != &obj) {
		while (head != nullptr) {
			this->pop();
		}

		if (obj.head == nullptr) {
			head = nullptr;
			count = 0;
			return *this;
		}

		Node* obj_current = obj.head;

		while (obj_current != nullptr) {
			this->push(obj_current->data);
			obj_current = obj_current->next;
		}
	}
	return *this;
}

template<typename T>
stack_l<T>& stack_l<T>::operator=(stack_l<T>&& obj) {
	if (this != &obj) {
		while (head != nullptr) {
			this->pop();
		}

		head = obj.head;
		count = obj.count;

		obj.head = nullptr;
		obj.count = 0;
	}
	return *this;
}

int main() {

	return 0;
}