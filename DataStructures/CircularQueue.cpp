/*
 * CircularQueue.cpp
 *
 *  Created on: Oct 17, 2016
 *      Author: megkobashi
 */

#include "Queue.h"

using namespace std;

class CircularQueue : public Queue {
public:
	using Queue::Queue;
	using Queue::~Queue;
	virtual bool enqueue(int data) override;
	virtual bool dequeue() override;
};

bool CircularQueue::enqueue(int data) {
	if (front != rear) {
		A[rear] = data;
		rear = (rear+1) % size;
		return true;
	} else {
		cout << "Queue overflow error" << endl;
		return false;
	}
}

bool CircularQueue::dequeue() {
	if (front != -1 && front != rear) {
		A[front] = 0;
		front = (front + 1) % size;
		return true;
	} else {
		cout << "Queue underflow error" << endl;
		return false;
	}
}
