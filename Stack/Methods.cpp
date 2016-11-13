#ifndef __HEADERMETHODS__
#define __HEADERMETHODS__
#include "Header_Stack.h"
#include <string.h>

bool checkString(char str)
{
	int strSize;
	int Brackets;
	strSize=strlen(str);
	Brackets=0;
	
	for (int i=0;i<strSize;i++)
	{
		/*
		if ( ( (str[i]<'0')||(str[i]>'9') )&&( (str[i]!='+')||( str[i]!='-')||(str[i]!='*')||(str[i]!='/') ) )
		{
			throw "incorrect string";
		}
		*/
		if (str[i]=='(')
		{
			Brackets++;
		}
		if(str[i]==')')
		{
			Brackets--;
		}
	}
	if ( Brackets!=0 )
	{
		return false;
	}
	else
	{
		return true;
	}
}



void fillStacks (char str)//заполнение стеков чисел и операторов
{
	int strSize;
	int opCount;//кол-во открытых скобок
	int curPriority;// каков на данный момент максимальный приоритет имеется у какого-либо оператора
	int sizeTempOperStack;
	strSize=strlen(str);
	for (int i=0;i<strSize;i++)
	{
		if ( (str[i] >= '0') || (str[i]<='9') )
		{
			NumStack.push(str[i]);//заполняется стек чисел
		}
		//Дальше - заполнение стека операторов
		if ( (str[i]=='+') || (str[i]=='-') || (str[i]=='*') || (str[i]=='/') )
		{
			if ( (str[i]=='+') || (str[i]=='-') )//попался нам плюс/минус
			{
				if (curPriority<=1)//если ничего важнее плюса или минуса нет
				{
					curPriority=1;
					tempOperatorStack.push(str[i]);//кладём этот плюс/минус во временный стек
				}
				else //то есть макс. приоритет от двух и выше, и что-то важнее плюса есть
				{

					/*
					if ((str[i]=='*') || (str[i]=='/') )
					{
						sizeTempOperStack=tempOperatorStack.getSize();
						curPriority=2;
						Quete.push(str[i]);
						for (int i=0;i<sizeTempOperStack;i++)
						{

						}
					}
					*/
				}
			}

			if ( (str[i]=='+') || (str[i]=='-') )//попалось нам умножение/деление
			{
				if (curPriority==2)//и ничего важнее * или / нет
				{				
					Quete.push(str[i]);
				}
				else//то есть перед * или / есть = или -
					if (curPriority==1)
				{
					Quete.push(str[i]);
					tempOperatorStack.push(str[i]);
				}
			}

			if (str[i]==='(')
			{
				curPriority=0;
			}
			if (str[i]===')')
			{
				curPriority=0;
			}
		}

#endif