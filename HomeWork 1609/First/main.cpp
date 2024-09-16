#include <iostream>

class Node {
public:

	int data;
	Node* prev;
	Node* next;

	Node(int value) {
		this->data = value;
		this->next = nullptr;
		this->prev = nullptr;
	}
};

class LinkedList {
public:
	Node* head, * tail;

	LinkedList() {
		this->head = this->tail = nullptr;
	}
	Node* push_back(int value) {
		Node* ptr = new Node(value);

		ptr->prev = tail;
		if (tail != nullptr) {
			tail->next = ptr;
		}
		if (head == nullptr) {
			head = ptr;
		}
		tail = ptr;

		return ptr;
	}
	Node* get_at(int index) {
		Node* ptr = head;
		int n = 0;

		while (n != index) {
			if (ptr == nullptr)
				return nullptr;
			ptr = ptr->next;
			n++;
		}

		return ptr;
	}
	Node* operator [] (int index) {
		return get_at(index);
	}
	int size() {
		int count = 0;
		Node* ptr = head;

		while (ptr != nullptr) {
			ptr = ptr->next;
			count++;
		}

		return count;
	}
	void erase(int index) {
		Node* ptr = get_at(index);

		Node* left = ptr->prev;
		Node* right = ptr->next;

		if (left) {
			left->next = right;
		}
		else {
			head = right;
		}
		if (right) {
			right->prev = left;
		}
		else
			tail = left;
		

		delete ptr;

	}
};

bool is_zero_summ(LinkedList list) {
	int sum = list[0]->data;
	int size = list.size();

	while (size != 1) {
		for (int i = 1; i < size; i++) {

			if ((sum >= 0 && i == size - 1 && list[i]->data > 0) || (sum < 0 && i == size - 1 && list[i]->data < 0)) {
				return false;
			}

			if ((sum >= 0 && list[i]->data > 0) || (sum < 0 && list[i]->data < 0)) {
				continue;
			}

			sum += list[i]->data;
			list.erase(i);
			size--;
			break;
		}
	}

	return sum == 0;
}


int main() {

	LinkedList list;
	int number;
	std::cout << "Enter sequence integers (enter 'q' for end sequence): " << std::endl;
	while (std::cin >> number) {
		list.push_back(number);
	}

	std::system("cls");

	if (is_zero_summ(list)) {
		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "False" << std::endl;
	}

	return 0;
}