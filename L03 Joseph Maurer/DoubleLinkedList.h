/************************************************************************
* Class: DoubleLinkedList
* Updates:
*		1. This class has been updated to throw an Exception from
*		   apart of the Exception class instead of just a char *.
*		2. Stops PrintForwards from putting new lines after each element
*		   is displayed.
*
* Purpose: This class was created to handle the methods and transfer
*		of data with regards to a doubly linked list. The Canonical
*		Methods of this class allow the consumer to create LL objects
*		and the Mutators/Accessors give the consumer access to data.
*
* Manager functions:
* 	DoubleLinkedList<T>()
* 		The default head and tail to nullptr.
*	DoubleLinkedList<T>(const DoubleLinkedList<T> & copy)
*		Copy CTOR that copies over all of the nodes in a list.
*	DoubleLinkedList<T> & operator=(const DoubleLinkedList<T> & rhs)
*		Transferes the elements of one list into anthor via a deep
*			copy.
*	~DoubleLinkedList<T>()
*		Destructor. This manager function deallocates the memory back
*				to the operating system, and resets to nullptr or 0;
*
*
* Methods:
*		bool isEmpty()
*			Returns when the list is empty, true. else false.
*		const T & First() const
*			return a const reference to the first element.
*		const T & Last() const
*			return a const reference to the last element.
*		void Append(T data)
*			add an item to the end of the list.
*		void Prepend(T passed)
*			add an item to the front of the list.
*		void Purge()
*			remove all items from the list.
*		void Extract(T find)
*			remove a single item from the list.
*		Node<T> * Find(T data)
*			Finds the pasted data in the list.
*		void InsertAfter( T insert, T place_after)
*			insert an item after an item in the list.
*		void InsertBefore(T insert, T place_before)
*			insert an item before an item in the list.
*		void PrintForwards()
*			prints all content forward.
*		void PrintBackwards()
*			prints all contect backwards.
*************************************************************************/
#ifndef DOUBLELINKEDLIST
#define DOUBLELINKEDLIST
#include "Node.h"
#include "Exception.H"
#include <iostream>
using std::ostream;
template <typename T>
class DoubleLinkedList
{
public:
	// Canonical Methods
	DoubleLinkedList<T>();
	DoubleLinkedList<T>(const DoubleLinkedList<T> & copy);
	DoubleLinkedList<T> & operator=(const DoubleLinkedList<T> & rhs);
	~DoubleLinkedList<T>();

	// Mutators/Accessors
	const Node<T> * getHead();
	const Node<T> * getTail();

	bool isEmpty();
	const T & First() const;
	const T & Last() const;
	void Append(T data);
	void Prepend(T passed);
	void Purge();
	void Extract(T find);
	Node<T> * Find(T data);
	void InsertAfter(T insert, T place_after);
	void InsertBefore(T insert, T place_before);
	void PrintForwards();
	void PrintBackwards();
private:
	//Linked-List Class Data Members
	Node<T> * m_head;
	Node<T> * m_tail;
};

/**********************************************************************
* Purpose: This function is a constructor that builds the inital LL
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : m_head(nullptr), m_tail(nullptr)
{

}
/**********************************************************************
* Purpose: This function is a copy CTOR that preforms a deep copy of the
*		Linked List.
*
* Entry: This function takes a LL item by reference.
*
* Exit: This function does not have a return.
*
************************************************************************/
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T> & copy)
	: m_head(nullptr), m_tail(nullptr)
{
	if (copy.m_head != nullptr) // stuff in the list
	{
		Node<T> * traverse = copy.m_head;
		while (traverse) // Do a deep copy of the list
		{// append the data to the end of the new list
			Append(traverse->m_data);
			// increment to the next item in the list
			traverse = traverse->m_next;
		}
	}
	else // no stuff in the list
	{
		m_head = nullptr;
		m_tail = nullptr;
	}
}

/**********************************************************************
* Purpose: This function is a DTOR.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns a deleted list and reset members.
*
************************************************************************/
template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	if (m_head != nullptr)
	{
		// Delete everything in the list first
		Purge();
		m_head = nullptr;
		m_tail = nullptr;
	}
}
/**********************************************************************
* Purpose: This function is a getter for the LL.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns a the head of the list.
*
************************************************************************/
template <typename T>
const Node<T> * DoubleLinkedList<T>::getHead()
{
	return m_head;
}

/**********************************************************************
* Purpose: This function is a getter for the last item in the list.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns the last item in the list.
*
************************************************************************/
template <typename T>
const Node<T> * DoubleLinkedList<T>::getTail()
{
	return m_tail;
}

/**********************************************************************
* Purpose: This function is a check to see if the List is empty.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns a bool for if the LL has anything in it.
*
************************************************************************/
template <typename T>
bool DoubleLinkedList<T>::isEmpty()
{
	bool answer = false;
	if (m_head != nullptr)
	{
		answer = true;
	}
	return answer;
}
/**********************************************************************
* Purpose: This function is a getter for the first value of the LL.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns the data of the head.
*
************************************************************************/
template <typename T>
const T & DoubleLinkedList<T>::First() const
{
	if (m_head == nullptr)
	{
		throw Exception("Exception: Empty List, no first item can be found");
	}
	return m_head->m_data;
}
/**********************************************************************
* Purpose: This function is a getter that returns the last value of the LL
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns Tails data.
*
************************************************************************/
template <typename T>
const T & DoubleLinkedList<T>::Last() const
{
	if (m_head == nullptr)
	{
		throw Exception("Exception: Empty List, no last item can be found");
	}
	return m_tail->m_data;
}
/**********************************************************************
* Purpose: This function appends data to the end of a LL.
*
* Entry: This function take data to append.
*
* Exit: This function returns nothing.
*
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::Append(T data)
{
	// Add item to the end of the list
	if (m_head == nullptr) // Case for nothing in the List
	{
		m_tail = new Node<T>(data); // make the new node at the end
		m_head = m_tail; // end is also the start in this case
	}
	else
	{
		Node<T> * previous = m_tail; // save off the current end to reassign later
		
		m_tail->m_next = new Node<T>(data); // make new node, at the end of the list
		m_tail = m_tail->m_next; // set the new tail
		m_tail->m_previous = previous; // set the previous to the old tail
	}
}

/**********************************************************************
* Purpose: This function is a prepends an item to the list.
*
* Entry: This function takes data to be prepended.
*
* Exit: This function returns nothing.
*
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::Prepend(T passed)
{
	// Add item to the front of the list
	if (m_head == nullptr)
	{
		m_head = new Node<T>(passed); // make the new node
		m_tail = m_head; // head is also the tail in this case
	}
	else
	{
		Node<T> * new_node = new Node<T>(passed); // make the new node before inserting 
		new_node->m_next = m_head; // insert node at the top of the list
		m_head->m_previous = new_node; // set the previous of the old head
		m_head = new_node; // update the head pointer
	}
}
/**********************************************************************
* Purpose: This function is deletes everything in the LL.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns nothing.
*
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::Purge()
{
	Node<T> * traverse = m_head;
	while (traverse)
	{
		Node <T> * temp = traverse->m_next;// Save the next node in a temp
		delete traverse; // Delete the one your looking at
		traverse = temp; // Set the traverse to the next temp

	}
	m_head = nullptr;
	m_tail = nullptr;
}
/**********************************************************************
* Purpose: This function extracts an item from the list.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns a deleted list members.
*
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::Extract(T find)
{
	Node<T> * trail = m_head;
	if (m_head == nullptr) // case for empty list
	{
		throw Exception("Exception: No node could be found because the list is empty!");
	}
	else if (m_head->m_data == find) // head is found
	{
		trail = m_head;
		m_head = m_head->m_next;
		delete trail;
	}
	else
	{
		Node<T> * traverse = m_head;
		while (traverse != nullptr && traverse->m_data != find) // traverse through the list
		{
			trail = traverse;
			traverse = traverse->m_next;
		}
		if (traverse == nullptr) //Case to see if nothing was found
		{
			throw Exception("Exception: List item to delete was not found");
		}
		else if (traverse->m_next == nullptr) // Case for last node being target
		{
			trail->m_next = nullptr;
			m_tail = trail;
			delete traverse;
		}
		else // case for everywhere in the middle
		{
			trail->m_next = traverse->m_next;
			traverse->m_next->m_previous = trail;
			delete traverse;
		}
	}
}

/**********************************************************************
* Purpose: This function is an op= that takes a LL by reference.
*
* Entry: This function takes a LL by reference.
*
* Exit: This function returns a copied LL.
*
************************************************************************/
template <typename T>
DoubleLinkedList<T> & DoubleLinkedList<T>::operator=(const DoubleLinkedList<T> & rhs)
{
	if (this != &rhs) // check for self-assignment
	{
		Purge(); // delete lhs
		Node<T> * traverse = rhs.m_head;
		while (traverse != nullptr)
		{
			Append(traverse->m_data); // append the item to the end of the list
			traverse = traverse->m_next; // increment
		}
	}
	return *this;
}

/**********************************************************************
* Purpose: This function Finds the passed data in the LL.
*
* Entry: This function takes data to look for.
*
* Exit: This function returns the location of the node.
*
************************************************************************/
template <typename T>
Node<T> * DoubleLinkedList<T>::Find(T data)
{
	Node<T> * return_node = nullptr;
	if (m_head == nullptr) // check if the list is empty
	{
		throw Exception("Exception: No node could be found because the list is empty!");
	}
	else // case for when there is stuff in the list
	{
		Node<T> * traverse = m_head;
		while (traverse != nullptr) // while not at the end of the list
		{
			if (traverse->m_data == data) // check to see if thats what you want
			{
				return_node = traverse; // set the return value to the found item in the list
				traverse = traverse->m_next; // increment
			}
			else // increment to the next item in the list
			{
				traverse = traverse->m_next;
			}
		}
	}
	return return_node; // either return nullptr or the found node
}
/**********************************************************************
* Purpose: This function inserts an item after the second arg.
*
* Entry: This function takes two data segments.
*
* Exit: This function returns an updated LL.
*
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::InsertAfter(T insert, T place_after)
{
	if (m_head == nullptr) // if the list is empty
	{
		throw Exception("Exception: Can't insert anything in a blank list");
	}
	else
	{
		Node<T> * found = nullptr;
		found = Find(place_after); // see if that item is in the list
		if (found == nullptr) // case for not in the list
		{
			throw Exception("Exception: Passed argument was not found in list");
		}
		else // case for whem it is in the list
		{
			if (found->m_next == nullptr) // case for tail
			{
				Append(insert);
			}
			else
			{
				Node<T> * insert_after = new Node<T>(insert);

				insert_after->m_next = found->m_next;
				insert_after->m_previous = found;
				found->m_next = insert_after;
				insert_after->m_next->m_previous = insert_after;
			}
		}
	}
}
/**********************************************************************
* Purpose: This function inserts an item before the second arg.
*
* Entry: This function takes two data segments.
*
* Exit: This function returns an updated LL.
*
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::InsertBefore(T insert, T place_before)
{
	if (m_head == nullptr) // if the list is empty
	{
		throw Exception("Exception: Can't insert anything in a blank list");
	}
	else
	{
		Node<T> * found = nullptr;
		found = Find(place_before);
		if (found == nullptr) // case for bad passed data
		{
			throw Exception("Exception: Passed argument was not found in list");
		}
		else
		{
			if (found->m_previous == nullptr) // case for tail
			{
				Prepend(insert);
			}
			else // middle case
			{
				Node<T> * insert_before = new Node<T>(insert);
				insert_before->m_next = found;
				insert_before->m_previous = found->m_previous;

				found->m_previous = insert_before;
				insert_before->m_previous->m_next = insert_before;
			}
		}
	}

}
/**********************************************************************
* Purpose: This function prints the LL forwards.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not return anything.
*
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::PrintForwards()
{
	Node<T> * traverse = m_head;
	while (traverse)
	{
		std::cout << traverse->m_data << ' ';
		traverse = traverse->m_next;
	}
}
/**********************************************************************
* Purpose: This function prints the LL backwards.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not return anything.
*
************************************************************************/
template <typename T>
void DoubleLinkedList<T>::PrintBackwards()
{
	Node<T> * traverse = m_tail;
	while (traverse)
	{
		std::cout << traverse->m_data << std::endl;
		traverse = traverse->m_previous;
	}
}
#endif