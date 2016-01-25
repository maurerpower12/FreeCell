#include "PlayArea.h"

/**********************************************************************
* Purpose: This function is a constructor that builds the area.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
PlayArea::PlayArea() : m_stack(8)
{}
/**********************************************************************
* Purpose: This function is a copy constructor that builds a play area.
*
* Entry: This function takes a play area by reference.
*
* Exit: This function does not have a return.
*
************************************************************************/
PlayArea::PlayArea(const PlayArea & copy)
{
	*this = copy;
}
/**********************************************************************
* Purpose: This function copies on play area to another one.
*
* Entry: This function takes a play area by reference.
*
* Exit: This function returns a copied object.
*
************************************************************************/
PlayArea & PlayArea::operator=(const PlayArea & rhs)
{
	if (this != &rhs)
	{
		m_stack = rhs.m_stack;
	}
	return *this;
}
/**********************************************************************
* Purpose: This function deallocates memory.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return.
*
************************************************************************/
PlayArea::~PlayArea()
{}


/**********************************************************************
* Purpose: This function allows for access to the play area stack.
*
* Entry: This function does not take any arguments.
*
* Exit: This function returns a stack.
*
************************************************************************/
Array<LLStack<Card *>> & PlayArea::getStack()
{
	return m_stack;
}