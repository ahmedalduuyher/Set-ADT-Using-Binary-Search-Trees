#ifndef LLNODE_H_
#define LLNODE_H_

#include "TNode.h"
#include <vector>
template <typename E>
class LLNode
{
public:
	E data;
	LLNode<E>* next;
	LLNode(E e, LLNode<E>* n)
	{
		data = e;
		next = n;
	}
};

#endif /* LLNODE_H_ */
