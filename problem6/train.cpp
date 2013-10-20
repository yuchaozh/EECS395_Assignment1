/*
 *Prupose: Implement the sorting function
 *Author: Yuchao Zhou
 *Time: 10/16/2013
 */
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include<sstream>
#include "LinkedStack.h"

using namespace std;

bool success = false;
int times = 0;
vector<LinkedStack> stack;
vector<int> result;
vector<string> procedure;
string str;
int targetNumber = 1;
int carNumber = 0;
bool output = false;


LinkedStack stack1;
LinkedStack stack2;
int stack_number = 0;

//change int type into string type
string int_string(int num)
{
	stringstream ss;
	ss<<num;
	string s=ss.str();
	return s;
}

//output number from holding tack
bool outputFromHoldTrack(int tNumber)
{
	output = false;
	int once = 0;
	targetNumber = tNumber;
	int posible = stack1.top();
	if (posible == targetNumber)
	{
		str = "Move car " + int_string(posible) + " from holding track 1 to output";
		procedure.push_back(str);
		result.push_back(stack1.pop());
		targetNumber++;
		output = true;
		once = 1;
	}
	return output;
}
		
//put numbers from input into holding tracks
bool putinHold(int c)
{
	bool result = true;
	if (stack1.top() == 0)
	{
		stack1.push(c);
		stack_number = 1;
		cout<<"holding track "<<1<<" hold car "<<c<<endl;
		cout<<endl;
		return result;
	}
	//if the input number is smaller than top, then push it into that stack
	if (stack1.top() > c)
	{
		stack1.push(c);
		cout<<"holding track "<<1<<" hold car "<<c<<endl;
		cout<<endl;
		return result;
	}
	//else push the number which are smaller than the number into another stack, and push them back.
	if (stack1.top() < c)
	{
		while ((stack1.top() < c) &&(stack1.top() != 0))
		{
			cout<<"holding track "<<2<<" hold car "<<stack1.top()<<endl;
			stack2.push(stack1.pop());
			
			stack_number = 2;
		}
		stack1.push(c);
		cout<<"holding track "<<1<<" hold car "<<c<<endl;
		while (stack2.empty() == false)
		{
			cout<<"holding track "<<1<<" hold car "<<stack2.top()<<endl;
			stack1.push(stack2.pop());
		}
		cout<<endl;
	}
	return result;
}

//main function of sorting.
bool Railroad (int inputOrder[], int numberofCars, int numberofTracks)
{
	int totle = numberofCars;
	times = numberofCars;
	bool done = false;
	carNumber = numberofCars;
	const int trackNumber = numberofTracks;
	stack.resize(trackNumber);
	cout<<"input array: "<<endl;
	for (int i = 0; i < carNumber; i++)
	{
		cout<<inputOrder[i]<<" ";
	}
	cout<<endl;
	while (carNumber > 0)
	{
		int currentNumber = inputOrder[carNumber - 1];
		//if currentNumber is not equal to targetNumber, then put it into stack
		if (currentNumber != targetNumber)
		{
			putinHold(currentNumber);
			carNumber--;
		}
		//put currentNumber into output and look up the next number in stack and input
		else
		{
			str = "Move car "+ int_string(currentNumber) + " from input to output ";
			procedure.push_back(str);
			result.push_back(currentNumber);
			carNumber--;
			targetNumber++;
			outputFromHoldTrack(targetNumber);
			while (output == true)
			{
				outputFromHoldTrack(targetNumber);
			}
		}
		//judge whether the procedure can output the sorted number
		if (carNumber == 0)
		{
			if (result.size() == numberofCars)
			{
				success = true;
				for (int i = 0; i < procedure.size(); i++)
				{
					cout<<procedure[i]<<endl;
				}
			}
			else
			{
				success = false;
				for (int a = 0; a < totle - 1; a++)
				{
					cout<<inputOrder[a]<<"-";
				}
				cout<<inputOrder[totle -1];
				cout<<" is not feasible"<<endl;
			}
		}
	}
	return done;
}

int main()
{
	int carnumber;
	int stacknumber;

	//read data from txt file
	ifstream inputfile("input2.txt");
	inputfile>>carnumber;
	inputfile>>stacknumber;
	int *cars = new int[carnumber];
	for (int i = 0; i < carnumber; i++)
	{
		inputfile>>cars[i];
	}

	Railroad(cars, carnumber, stacknumber);
	cout<<stack_number<<" stack we use."<<endl;
	system("pause");
	return 0;
}