/*
 * Queue.cpp
 *
 *  Created on: Oct 17, 2016
 *      Author: megkobashi
 */

#include "Queue.h"

using namespace std;

Queue::Queue(int size) : size(size), front(-1), rear(0) {}

bool Queue::enqueue(int data) {
	if (rear < size) {
		A[rear] = data;
		rear++;
		return true;
	} else {
		cout << "Queue overflow error" << endl;
		return false;
	}
}

bool Queue::dequeue() {
	if (front >= 0) {
		A[front] = 0;
		front++;
		return true;
	} else {
		cout << "Queue underflow error" << endl;
		return false;
	}
}

