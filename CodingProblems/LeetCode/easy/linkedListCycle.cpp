#include <iostream>

/* Definition for singly-linked list
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
*/

class Solution {
	public:
		/* Floyd's Cycle-finding algo
		bool hasCycle(ListNode *head) {
			ListNode *p_slow = head, *p_fast = head;
			while (p_slow && p_fast && p_fast->next) {
				p_slow = p_slow->next;
				p_fast = p_fast->next->next;
				if (p_slow == p_fast) {
					return true;
				}
			}
			return false;
		}
		*/
		bool hasCycle(ListNode *head) {
			int space = 0;
			ListNode *tmp = head;
			ListNode *save{};
			while (tmp != nullptr) {
				if (tmp->next == &space) return true;
				save = tmp;
				tmp->next = &space;
				tmp = save->next;
			}
			return false;
		}
};
