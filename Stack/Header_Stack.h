
class NumStack //������ �����
{
	int *NumArray;//������
	int size;//������
	int curIndex;//������� ������
public:
	//����������� �� ������������� ��������
	NumStack (int Sz)
	{
		NumArray = new int [Sz];
		size=Sz;
	}
	//�������� - ����� �� ����?
	bool isFull()
	{
		return curIndex==size-1;
	}
	//�������� - ���� �� ����?
	bool isEmpty()
	{
		return curIndex<=-1;
	}
	//������� �������� � ����
	void push (int Elem)
	{
		if (isFull() )
		{
			throw "NumStack is full";
		}
		curIndex++;
		NumArray[curIndex]=Elem;
	}
	// ���� ������� �� �����
	int pop ()
	{
		if (isEmpty() )
		{
			throw "Numstack is empty";
		}
		curIndex--;
		return NumArray[curIndex+1];
	}
//����������� ����� �����
	void rePackNumStack(int ElemIndex)
	{
		//NumArray[ElemIndex]=;//��������� �������� ��� ����������� ���� x y +(���)-(��� ������ ��������)
		for (int i=ElemIndex;i<size;i++)
		{
			if (NumArray[ElemIndex+3]==0)//����������� ��� ����������� ����� ������������ ����� � �����
			{
				break;
			}
			NumArray[ElemIndex]=NumArray[ElemIndex+3];
		}
	}
};


//=================================================================================================================
//=================================================================================================================
//=================================================================================================================


class OperatorStack//�������� ���� ����������
{
	int operCount; //������
	char *operators; //������
	int currentOperatorIndex; //������� ������
public:
	//�����������
	OperatorStack (int Sz)
	{
		operators = new char [Sz];
		operCount=Sz;
	}
	//�������� - ����� �� ����?
	bool isFull()
	{
		return currentOperatorIndex==operCount-1;
	}
	//�������� - ���� �� ����?
	bool isEmpty()
	{
		return currentOperatorIndex<=-1;
	}
	//������� �������� � ����
	void push (int Elem)
	{
		if (isFull() )
		{
			throw "Stack is full";
		}
		currentOperatorIndex++;
		operators[currentOperatorIndex]=Elem;
	}
	// ���� ������� �� �����
	int pop ()
	{
		if (isEmpty() )
		{
			throw "There are no operators";
		}
		currentOperatorIndex--;
		return operators[currentOperatorIndex+1];
	}
};
//========================================================================
//====================================================================
//��������� ���� ����������
//�� ����������� - ��� �� ���� ����������
class tempOperatorStack
{
	int operCount; //������
	char *operators; //������
	int current_tempOperatorIndex; //������� ������
public:
	//�����������
	tempOperatorStack (int Sz)
	{
		operators = new char [Sz];
		operCount=Sz;
		for (int i=0;i<operCount;i++)
		{
			operators[i]=0;//���� � ������ ����� - ��� �������
		}
	}
	//�������� - ����� �� ����?
	bool isFull()
	{
		return current_tempOperatorIndex==operCount-1;
	}
	//�������� - ���� �� ����?
	bool isEmpty()
	{
		return current_tempOperatorIndex<=-1;
	}
	//������� �������� � ����
	void push (int Elem)
	{
		if (isFull() )
		{
			throw "Stack is full";
		}
		current_tempOperatorIndex++;
		operators[current_tempOperatorIndex]=Elem;
	}
	// ���� ������� �� �����
	int pop ()
	{
		if (isEmpty() )
		{
			throw "There are no operators";
		}
		current_tempOperatorIndex--;
		return operators[current_tempOperatorIndex+1];
	}

	int getSize()
	{
		return current_tempOperatorIndex;
	}
};

//=====================================================================
//=====================================================================
//=====================================================================

//������� ����������
class Quete
{
	char *array;
	int size;
	int startIndex, endIndex;
public:
	Quete (int Sz)
	{
		array=new char[Sz];
		startIndex=0;
		endIndex=1;
		size=Sz;
	}
	~Quete()
	{
		delete array;
	}
//=======================================================
	bool isEmpty()
	{
		return ( startIndex+1 )%size==endIndex;
	}

	bool isFull()
	{
		return ( startIndex+2 )%size==endIndex;
	}
//======================================================
	void push (char Elem)
	{
		if ( isFull() )
		{
			throw "Quete is full";
		}
		startIndex=(startIndex+1)%size;
		array [startIndex]=Elem;
	}

	char pop()
	{
		if ( isEmpty() )
		{
			throw "Quete is empty";
		}
		char tempElem=array[endIndex];
		endIndex=(endIndex+1)%size;
		return tempElem;
	}
//======================================================
};

