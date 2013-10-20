/*
 *Prupose: Implement the sorting function
 *Author: Yuchao Zhou
 *Time: 10/16/2013
 */
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
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


string int_string(int num)
{
	stringstream ss;
	ss<<num;
	string s=ss.str();
	return s;
}

//outputs instructions to ove a car from a holding track to the output track.
//bool outputFromHoldTrack(int tNumber)
//{
//	output = false;
//	int once = 0;
//	targetNumber = tNumber;
//	//cout<<"target: "<<targetNumber<<endl;
//	for (int i = 0; i < stack.size(); i++)
//	{
//		int posible = stack[i].top();
//		//cout<<"posible "<<i<<": "<<posible<<endl;
//		
//		if (posible == targetNumber)
//		{
//			//cout<<"bingo in stack"<<endl;
//			//cout<<"Move car "<<posible<<" from holding track "<<i<<" to output"<<endl;
//			str = "Move car " + int_string(posible) + " from holding track " + int_string(i) + " to output";
//			procedure.push_back(str);
//			//cout<<str<<endl;
//
//			result.push_back(stack[i].pop());
//			//carNumber--;
//			targetNumber++;
//			//cout<<"next targetNumber: "<<targetNumber<<endl;
//			output = true;
//			once = 1;
//			//cout<<"output: "<<output<<endl;
//			//outputFromHoldTrack（targetNumber）;
//			//return output;
//		}
//	}
//	return output;
//}



bool outputFromHoldTrack(int tNumber)
{
	output = false;
	int once = 0;
	targetNumber = tNumber;
	//cout<<"target: "<<targetNumber<<endl;
	//for (int i = 0; i < stack.size(); i++)
	//{
		int posible = stack1.top();
		//cout<<"posible "<<i<<": "<<posible<<endl;
		
		if (posible == targetNumber)
		{
			//cout<<"bingo in stack"<<endl;
			//cout<<"Move car "<<posible<<" from holding track "<<i<<" to output"<<endl;
			str = "Move car " + int_string(posible) + " from holding track 1 to output";
			procedure.push_back(str);
			//cout<<str<<endl;

			result.push_back(stack1.pop());
			//carNumber--;
			targetNumber++;
			//cout<<"next targetNumber: "<<targetNumber<<endl;
			output = true;
			once = 1;
			//cout<<"output: "<<output<<endl;
			//outputFromHoldTrack（targetNumber）;
			//return output;
		}
	//}
	return output;
}




//putinHold函数要放在Railroad前面，编译从上往下，不然会出现找不到标示符
//moves car c from the input track to one of the holding tracks if possible, else it return false.
//bool putinHold(int c)
//{
//	vector<int> temp;
//	int contain = 0;
//	bool notfull = true;
//	int notFullSlut = 0;
//	int slut = 0;
//	int smallest = 0;
//	bool result = true;
//	int finish = false;
//
//	//判断stack是否已满
//	if (contain == stack.size())
//	{
//		notfull == false;
//	}
//	else
//	{
//		notfull == true;
//	}
//
//	//如果stack 0 为空，则插入
//	if (stack[0].top() == 0)
//	{
//		stack[0].push(c);
//		contain++;
//		//cout<<"holding track 0 hold car "<<c<<endl;
//		str = "holding track 0 hold car "+int_string(c);
//		procedure.push_back(str);
//		//cout<<str<<endl;
//		//cout<<"now:"<<endl;
//		for (int i = 0; i < stack.size(); i++)
//		{
//			//cout<<"stack "<<i<<" : "<<stack[i].top()<<endl;
//		}
//	}
//	else  //判断是否比已插入数字的stack的top大，如果大插入新的stack，如果小插在原先stack的上面
//	{
//		//cout<<"previous:"<<endl;
//		for (int i = 0; i < stack.size(); i++)
//		{
//			//cout<<"stack "<<i<<" : "<<stack[i].top()<<endl;
//			if (stack[i].top() != 0)
//			{
//				contain++;
//			}
//		}
//		//cout<<contain<<" stack has content "<<endl;
//		//比较大小
//		int currentGap = 0;
//		int previousGap = 0;
//
//		for (int i = 0; i < contain; i++)
//		{
//			if (i == (contain - 1))
//					finish = true;
//			//如果小于top则插入
//			if (c < stack[i].top())
//			{
//				stack[i].push(c);
//				//cout<<"push "<<c<<" into stack "<<i<<endl;
//				//cout<<"holding track "<<i<<" hold car "<<c<<endl;
//				str = "holding track " + int_string(i) + " hold car " + int_string(c);
//				procedure.push_back(str);
//				//cout<<str<<endl;
//				//cout<<"now:"<<endl;
//				for (int i = 0; i < stack.size(); i++)
//				{
//					//cout<<"stack "<<i<<" : "<<stack[i].top()<<endl;
//				}
//				break;
//			}
//			else if ((finish == true) && (contain < stack.size()))
//			{
//				stack[contain].push(c);
//				contain++;
//				//cout<<"push "<<c<<"into stack "<<contain-1<<endl;
//				//cout<<"holding track "<<contain-1<<" hold car "<<c<<endl;
//				str = "holding track " + int_string(contain -1) + " hold car " + int_string(c);
//				procedure.push_back(str);
//				//cout<<str<<endl;
//				//cout<<"now:"<<endl;
//				for (int i = 0; i < stack.size(); i++)
//				{
//					//cout<<"stack "<<i<<" : "<<stack[i].top()<<endl;
//				}
//				if (contain == stack.size())
//				{
//					//cout<<"stacks are full "<<endl;
//				}
//				break;
//			}
//		}
//	}
//

			
bool putinHold(int c)
{
	//cout<<"current number: "<<c<<endl;
	
	bool result = true;
	//cout<<"stack1.top: "<<stack1.top()<<endl;
	if (stack1.top() == 0)
	{
		stack1.push(c);
		stack_number = 1;
		//cout<<"init: push "<<c<<" into stack 1"<<endl;
		cout<<"holding track "<<1<<" hold car "<<c<<endl;
		cout<<endl;
		//cout<<stack1.top()<<endl;
		return result;
	}
	if (stack1.top() > c)
	{
		stack1.push(c);
		cout<<"holding track "<<1<<" hold car "<<c<<endl;
		cout<<endl;
		//cout<<"push "<<c<<" into stack 1"<<endl;
		//cout<<stack1.top()<<endl;
		return result;
	}
	if (stack1.top() < c)
	{
		while ((stack1.top() < c) &&(stack1.top() != 0))
		{
			//cout<<"push "<<stack1.top()<<" into stack 2"<<endl;
			cout<<"holding track "<<2<<" hold car "<<stack1.top()<<endl;
			stack2.push(stack1.pop());
			
			stack_number = 2;
		}
		stack1.push(c);
		cout<<"holding track "<<1<<" hold car "<<c<<endl;
		//cout<<"push "<<c<<" into stack 1"<<endl;
		while (stack2.empty() == false)
		{
			//cout<<"push "<<stack2.top()<<" fromo stack 2 into stack 1"<<endl;
			cout<<"holding track "<<1<<" hold car "<<stack2.top()<<endl;
			stack1.push(stack2.pop());
		}
		cout<<endl;
	}
	//cout<<endl;
	//stack1.traverse();
	//while(stack1.empty() == false)
	//{
	//	cout<<






//~~~~~~~~~~~~~~~~~wrong~~~~~~~~~~~~~
	////首先遍历stack看有没有空的。
	//for (int i = 0; i < stack.size(); i++)
	//{
	//	cout<<"stack "<<i<<" : "<<stack[i].top()<<endl;
	//	if (stack[i].top() == 0)
	//	{
	//		//cout<<i<<"stack is not full"<<endl;
	//		notfull = true;
	//		notFullSlut = i;
	//		break;
	//	}
	//	else
	//	{
	//		//cout<<"stack is full"<<endl;
	//		notfull = false;
	//	}
	//}
	////有空的，则插入
	//if (notfull == true)
	//{
	//	stack[notFullSlut].push(c);
	//}
	////否则，选择插入
	//else
	//{
	//		int i = 0;
	//		int a = 1;
	//		int currentGap = 0;
	//		int previousGap = 0;
	//		//把stack的top输入到temp
	//		while (i < stack.size())
	//		{
	//			int top = stack[i].top();
	//			if (top < c)
	//			{
	//				temp.push_back(99);
	//				i++;
	//			}
	//			else
	//			{
	//				temp.push_back(stack[i].top());
	//				i++;
	//			}
	//		}
	//		//输出temp
	//		cout<<"temp:  ";
	//		for (int i = 0; i < temp.size(); i++)
	//		{

	//			cout<<"  "<<temp[i]<<" ";
	//		}
	//		//分析大小
	//		previousGap = temp[a - 1] - c;
	//		//cout<<"temp.size(): "<<temp.size()<<endl;
	//		while (a < temp.size())
	//		{
	//			currentGap = temp[a] - c;
	//			if (previousGap <= currentGap)
	//			{
	//				smallest = previousGap;
	//				previousGap = previousGap;
	//				//slut = a - 1;
	//			}
	//			else
	//			{
	//				smallest = currentGap;
	//				previousGap = currentGap;
	//				//slut = a;
	//			}
	//			a++;
	//		}
	//		for (int i = 0; i < temp.size(); i++)
	//		{
	//			if (temp[i] == (smallest + c))
	//			{
	//				slut = i;
	//			}
	//		}
	//		cout<<"the number is "<<smallest + c;
	//		cout<<"the slut is "<<slut<<endl;
	//		stack[slut].push(c);
	//}
	return result;
}

	//cout<<"the number of holding tracks: "<<stack.size()<<endl;
	//for (int i = 0; i < stack.size(); i++)
	//{
		//cout<<"stack "<<i<<" : "<<stack[i].top()<<endl;
		//如果stack的top为0，则插入
		//if (stack[i].top() == 0)
		//{
		//	stack[i].push(c);
		//	return true;
		//}
		//else//如果stack的top不为0，则比较跟那个stack最接近，然后插入
		//{
			
	
	

bool Railroad (int inputOrder[], int numberofCars, int numberofTracks)
{
	//int vectorSize = 0;
	int totle = numberofCars;
	times = numberofCars;
	bool done = false;
	carNumber = numberofCars;
	const int trackNumber = numberofTracks;
	//cout<<trackNumber;
	stack.resize(trackNumber);
	//cout<<"stack size:  "<<stack.size();

	cout<<"input array: "<<endl;
	for (int i = 0; i < carNumber; i++)
	{
		cout<<inputOrder[i]<<" ";
	}
	cout<<endl;

	//cout<<"totle number of cars: "<<totle<<endl<<endl;

	while (carNumber > 0)
	{
		int currentNumber = inputOrder[carNumber - 1];
		//cout<<"~~~~~~~~~~~~~~"<<endl;
		//cout<<"the size of cars: "<<carNumber<<endl;
		//cout<<"the current number is : "<<currentNumber<<endl;
		//int targetNumber = totle - carNumber + 1;
		//cout<<"the target number is : "<<targetNumber<<endl;

		//如果currentNumber不等于targetNumber，则放入stack中
		if (currentNumber != targetNumber)
		{
			//cout<<"currentNumber is not equal to targetNumber"<<endl;
			putinHold(currentNumber);
			carNumber--;
		}
		//把currentNumber直接放到output序列中，并且查看stack和input
		else
		{
			//cout<<"bingo in input"<<endl;
			//cout<<"Move car "<<currentNumber<<" from input to output"<<endl;
			str = "Move car "+ int_string(currentNumber) + " from input to output ";
			procedure.push_back(str);
			//cout<<str<<endl;
			result.push_back(currentNumber);
			carNumber--;
			targetNumber++;
			outputFromHoldTrack(targetNumber);
			while (output == true)
			{
				//cout<<"here again"<<endl;
				outputFromHoldTrack(targetNumber);
			}
		}

		//输出output的序列
		//cout<<"the output vector: ";
		for (int i = 0; i < result.size(); i++)
		{
			//cout<<result[i]<<" ";
		}
		//cout<<endl<<endl;
		//cout<<"carNumber: "<<carNumber<<endl;
		//判断是否成功
		if (carNumber == 0)
		{
			if (result.size() == numberofCars)
			{
				success = true;
				//cout<<"successful!"<<endl;
				for (int i = 0; i < procedure.size(); i++)
				{
					cout<<procedure[i]<<endl;
				}
			}
			else
			{
				success = false;
				//cout<<"unsuccessful!"<<endl;
				//cout<<inputOrder[1]<<endl;
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
	
	//int cars[9];
	//int cars[9] = {7, 6, 1, 5, 4, 3, 2, 8, 9}; //4
	//int cars[9] = {7, 5, 3, 4, 1, 2, 6, 9, 8};
	//int cars[9] = {1, 9, 8, 7, 6, 5, 4, 3, 2};
	 //int cars[9] = {7, 5, 1, 4, 9, 3, 2, 8, 6};  //3
	//int cars[9] = {9,9,9,9,9,9,9};
	 //int cars[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	//int cars[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	//int cars[4] = {7, 6, 1, 5};
	ifstream inputfile("input.txt");
	inputfile>>carnumber;
	cout<<carnumber;
	inputfile>>stacknumber;
	cout<<stacknumber;
	int *cars = new int[carnumber];
	for (int i = 0; i < carnumber; i++)
	{
		inputfile>>cars[i];
	}
	Railroad(cars, carnumber, stacknumber);
	//for (int i = 0; i < 9; i++)
	//{
	//	putinHold(cars[i]);
	//}
	//fstream file("input.txt");
	////fstream file("input2.txt");
	//if (!file)
	//{
	//	cout<<"Can not open the txt!"<<endl;
	//}
	//else
	//{
	//	//cout<<"open txt sucessfully!"<<endl;
	//	string car_number;
	//	string stack_number;
	//	string car;
	//	const char *d = " ";
	//	char* segment;

	//	getline(file, car_number);
	//	const int cn = atoi(car_number.c_str());
	//	cout<<"car number: "<<cn<<endl;
	//	
	//	int cars[9];

	//	getline(file, stack_number);
	//	int sn = atoi(stack_number.c_str());
	//	cout<<"stack number: "<<sn<<endl;
	//	
	//	getline(file,car);
	//	char* p=const_cast<char*>(car.c_str()); 
	//	segment = strtok(p, d);
	//	while(segment)
	//	{
	//		cout<<segment<<endl;
	//		segment = strtok(NULL, d);
	//		int a = atoi(segment);
	//		//cout<<a<<endl;
	//	}

	//	//int c = atoi(car.c_str());
	//	//p = strtok(car, " ");
	//	
	//	//cout<<"car: "<<c<<endl;
	//	//Railroad(cn, cn, sn);
	//}
	cout<<stack_number<<" stack we use."<<endl;
	//file.close();
	system("pause");
	return 0;
}