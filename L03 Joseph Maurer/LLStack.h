/************************************************************************
* Class: Stack
*
* Purpose: This class was created to handle the methods and transfer
*		of data with regards to a doubly linked list and a stack frame.
*		It utilizes an earlier built LL class. Some adjustments were
*		made in order to better accomidate this assignments stipulations.
*
*	Note: Remove calls to print forwards which occur at the end of push
*		and pop. This is mainly done for testing purposes.
*
* Manager functions:
* 	Stack<T>()
* 		Sets the default values for the Stack.
*	Stack<T>(const DoubleLinkedList<T> & copy)
*		Copy CTOR that copies over all of information.
*	Stack<T> & operator=(const DoubleLinkedList<T> & rhs)
*		Transferes the elements of one list into anthor.
*	~Stack<T>()
*		Destructor. This manager function deallocates the memory back
*				to the operating system.
*
*
* Methods:
*	void Push(T data);
*		FIFO. Pushes the data on top of the stack.
*	T Pop();
*		FIFO. Pops the last pushed element off of the
*		stack.
*	T Peek();
*		Looks to see the next element in the stack.
*	int Size();
*		Returns the size of the stack.
*	bool isEmpty()
*		Returns when the list is empty, true. else false.
*
*************************************************************************/
#ifndef LLSTACK_H
#define LLSTACK_H
#include "doublelinkedlist.h"

template <typename T>
class LLStack
{
public:
	// Canonical Functions
	LLStack();
	LLStack(const LLStack<T> & copy);
	LLStack<T> operator=(const LLStack<T> & rhs);
	~LLStack();

	// Class Methods
	void Push(T data);
	T Pop();
	T Peek();
	int Size();
	bool isEmpty();
private:
	DoubleLinkedList<T> m_stack;
	// How many elements are in the stack right now
	int m_current_size;
};

/**********************************************************************
* Purpose: This function is a constructor that builds the inital stack
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
template <typename T>
LLStack<T>::LLStack() : m_stack(DoubleLinkedList<T>()), m_current_size(0)
{}
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
LLStack<T>::LLStack(const LLStack<T> & copy)
{
	m_stack = copy.m_stack;
}
/**********************************************************************
* Purpose: This function is an op=. For future compatability, this
*		function calls the op= of the DLL.
*
* Entry: This function takes an right hand side argument.
*
* Exit: This function does not have a return.
*
************************************************************************/
template <typename T>
LLStack<T> LLStack<T>::operator=(const LLStack<T> & rhs)
{
	if (this != &rhs)
	{
		m_stack = rhs.m_stack;
		m_current_size = rhs.m_current_size;
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
LLStack<T>::~LLStack()
{}

/**********************************************************************
* Purpose: This function pushes the passed data onto the stack.
*
* Entry: This function takes data T.
*
* Exit: This function does not have a return.
*
************************************************************************/
template <typename T>
void LLStack<T>::Push(T data)
{
	m_stack.Append(data);
	m_current_size++;

}
/**********************************************************************
* Purpose: This function pops off the last added element of the LL.
*		It then returns that value so you know you did the right one.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns a value of the Node removed from the stack.
*
************************************************************************/
template <typename T>
T LLStack<T>::Pop()
{
	T pop_return;

	if (m_current_size <= 0)
		throw Exception("Error: Stack is empty\n");
	else
	{
		m_current_size--;
		pop_return = m_stack.Last();


		m_stack.Extract(m_stack.Last());
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
T LLStack<T>::Peek()
{
	return m_stack.Last();
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
int LLStack<T>::Size()
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
bool LLStack<T>::isEmpty()
{
	bool empty(true);
	if (m_current_size > 0)
		empty = false;
	return empty;
}

#endif