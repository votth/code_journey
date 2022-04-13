#include <iostream>

struct node {
	int data;
	node *next;

	// Cons and Des
	node() = default;
	node(int data, node *next) {
		this->data = data;
		this->next = next;
	}

	// Methods
	void print_node() {
		std::cout << this << std::endl;
		std::cout << this->data << std::endl;
		std::cout << this->next << std::endl;
		std::cout << "-----------" << std::endl;
	}
};

int main(void) {

	node *head = new node(1, nullptr);
	node *new_node = new(node);
	node *tmp = head;

	new_node->data = 2;
	new_node->next = nullptr;
	head->next = new_node;

	while (tmp != nullptr) {
		tmp->print_node();
		tmp = tmp->next;
	}

	 while (head != nullptr) {
		tmp = head;
		head = head->next;
		delete(tmp);
	}

	return 0;
}
