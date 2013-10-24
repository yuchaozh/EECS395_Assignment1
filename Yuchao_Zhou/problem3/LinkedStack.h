/*
 *Author: Yuchao Zhou
 *Time: 10/16/2013
 */
#ifndef WORKSPACE_LINKEDSTACK_H
#define WORKSPACE_LINKEDSTACK_H
#include <assert.h>
#include "Node.h"
class LinkedStack
{
	node* first;
public:
	LinkedStack();
	~LinkedStack();
	LinkedStack(const LinkedStack& other);
	void push(int num);
	int pop();
	bool empty();
	int top();
	void traverse();
};

#endif
