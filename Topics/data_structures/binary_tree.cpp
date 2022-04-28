#include <iostream>

struct BstNode {
	int data;
	BstNode *left;
	BstNode *right;
	BstNode(int data) {
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

struct Bst {
	BstNode *root;
	Bst() { root = nullptr; }
	// print
	void printPostOrder(BstNode *root) {
		if (root == nullptr) return;
		printPostOrder(root->left);
		printPostOrder(root->right);
		std::cout << root->data << " " ;
	}

	// insert
	void insert(BstNode **root, int data) {
		BstNode *newNode = new BstNode(data);
		if (*root == nullptr) {
			*root = newNode;
		} else if (data <= (*root)->data) {
			insert(&((*root)->left), data);
		} else insert(&((*root)->right), data);
	}
	/*
	// search
	bool search(BstNode *root, int data) {
		if (root == nullptr) return false;
		else if (root->data == data) return true;
		else if (data <= root->data) return search(root->left, data);
		else return search(root->right, data);
	}
	*/
};

int main(void) {
	Bst bst1;

	bst1.insert(&bst1.root, 1);
	bst1.insert(&bst1.root, 2);
	bst1.insert(&bst1.root, 3);

	bst1.printPostOrder(bst1.root);

	/* if (bst1.search(2)) { */
	/* 	std::cout << "Found\n"; */
	/* } */

	return 0;
}
