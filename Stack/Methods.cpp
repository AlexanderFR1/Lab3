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



void fillStacks (char str)//���������� ������ ����� � ����������
{
	int strSize;
	int opCount;//���-�� �������� ������
	int curPriority;// ����� �� ������ ������ ������������ ��������� ������� � ������-���� ���������
	int sizeTempOperStack;
	strSize=strlen(str);
	for (int i=0;i<strSize;i++)
	{
		if ( (str[i] >= '0') || (str[i]<='9') )
		{
			NumStack.push(str[i]);//����������� ���� �����
		}
		//������ - ���������� ����� ����������
		if ( (str[i]=='+') || (str[i]=='-') || (str[i]=='*') || (str[i]=='/') )
		{
			if ( (str[i]=='+') || (str[i]=='-') )//������� ��� ����/�����
			{
				if (curPriority<=1)//���� ������ ������ ����� ��� ������ ���
				{
					curPriority=1;
					tempOperatorStack.push(str[i]);//����� ���� ����/����� �� ��������� ����
				}
				else //�� ���� ����. ��������� �� ���� � ����, � ���-�� ������ ����� ����
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

			if ( (str[i]=='+') || (str[i]=='-') )//�������� ��� ���������/�������
			{
				if (curPriority==2)//� ������ ������ * ��� / ���
				{				
					Quete.push(str[i]);
				}
				else//�� ���� ����� * ��� / ���� = ��� -
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