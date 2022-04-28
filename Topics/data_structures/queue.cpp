#include <iostream>

struct Node {
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};

struct Queue {
	Node *head;

	Queue() { head = nullptr; }
	~Queue() {
		Node *tmp = head;
		while(tmp != nullptr) {
			tmp = head->next;
			delete(head);
			head = tmp;
		}
		std::cout << "\nCleared queue\n";
	}

	void enQueue(int data) {
		Node *newNode = new Node(data);
		newNode->next = head;
		head = newNode;
	}

	void deQueue() {
		Node *tmp = head;
		while (tmp->next->next != nullptr) {
			tmp = tmp->next;
		}
		delete(tmp->next);
		tmp->next = nullptr;
	}

	void print() {
		Node *tmp = head;
		std::cout << "Your queue:\n";
		while (tmp != nullptr) {
			std::cout << tmp->data << " ";
			tmp = tmp->next;
		}
		std::cout << std::endl;
	}
};

int main(void) {
	Queue q1;

	std::cout << "Enqueuing 1 2 3\n";
	q1.enQueue(1);
	q1.enQueue(2);
	q1.enQueue(3);
	q1.print();

	std::cout << "\nDequeuing once\n";
	q1.deQueue();
	q1.print();

	return 0;
}
