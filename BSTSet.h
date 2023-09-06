#ifndef BSTSET_H_
#define BSTSET_H_

#include "TNode.h"
#include <vector>

class BSTSet
{
private:
	// must contain only one private field
	TNode* root = 0;
	int BSTSize = 0;


public:
	// required constructors/destructor
	BSTSet();
	BSTSet(const std::vector<int>& input);
	~BSTSet();
	// required methods
	bool isIn(int v);
	void add(int v);
	bool remove(int v);
	void Union(const BSTSet& s);
	void intersection(const BSTSet& s);
	void difference(const BSTSet& s);
	int size();
	int height();
	void printNonRec(); // create and use class MyStack

	// provided recursive print method
	void printBSTSet();

	// Used for testing
	TNode* getRoot()
	{
		return root;
	}

private:
	bool removeHelperFunction(int v, TNode*& variable);
	void UnionHelperFunction(TNode* y);
	void intersectionHelperFunction(TNode* second, TNode* first);
	void differenceHelperFunction(TNode* Root2, TNode* s);
	int  heightHelperFunction(TNode* root);
	bool IsInV2(int x, TNode* n);
	void BSTSetDestructor(TNode*& x);
	// provided helper methods
	void printBSTSet(TNode* t);
};

#endif /* BSTSET_H_ */
