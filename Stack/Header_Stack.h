
class NumStack //массив чисел
{
	int *NumArray;//массив
	int size;//размер
	int curIndex;//текущий индекс
public:
	//конструктор по передаваемому значению
	NumStack (int Sz)
	{
		NumArray = new int [Sz];
		size=Sz;
	}
	//проверка - полон ли стек?
	bool isFull()
	{
		return curIndex==size-1;
	}
	//проверка - пуст ли стек?
	bool isEmpty()
	{
		return curIndex<=-1;
	}
	//вставка элемента в стек
	void push (int Elem)
	{
		if (isFull() )
		{
			throw "NumStack is full";
		}
		curIndex++;
		NumArray[curIndex]=Elem;
	}
	// берём элемент из стека
	int pop ()
	{
		if (isEmpty() )
		{
			throw "Numstack is empty";
		}
		curIndex--;
		return NumArray[curIndex+1];
	}
//перепаковка стека чисел
	void rePackNumStack(int ElemIndex)
	{
		//NumArray[ElemIndex]=;//изменение элемента при вычислениях вида x y +(или)-(или другой оператор)
		for (int i=ElemIndex;i<size;i++)
		{
			if (NumArray[ElemIndex+3]==0)//выполняется при обнаружении конца существующих чисел в стеке
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


class OperatorStack//конечный стек операторов
{
	int operCount; //размер
	char *operators; //массив
	int currentOperatorIndex; //текущий индекс
public:
	//конструктор
	OperatorStack (int Sz)
	{
		operators = new char [Sz];
		operCount=Sz;
	}
	//проверка - полон ли стек?
	bool isFull()
	{
		return currentOperatorIndex==operCount-1;
	}
	//проверка - пуст ли стек?
	bool isEmpty()
	{
		return currentOperatorIndex<=-1;
	}
	//вставка элемента в стек
	void push (int Elem)
	{
		if (isFull() )
		{
			throw "Stack is full";
		}
		currentOperatorIndex++;
		operators[currentOperatorIndex]=Elem;
	}
	// берём элемент из стека
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
//временный стек операторов
//По конструкции - тот же стек операторов
class tempOperatorStack
{
	int operCount; //размер
	char *operators; //массив
	int current_tempOperatorIndex; //текущий индекс
public:
	//конструктор
	tempOperatorStack (int Sz)
	{
		operators = new char [Sz];
		operCount=Sz;
		for (int i=0;i<operCount;i++)
		{
			operators[i]=0;//ноль в данном стеке - это пустота
		}
	}
	//проверка - полон ли стек?
	bool isFull()
	{
		return current_tempOperatorIndex==operCount-1;
	}
	//проверка - пуст ли стек?
	bool isEmpty()
	{
		return current_tempOperatorIndex<=-1;
	}
	//вставка элемента в стек
	void push (int Elem)
	{
		if (isFull() )
		{
			throw "Stack is full";
		}
		current_tempOperatorIndex++;
		operators[current_tempOperatorIndex]=Elem;
	}
	// берём элемент из стека
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

//очередь операторов
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

