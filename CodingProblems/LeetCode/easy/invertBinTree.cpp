#include <iostream>

/* Definitition of a bin. tree
struct TreeNode {
	// Members
	int val;
	TreeNode *left;
	TreeNode *right;
	// Constructor
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) :
		val(x), left(left), right(right) {}
	// Methods
	void print(TreeNode *root) {
		while (root != nullptr) {
			print(root->left);
		}
	}
};
*/

class Solution {
	public:
		// For balanced bin.tree
		TreeNode* invertTree(TreeNode *root) {
			TreeNode *tmp{};
			if (root == nullptr) {}
			else if (root->left != nullptr) {
				root->left = invertTree(root->left);
				root->right = invertTree(root->right);
				if (root->right != nullptr) {
					tmp = root->right;
					root->right = root->left;
					root->left = tmp;
					tmp = nullptr;
				}
			}
			return root;
		}
		/* For non-balanced
			TreeNode *tmp{};
			if (root == nullptr) {}
			else {
				root->left = invertTree(root->left);
				root->right = invertTree(root->right);
				tmp = root->right;
				root->right = root->left;
				root->left = tmp;
				tmp = nullptr;
			}
			return root;
		*/
};

/*
int main(void) {
	TreeNode *tre{};
	Solution.invertTree(tre);
	return 0;
}
*/
