/*
 *Purpose: Implement basic function of stack by linked list
 *Author: Yuchao Zhou
 *Time: 10/16/2013
 */
#include "LinkedStack.h"
#include "Node.h"
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
	while (current)
	{
		delete current; 
		current = current->next;
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
	if (conductor -> next== NULL)
	{
		node* add;
		add = new node();
		add -> d = num;
		add -> next = NULL;
		conductor -> next = add;
	}
	else
	{

		while (conductor -> next != 0)
		{
			conductor = conductor -> next;
		}
		node* add;
		add = new node();
		add -> d = num;
		add -> next = NULL;
		conductor -> next = add;
	}
}

//return the element at the top
int LinkedStack::top()
{
	node* conductor;
	//node* previous;
	//previous = first;
	conductor = first;
	if (empty() == true)
	{
		cout<<"no node (top)"<<endl;
	}
	else
	{
		while (conductor -> next != 0)
		{
			//previous = conductor;
			conductor = conductor -> next;
		}
		//previous -> next = NULL;
	}
	return conductor -> d;
}

//return a boolean value indicating whether no elements are stored
bool LinkedStack::empty()
{
	//cout<<"empty function"<<endl;
	if (first -> next == NULL)
	{
		//cout<<"empty"<<endl;
		return true;
	}
	else
	{
		//cout<<"not empty"<<endl;
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
		cout<<"no node (top)"<<endl;
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
	//while (current)
	while (current)
	{
		cout<<current -> d<<endl;
		current = current -> next;
	}
}

int main()
{
	LinkedStack* ls = new LinkedStack();
	//ls -> pop();
	//ls -> top();
	ls -> push(9);
	ls -> push(3);
	ls -> push(6);
	ls -> push(1);
	ls -> push(0);
	ls ->traverse();
	while (ls -> empty() == false)
	{
		int i = 0;
		int a = 0;
		a = ls -> top();
		i = ls -> pop();
		cout<<" top: "<<a<<endl;
		cout<<" pop: "<<i<<endl;
	}
	system("Pause");
	return 0;
}