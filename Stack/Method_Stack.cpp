#include "Header_Stack.h"
#include <stdlib.h>


// �����������
template <typename Stack_type>
Stack<Stack_type>::Stack(int n)
{
	isArend=true;
	size=n;
	if ( stackArray==NULL )
	{
		isArend=false;
		stackArray=new Stack_type [n];
		ind=-1;
	}
}
 
// ����������
template <typename Stack_type>
Stack<Stack_type>::~Stack()
{
	if ( !isArend )
	{
		delete [] stackArray;
	}
}
 //======================================================================================================================
 //===============-  - ������ - - =======================================================================================
 //======================================================================================================================
template <typename Stack_type>
bool isEmpty()
{
	return ind<=-1;
}
template <typename Stack_type>
bool isFull()
{
	return ind==n-1;
}

//==============================���������� � ������������===================

template <typename Stack_type>
void Stack<Stack_type>::push(const Stack_type value)
{
	if ( isFull() )
	{
		throw "Stack is Full";
	}

    ind++;
    stackArray[ind] = value; // �������� ������� � ����

}
 

template <typename Stack_type>
void Stack<Stack_type>::pop()
{
    if ( isEmpty() )
	{
		throw "Error";
	}

    ind--;
	return stackArray[ind+1];
}

