#include <iostream>
#include <queue>

class MyStack {
	private:
		std::queue<int> q1;
		std::queue<int> q2;

	public:
		MyStack() = default;

		void push(int x) {
			q1.push(x);
		}

		int pop() {
			int tmp{};
			while (q1.size() > 1) {
				q2.push(q1.front());
				q1.pop();
			}
			tmp = q1.front();
			q1.pop();
			q1 = q2;
			while (!(q2.empty())) {
				q2.pop();
			}
			return tmp;
		}

		int top() {
			return q1.back();
		}

		bool empty() {
			return q1.empty();
		}

		void print() {
			q2 = q1;
			while (!(q2.empty())) {
				std::cout << q2.front() << " ";
				q2.pop();
			}
			std::cout << std::endl;
		}
};

/**
 * MyStack obj will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
	MyStack *obj = new MyStack();

	std::cout << "Pushing element by order: 1, 2, 3\n";
	obj->push(1);
	obj->push(2);
	obj->push(3);
	obj->print();

	std::cout << "Poping once and checking top of stack\n";
	int param_2 = obj->pop();
	int param_3 = obj->top();
	std::cout << param_2 << std::endl << param_3 << std::endl;
	obj->print();

	std::cout << "Check if the stack is empty\n";
	bool param_4 = obj->empty();
	std::cout << std::boolalpha;
	std::cout << param_4 << std::endl;

	return 0;
}
