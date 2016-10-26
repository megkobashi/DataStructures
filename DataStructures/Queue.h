/*
 * Queue.h
 *
 *  Created on: Oct 17, 2016
 *      Author: megkobashi
 */

#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {
public:
	explicit Queue(int size);
	virtual ~Queue();
	virtual bool enqueue(int data);
	virtual bool dequeue();
private:
	int size;
	int front;
	int rear;
	int A[size];
};



#endif /* QUEUE_H_ */
