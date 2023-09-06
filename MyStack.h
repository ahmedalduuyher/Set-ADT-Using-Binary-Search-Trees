#ifndef MYSTACK_H_
#define MYSTACK_H_

#include "TNode.h"
#include "LLNode.h"
#include <vector>
template <typename E>
class MyStack
{
private:
	LLNode<E>* head;
public:
	MyStack()
	{
		head = nullptr;
	}
	~MyStack();
	bool isEmpty();
	E top();
	void push(const E& e);
	E pop();
};

#endif /* MYSTACK_H_ */
