/************************************************************************
* Class: Node
* Updates:
*		1. Now Include a get previous function.
*
* Purpose: This class's function is to house the node that
*		is used as part of a linked list.
*
* Manager functions:
* 		Node()
*			Default CTOR. sets everything to nullptr.
*   	Node(T data)
*			Sets m_data to the passed data. Everything else to nullptr.
*		~Node()
*			Resets the Node. No deletes
*		Node<T> & operator=(const Node<T> & rhs)
*			Transferes content of one node to another.
*
*
* Methods:
*		T getData() const
*			Return the data of the passed node.
*   	void setData(T data)
*			Sets the data of the passed Node.
*   	void setPrevious(Node<T> * previous)
*			Sets the previous of the past Node.
*
*************************************************************************/

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
	// grant friendship to LL to stop recursive calls
	template <typename T>
	friend class DoubleLinkedList;

	Node();
	Node(T data);
	Node<T> * getNext();
	Node<T> * getPrevious();
	void setNext(Node<T> * forward);
	T & getData();
	void setData(T data);
	void setPrevious(Node<T> * previous);
	Node<T> & operator=(const Node<T> & rhs);
	~Node();

private:
	T m_data;
	Node<T> * m_next;
	Node<T> * m_previous;
};


/**********************************************************************
* Purpose: This function is a constructor that builds the inital Node.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
template <typename T>
Node<T>::Node() : m_data(T()), m_next(nullptr), m_previous(nullptr)
{

}
/**********************************************************************
* Purpose: This function is a constructor that builds the inital Node
*		with the data that is passed in.
*
* Entry: This function takes data to fill the node with.
*
* Exit: This function does not have a return.
*
************************************************************************/
template <typename T>
Node<T>::Node(T data) : m_data(data), m_next(nullptr), m_previous(nullptr)
{

}

/**********************************************************************
* Purpose: This function sets the next node.
*
* Entry: This function takes a node by pointer.
*
* Exit: This function does not have a return.
*
************************************************************************/
template <typename T>
void Node<T>::setNext(Node<T> * forward)
{
	this->m_next = *forward;
}

/**********************************************************************
* Purpose: This function gets the data from the node.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns the value from the node.
*
************************************************************************/
template <typename T>
T & Node<T>::getData()
{
	return m_data;
}

/**********************************************************************
* Purpose: This function sets the data.
*
* Entry: This function takes T data.
*
* Exit: This function does not have a return.
*
************************************************************************/
template <typename T>
void Node<T>::setData(T data)
{
	m_data = data;
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
Node<T>::~Node()
{
	m_data = T();		// reset to default value for whatever type
	m_next = nullptr;
	m_previous = nullptr;
}
/**********************************************************************
* Purpose: This function returns the next node.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns the next node.
*
************************************************************************/
template <typename T>
Node<T> * Node<T>::getNext()
{
	return m_next;
}
/**********************************************************************
* Purpose: This function gets the previous from the node.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns the previous from the node.
*
************************************************************************/
template <typename T>
Node<T> * Node<T>::getPrevious()
{
	return m_previous;
}
/**********************************************************************
* Purpose: This function sets the previous node.
*
* Entry: This function takes in a node pointer.
*
* Exit: This function does not have a return.
*
************************************************************************/
template <typename T>
void Node<T>::setPrevious(Node<T> * previous)
{
	m_previous = previous;
}
/**********************************************************************
* Purpose: This function is an op=. It returns this by pointer.
*
* Entry: This function takes a node by reference.
*
* Exit: This function a node by pointer.
*
************************************************************************/
template <typename T>
Node<T> & Node<T>::operator=(const Node<T> & rhs)
{
	if (this != &rhs) // check for self-assignment
	{
		m_data = rhs.m_data;
		m_next = rhs.m_next;
		m_previous = rhs.m_previous;
	}
	return *this;
}
#endif