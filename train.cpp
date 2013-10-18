/*
 *Prupose: Implement the sorting function
 *Author: Yuchao Zhou
 *Time: 10/16/2013
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "LinkedStack.h"

using namespace std;

int times = 0;
vector<LinkedStack> stack;
vector<int> result;

int targetNumber = 1;
int carNumber = 0;
bool output = false;

//outputs instructions to ove a car from a holding track to the output track.
bool outputFromHoldTrack(int tNumber)
{
	output = false;
	int once = 0;
	targetNumber = tNumber;
	cout<<"target: "<<targetNumber<<endl;
	for (int i = 0; i < stack.size(); i++)
	{
		int posible = stack[i].top();
		cout<<"posible "<<i<<": "<<posible<<endl;
		
		if (posible == targetNumber)
		{
			cout<<"bingo in stack"<<endl;
			result.push_back(stack[i].pop());
			//carNumber--;
			targetNumber++;
			cout<<"next targetNumber: "<<targetNumber<<endl;
			output = true;
			once = 1;
			cout<<"output: "<<output<<endl;
			//outputFromHoldTrack��targetNumber��;
			//return output;
		}
		else
		{
			//output = false;
			//return output;
		}
	}
	return output;
}


//putinHold����Ҫ����Railroadǰ�棬����������£���Ȼ������Ҳ�����ʾ��
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

	//�ж�stack�Ƿ�����
	if (contain == stack.size())
	{
		notfull == false;
	}
	else
	{
		notfull == true;
	}

	//���stack 0 Ϊ�գ������
	if (stack[0].top() == 0)
	{
		stack[0].push(c);
		contain++;
		cout<<"push "<<c<<" into stack 0"<<endl;
		cout<<"now:"<<endl;
		for (int i = 0; i < stack.size(); i++)
		{
			cout<<"stack "<<i<<" : "<<stack[i].top()<<endl;
		}
	}
	else  //�ж��Ƿ���Ѳ������ֵ�stack��top�����������µ�stack�����С����ԭ��stack������
	{
		cout<<"previous:"<<endl;
		for (int i = 0; i < stack.size(); i++)
		{
			cout<<"stack "<<i<<" : "<<stack[i].top()<<endl;
			if (stack[i].top() != 0)
			{
				contain++;
			}
		}
		cout<<contain<<" stack has content "<<endl;
		//�Ƚϴ�С
		int currentGap = 0;
		int previousGap = 0;

		for (int i = 0; i < contain; i++)
		{
			if (i == (contain - 1))
					finish = true;
			//���С��top�����
			if (c < stack[i].top())
			{
				stack[i].push(c);
				cout<<"push "<<c<<" into stack "<<i<<endl;
				cout<<"now:"<<endl;
				for (int i = 0; i < stack.size(); i++)
				{
					cout<<"stack "<<i<<" : "<<stack[i].top()<<endl;
				}
				break;
			}
			else if ((finish == true) && (contain < stack.size()))
			{
				stack[contain].push(c);
				contain++;
				cout<<"push "<<c<<"into stack "<<contain-1<<endl;
				cout<<"now:"<<endl;
				for (int i = 0; i < stack.size(); i++)
				{
					cout<<"stack "<<i<<" : "<<stack[i].top()<<endl;
				}
				if (contain == stack.size())
				{
					cout<<"stacks are full "<<endl;
				}
				break;
			}
		}
	}


			





	////���ȱ���stack����û�пյġ�
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
	////�пյģ������
	//if (notfull == true)
	//{
	//	stack[notFullSlut].push(c);
	//}
	////����ѡ�����
	//else
	//{
	//		int i = 0;
	//		int a = 1;
	//		int currentGap = 0;
	//		int previousGap = 0;
	//		//��stack��top���뵽temp
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
	//		//���temp
	//		cout<<"temp:  ";
	//		for (int i = 0; i < temp.size(); i++)
	//		{

	//			cout<<"  "<<temp[i]<<" ";
	//		}
	//		//������С
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
		//���stack��topΪ0�������
		//if (stack[i].top() == 0)
		//{
		//	stack[i].push(c);
		//	return true;
		//}
		//else//���stack��top��Ϊ0����Ƚϸ��Ǹ�stack��ӽ���Ȼ�����
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

	cout<<"totle number of cars: "<<totle<<endl<<endl;

	while (carNumber > 0)
	{
		int currentNumber = inputOrder[carNumber - 1];
		cout<<"~~~~~~~~~~~~~~"<<endl;
		cout<<"the size of cars: "<<carNumber<<endl;
		cout<<"the current number is : "<<currentNumber<<endl;
		//int targetNumber = totle - carNumber + 1;
		cout<<"the target number is : "<<targetNumber<<endl;

		//���currentNumber������targetNumber�������stack��
		if (currentNumber != targetNumber)
		{
			cout<<"currentNumber is not equal to targetNumber"<<endl;
			putinHold(currentNumber);
			carNumber--;
		}
		//��currentNumberֱ�ӷŵ�output�����У����Ҳ鿴stack��input
		else
		{
			cout<<"bingo in input"<<endl;
			result.push_back(currentNumber);
			carNumber--;
			targetNumber++;
			outputFromHoldTrack(targetNumber);
			while (output == true)
			{
				cout<<"here again"<<endl;
				outputFromHoldTrack(targetNumber);
			}
		}

		//���output������
		cout<<"the output vector: ";
		for (int i = 0; i < result.size(); i++)
		{
			cout<<result[i]<<" ";
		}
		cout<<endl<<endl;
		cout<<"carNumber: "<<carNumber<<endl;
	}
	return done;
}

int main()
{
	//int cars[9] = {7, 6, 1, 5, 4, 3, 2, 8, 9};
	 //int cars[9] = {7, 5, 1, 4, 9, 3, 2, 8, 6};
	 int cars[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	//int cars[4] = {7, 6, 1, 5};
	Railroad(cars, 9, 1);
	//putinHold(7);
	system("pause");
	return 0;
}