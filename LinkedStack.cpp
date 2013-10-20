/*
 *Purpose: Implement basic functions of stack by linked list
 *Author: Yuchao Zhou
 *Time: 10/16/2013
 */
#include "LinkedStack.h"
#include <iostream>

using namespace std;

//constructor
LinkedStack::LinkedStack()
{
	first = new node();
	first -> next = NULL;
}

//destructor
LinkedStack::~LinkedStack()
{
	node* current = first;
	node *to_free;
	while (current)
	{
		to_free = current;
		//node *to_free = current;
		current = current->next;
		delete to_free;
	}
}

//constructor
LinkedStack::LinkedStack(LinkedStack& other)
{
	cout<<"not implement"<<endl;
}

//insert element num
void LinkedStack::push(int num)
{
	node* conductor;
	conductor = first;
	//if (conductor -> next== NULL)
	//{
	//	node* add;
	//	add = new node();
	//	add -> d = num;
	//	add -> next = NULL;
	//	conductor -> next = add;
	//}
	//else
	//{

		while (conductor -> next != 0)
		{
			conductor = conductor -> next;
		}
		node* add;
		add = new node();
		add -> d = num;
		add -> next = NULL;
		conductor -> next = add;
	//}
}

//return the element at the top
int LinkedStack::top()
{
	node* conductor;
	conductor = first;
	if (empty() == true)
	{
		//cout<<"the stack is empty"<<endl;
	}
	else
	{
		while (conductor -> next != 0)
		{
			conductor = conductor -> next;
		}
	}
	return conductor -> d;
}

//return a boolean value indicating whether no elements are stored
bool LinkedStack::empty()
{
	if (first -> next == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//removes and returns the last inserted element
int LinkedStack::pop()
{
	node* conductor;
	node* previous;
	previous = first;
	conductor = first;
	if (empty() == true)
	{
		//cout<<"no node (top)"<<endl;
	}
	else
	{
		while (conductor -> next != 0)
		{
			previous = conductor;
			conductor = conductor -> next;
		}
		previous -> next = NULL;
	}
	return conductor -> d;
}

//traverse the stack and output every element
void LinkedStack::traverse()
{
	node* current;
	current = first -> next;
	while (current)
	{
		cout<<current -> d<<endl;
		current = current -> next;
	}
}

//int main()
//{
//	LinkedStack stack;
//	stack.push(2);
//	stack.push(9);
//	stack.traverse();
//
//	system("pause");
//	return 0;
//}
