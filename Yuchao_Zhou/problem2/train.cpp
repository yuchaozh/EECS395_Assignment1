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

//change int type into string
string int_string(int num)
{
	stringstream ss;
	ss<<num;
	string s=ss.str();
	return s;
}

//outputs instructions to ove a car from a holding track to the output track.
bool outputFromHoldTrack(int tNumber)
{
	output = false;
	int once = 0;
	targetNumber = tNumber;
	for (int i = 0; i < stack.size(); i++)
	{
		int posible = stack[i].top();
		if (posible == targetNumber)
		{
			str = "Move car " + int_string(posible) + " from holding track " + int_string(i) + " to output";
			procedure.push_back(str);
			result.push_back(stack[i].pop());
			targetNumber++;
			output = true;
			once = 1;
		}
	}
	return output;
}

//moves car c from the input track to one of the holding tracks if possible, else it return false.
bool putinHold(int c)
{
	vector<int> temp;
	int contain = 0;
	bool notfull = true;
	int notFullSlut = 0;
	int slut = 0;
	int smallest = 0;
	bool result = true;
	int finish = false;

	//whether the stack size is full or not
	if (contain == stack.size())
	{
		notfull == false;
	}
	else
	{
		notfull == true;
	}
	//if stack is empty, then push
	if (stack[0].top() == 0)
	{
		stack[0].push(c);
		contain++;
		str = "holding track 0 hold car "+int_string(c);
		procedure.push_back(str);
	}
	else  
	//judege wheter the number is bigger than the top. 
	//if it does then compare it with next stack, else push it into current stack.
	{
		for (int i = 0; i < stack.size(); i++)
		{
			if (stack[i].top() != 0)
			{
				contain++;
			}
		}
		for (int i = 0; i < contain; i++)
		{
			if (i == (contain - 1))
					finish = true;
			//if it is small then top, then push
			if (c < stack[i].top())
			{
				stack[i].push(c);
				str = "holding track " + int_string(i) + " hold car " + int_string(c);
				procedure.push_back(str);
				break;
			}
			else if ((finish == true) && (contain < stack.size()))
			{
				stack[contain].push(c);
				contain++;
				str = "holding track " + int_string(contain -1) + " hold car " + int_string(c);
				procedure.push_back(str);
				break;
			}
		}
	}
	return result;
}

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
		//if currentNumber is not equal to targetNumber£¬then put it into stack
		if (currentNumber != targetNumber)
		{
			putinHold(currentNumber);
			carNumber--;
		}
		//put currentNumber into output£¬and look up the next number in stack and input
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
		//judge whether the program can sort the permutation or not
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
	ifstream inputfile("input.txt");
	inputfile>>carnumber;
	inputfile>>stacknumber;
	int *cars = new int[carnumber];
	for (int i = 0; i < carnumber; i++)
	{
		inputfile>>cars[i];
	}
	Railroad(cars, carnumber, stacknumber);
	//system("pause");
	return 0;
}
