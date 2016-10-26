#include <iostream>
#include <list>

struct Node {
	int data;
	Node* next;
};

class LinkedList {
public:
	LinkedList();
//	LinkedList operator=();
	void appendToTail(int data);
	void insert(int data, int index);
	void clear();
	void erase(int index);
	void merge (LinkedList* other); // Lists should be sorted.
	void splice(int index, LinkedList* other);
	bool isEmpty();
	Node* get_at(int index);
	int size;
	Node* head;
	Node* tail;
};

LinkedList::LinkedList() : size(0), head(nullptr), tail(nullptr){}

//LinkedList::LinkedList operator=() {

//}

void LinkedList::appendToTail(int data) {
	Node* element = new Node(data);
	if (size == 0) {
		element->next = head;
		head = element;
	} else {
		tail->next = element;
	}
	size++;
}

void LinkedList::insert(int data, int index) {
	Node* element = new Node(data);
	if (head == nullptr) {
		head = element;
	} else {
		Node* before = get_at(index);
		Node* temp = before->next;
		before->next = element;
		element->next = temp;
	}
	size++;
}

void LinkedList::erase(int index) {
	if (index == 0) {
		head = get_at(index)->next;
	} else if (index == size - 1) {
		Node* before = get_at(index - 1);
		before -> next = nullptr;
	} else {
		Node* before = get_at(index - 1);
		before -> next = get_at(index + 1);
	}
	size--;
}

void LinkedList::clear() {
	Node* begin = head;
	Node* to_delete = head;
	while (!isEmpty()) {
		begin = head -> next;
		delete(to_delete);
		to_delete = begin;
	}
	size = 0;
}

void LinkedList::merge(LinkedList* other) {
	LinkedList result_list;
	int index = 0;
	while (!other->isEmpty() && !isEmpty()) {
		if (get_at(index)->data > other->get_at(index)->data) {
			result_list.appendToTail(other->get_at(index)->data);
			result_list.appendToTail(get_at(index)->data);
			other->erase(index);
			erase(index);
		} else {
			result_list.appendToTail(other->get_at(index)->data);
			result_list.appendToTail(get_at(index)->data);
			other->erase(index);
			erase(index);
		}
		index++;
	}
	LinkedList remaining_list;
	if (isEmpty()) {
		remaining_list.head = other->get_at(index);
		remaining_list.tail = other->tail;
		remaining_list.size = other->size;
	} else {
		remaining_list.head = other->get_at(index);
		remaining_list.tail = other->tail;
		remaining_list.size = other->size;
	}
//	result_list.splice(result_list.size() - 1, remaining_list);
}

void LinkedList::splice(int index, LinkedList* other) {
	if (size > 0 && other->size > 0) {
		Node* before = get_at(index);
		Node* temp_next = before->next;
		before->next = other->get_at(0);
		Node* last = other->get_at(other->size-1);
		last->next = temp_next;
	}
}

bool LinkedList::isEmpty() {
	return head == nullptr;
}

Node* LinkedList::get_at(int index) {
	Node* start = head;
	for (int i = 0; i < index; i++) {
		start = start->next;
	}
	return start;
}

int main() {
	std::cout << "beginning main";

//	LinkedList list;
//	list.appendToTail(1);
//	list.appendToTail(2);
//	list.appendToTail(3);
//	list.appendToTail(4);
//
//	for (int i = 0; i < list.size; i++) {
//		std::cout << list.get_at(i);
//	}
	return 0;
}




