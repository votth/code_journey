#include <iostream>

struct Node {
	public:
		int data;
		Node *next;

		// Constructor
		Node() = default;
		Node(int t_data, Node *t_next) {
			this->data = t_data;
			this->next = t_next;
		}
};

// Create
void createLink(Node *t_head);
// Print
void printLink(Node *t_head);
void reversePrint(Node *curr);
// Insert
void insertNode(Node *t_head, Node *t_newNode);
void pushData(Node *t_head, int t_data);
// Remove
void removeNode(Node *t_head, int t_rmIndex);
// Reverse
void reverseLink(Node **t_head);
// Empty
void emptyLink(Node *t_head);

int main(void) {
	Node *head = new Node(0, nullptr);
	createLink(head);

	std::cout << "\nAdd nodes with function\n";
	Node *newNode = new Node(2, nullptr);
	insertNode(head, newNode);
	pushData(head, 3);
	printLink(head);

	/*
	int rmIndex{};
	std::cout << "Please state the n-th node to be delete: ";
	std::cin >> rmIndex;
	removeNode(head, rmIndex - 1);
	*/

	std::cout << "\nReversed link: \n";
	reverseLink(&head);
	printLink(head);

	std::cout << "\nReverse print:\n";
	reversePrint(head);

	emptyLink(head);
	return 0;
}

void printLink(Node *t_head) {
	std::cout << "The link: ";
	Node *tmp = t_head;
	while(tmp != nullptr) {
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

void createLink(Node *t_head) {
	Node *tmp = t_head;
	int n;
	std::cout << "How many initial nodes? ";
	std::cin >> n;
	while (n > 1) {
		Node *newNode = new Node{};
		std::cout << "The node data: ";
		std::cin >> newNode->data;
		tmp->next = newNode;
		printLink(t_head);
		tmp = tmp->next;
		--n;
	}
	tmp->next = nullptr;
}

void emptyLink(Node *t_head) {
	Node *tmp = t_head;
	while(t_head != nullptr) {
		t_head = t_head->next;
		delete(tmp);
		tmp = t_head;
	}
}

void insertNode(Node *t_head, Node *t_newNode) {
	Node *tmp = t_head;
	while(tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = t_newNode;
}

void pushData(Node *t_head, int t_data) {
	Node *tmp = new Node(t_data, nullptr);
	insertNode(t_head, tmp);
}

void removeNode(Node *t_head, int t_rmIndex) {
	Node *tmp = t_head;
	Node *tmpPre = tmp;
	/* Condition when removing head node?
	if (t_rmIndex == 0) {
		*t_head = *t_head->next;
		delete(tmp);
		return;
	}
	*/
	while ((t_rmIndex != 0) && (tmp->next != nullptr)) {
		tmpPre = tmp;
		tmp = tmp->next;
		--t_rmIndex;
	}
	if (t_rmIndex == 0) {
		tmpPre->next = tmp->next;
		delete(tmp);
	} else {
		std::cout << "Out of bound\n";
	}
}

// Require **t_head, why when insertNode() doesn't? Hmmmm
void reverseLink(Node **t_head) {
	Node *curNode = (*t_head);
	Node *preNode = nullptr;
	Node *nexNode = nullptr;
	while (curNode != nullptr) {
		nexNode = curNode->next;
		curNode->next = preNode;
		preNode = curNode;
		curNode = nexNode;
	}
	*t_head =  preNode;
}

void reversePrint(Node *curr) {
	if (curr->next != nullptr) {
		reversePrint(curr->next);
	}
	std::cout << curr->data << " ";
	return;
}
