#include "BSTSet.h"
#include "MyStack.h"
#include <iostream>
#include <vector>
using namespace std;

template <typename E>
bool MyStack<E>::isEmpty()
{
	return (head == NULL);
}


template <typename E>
void MyStack<E>::push(const E& e)
{
	head = new LLNode<E>(e, head);
}


template <typename E>
E MyStack<E>::pop()
{
	if (isEmpty())
	{
		throw std::underflow_error("Stack Underflow");
	}
	else
	{
		LLNode<E>* oldHead = head;

		E tempE = head->data;
		head = head->next;

		delete oldHead;
		return tempE;
	}
}


template <typename E>
E MyStack<E>::top()
{
	if (isEmpty())
	{
		throw std::underflow_error("Stack Underflow");
	}
	else
	{
		return head->data;
	}
}


template <typename E>
MyStack<E>::~MyStack()
{
	while (head)
	{
		LLNode<E>* temp = head->next;
		delete head;
		head = temp;
	}
}