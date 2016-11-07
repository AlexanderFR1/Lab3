
template <typename Stack_type>
class Stack
{
	private:
		Stack_type *stackArray; 
		int size; 
		Stack_type ind; 
		bool isArend;
	public:
		Stack(int = 10);
		~Stack(); 

		void push( const Stack_type  );
		void pop(); 

		bool isEmpty();
		bool isFull();

		int getCount()
		{
			return ind+1;
		}
};