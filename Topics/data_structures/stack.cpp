#include <iostream>

struct Node {
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};

struct Stack {
	Node *head;

	Stack() { head = nullptr; }
	~Stack() {
		Node *tmp = head;
		while (tmp != nullptr) {
			tmp = head->next;
			delete(head);
			head = tmp;
		}
		std::cout << "\nCleared stack\n";
	}

	void push(int t_data) {
		Node *newNode = new Node(t_data);
		newNode->next = head;
		head = newNode;
	}

	void pop() {
		Node *tmp = head;
		head = head->next;
		delete(tmp);
	}

	void print() {
		std::cout << "Your stack:\n";
		Node *tmp = head;
		while (tmp != nullptr) {
			std::cout << tmp->data << std::endl;
			tmp = tmp->next;
		}
	}
};

int main(void) {
	Stack s1;

	std::cout << "Pushing 3 2 1\n";
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.print();

	std::cout << "\nPoping once\n";
	s1.pop();
	s1.print();

	return 0;
}
