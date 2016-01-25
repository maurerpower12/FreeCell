/************************************************************************
* Class: Stack
*
* Updates:
*		1. Updated to include default ctor, and set length function
*
* Purpose: This class creates a stack that can push and pop off a
*		virtual stack. It also allows for stack maniulation
*		and
*
* Manager functions:
* 	Array ( )
* 		The default length is zero and the starting index is zero.
*	Array (int length, int start_index = 0)
*		Creates an appropriate sized array with the starting index
*              either zero or the supplied starting value.
*	Array (const Array & copy)
*		Copy Contructor that will instantiate another array and
*				copy over the data involved with the passed array.
*	operator = (const Array & copy)
*		Transferes the elements of one array into anthor via a deep
*				copy.
*	~Array()
*		Destructor. This manager function deallocates the memory back
*				to the operating system, and resets to nullptr or 0;
*
* Methods:
*	operator [ ] (int index)
*		Allows the consumer to do array[1] in main. Returns the value
*				at the assosiated address.
*	getStartIndex()
*		Returns the start index of the array as an integer.
*	setStartIndex(int start_index)
*		Sets the arrays start_index to the passed parameter.
*	getLength()
*		Returns the length of the passed array as an integer.
*	setLength(int length)
*		Sets the length of the array passed to the value of the integer
*				passed to the function.
*************************************************************************/
#ifndef STACK_H
#define STACK_H
#include "Array.h"

template <typename T>
class Stack
{
public:
	// Canonical Functions
	Stack();
	Stack(int stack_size);
	Stack(const Stack & copy);
	Stack<T> operator=(const Stack & rhs);
	~Stack();

	void setLength(int length);
	// Class Methods
	void Push(T data);
	T Pop();
	T Peek();
	int Size();
	bool isEmpty();
	bool isFull();
private:
	Array<T> m_stack;
	// Max size of the stack
	int m_stack_size;
	// How many elements are in the stack right now
	int m_current_size;
	int m_start_index;

};

template <typename T>
Stack<T>::Stack()
	: m_stack(0), m_stack_size(0), m_current_size(0), m_start_index(0)
{}



/**********************************************************************
* Purpose: This function is a constructor that builds the inital stack
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
template <typename T>
Stack<T>::Stack(int stack_size)
	: m_stack(0), m_stack_size(stack_size), m_current_size(0), m_start_index(0)
{

}
/**********************************************************************
* Purpose: This function is a Copy CTOR. It basically just calls
*		the op= for the DLL class which does the deep copy.
*
* Entry: This function does take a Stack object by reference to
*			copy the data from.
*
* Exit: This function does not have a return.
*
************************************************************************/
template <typename T>
Stack<T>::Stack(const Stack & copy)
{
	m_stack = copy.m_stack;
	m_stack_size = copy.m_stack_size;
	m_start_index = copy.m_start_index;
}
/**********************************************************************
* Purpose: This function is an op=. For future compatability, this
*		function calls the op= of the array.
*
* Entry: This function takes an right hand side argument.
*
* Exit: This function does not have a return.
*
************************************************************************/
template <typename T>
Stack<T> Stack<T>::operator=(const Stack & rhs)
{
	if (this != &rhs)
	{
		m_stack = rhs.m_stack;
		m_stack_size = rhs.m_stack_size;
		m_start_index = rhs.m_start_index;
	}
	return *this;
}
/**********************************************************************
* Purpose: This function is a DTOR.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
template <typename T>
Stack<T>::~Stack()
{
	m_stack_size = 0;
}


/**********************************************************************
* Purpose: This function pushes the passed data onto the stack.
*
* Entry: This function takes data T.
*
* Exit: This function does not have a return.
*
************************************************************************/
template <typename T>
void Stack<T>::Push(T data)
{
	m_current_size++;
	if (m_current_size > m_stack_size)
		throw Exception("Error: Stack is full\n");
	else
	{
		Array<T> temp(m_current_size, 0);
		temp = m_stack;

		// Put in the new data
		temp.setLength(m_current_size);
		temp[m_current_size - 1] = data;
		m_stack.setLength(m_current_size);
		//Copy everything over to the old array
		m_stack = temp;
	}
	//for (int i(0); i < m_current_size; i++)
		//cout << m_stack[i] << ' ';
	//cout << endl;
}
/**********************************************************************
* Purpose: This function pops off the last added element of the array.
*		It then returns that value so you know you did the right one.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns a value of the element removed from the
*		stack.
*
************************************************************************/
template <typename T>
T Stack<T>::Pop()
{
	T pop_return;

	if (m_current_size <= 0)
		throw Exception("Error: Stack is empty\n");
	else
	{
		m_current_size--;
		pop_return = m_stack[m_current_size - 1];


		m_stack.setLength(m_current_size);
	}
	return pop_return;
}

/**********************************************************************
* Purpose: This function returns the value of the last item
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns the value of the last item.
*
************************************************************************/
template <typename T>
T Stack<T>::Peek()
{
	return m_stack[m_current_size - 1];
}

/**********************************************************************
* Purpose: This function gets and returns the size of the Stack.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns the size of the stack.
*
************************************************************************/
template <typename T>
int Stack<T>::Size()
{
	return m_current_size;
}
/**********************************************************************
* Purpose: This function looks to see if the Stack is empty. If it is
*		it returns true.
*
* Entry: This function does not take any arguments.
*
* Exit: This function a bool for if the list is full or not.
*
************************************************************************/
template <typename T>
bool Stack<T>::isEmpty()
{
	bool empty(true);
	if (m_current_size > 0)
		empty = false;
	return empty;

}
/**********************************************************************
* Purpose: This function looks to see if the Stack is Full. If it is
*		it returns true.
*
* Entry: This function does not take any arguments.
*
* Exit: This function a bool for if the list is full or not.
*
************************************************************************/
template <typename T>
bool Stack<T>::isFull()
{
	bool full(false);
	if (m_current_size >= m_stack_size)
		full = true;
	return full;
}

template <typename T>
void Stack<T>::setLength(int length)
{
	m_stack_size = length;
}
#endif