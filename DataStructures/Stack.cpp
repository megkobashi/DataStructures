/*
 * Stack.cpp
 *
 *  Created on: Oct 17, 2016
 *      Author: megkobashi
 */

using namespace std;

struct Node {
	int data;
	Node* next;
};

class Stack {
public:
	Stack(int size);
	bool push(int data);
	bool pop();
	int peek_top();
private:
	Node* top;
	int size;
	int max_size;
};

Stack::Stack(int size) : max_size(size), top(nullptr), size(0) {}

bool Stack::push(int data) {
	Node* v;
	v->data = data;
	if (size < max_size) {
		v->next = top;
		top = v;
		size++;
		return true;
	} else {
		cout << "Stack overflow error" << endl;
		return false;
	}
}

bool Stack::pop() {
	if (size >= 1) {
		Node* next_top = top->next;
		delete(top);
		top = next_top;
		return true;
	} else {
		cout << "Stack underflow error" << endl;
		return false;
	}
}

int Stack::peek_top() {
	return top->data;
}
