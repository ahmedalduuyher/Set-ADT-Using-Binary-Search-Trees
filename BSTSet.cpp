#include "BSTSet.h"
#include <iostream>
#include <vector>
#include "MyStack.h"
#include "LLNode.h"
#include "MyStack.cpp"
using namespace std;

BSTSet::BSTSet()
{
	root = NULL;
	BSTSize = 0;
}
//Time complexity of theta(1), space complexity of theta(1) (Just an AR activation)

BSTSet::BSTSet(const std::vector<int>& input)
{
	// TODO, change following code after completing this function
	int x = input.size();
	if (x == 0)
	{
		root = NULL;
		BSTSize = 0;
		return;
	}
	root = new TNode(input[0], NULL, NULL);
	BSTSize++;
	for (int i = 1; i < x; i++)
	{
		TNode* temp = root;
		while (temp->element != input[i])
		{
			if (input[i] < temp->element && temp->left != NULL)
			{
				temp = temp->left;
			}
			else if (input[i] > temp->element && temp->right != NULL)
			{
				temp = temp->right;
			}
			else if (input[i] < temp->element && temp->left == NULL)
			{
				temp->left = new TNode(input[i], NULL, NULL);
				BSTSize++;
			}
			else
			{
				temp->right = new TNode(input[i], NULL, NULL);
				BSTSize++;
			}
		}
	}
}//Time complexity of theta(nlog(n)), Space complexity of theta(n)

BSTSet::~BSTSet()
{
	BSTSetDestructor(root);
	BSTSize = 0;
	root = NULL;
}//Time complexity of theta(n), space complexity of theta(n) (n activation records)
void BSTSet::BSTSetDestructor(TNode*& x)
{
	if (x == NULL)
	{
		return;
	}
	BSTSetDestructor(x->left);
	BSTSetDestructor(x->right);
	delete x;
}//Time complexity of theta(n), space complexity of theta(n) (n activation records)
bool BSTSet::IsInV2(int v, TNode* n)
{
	if (n == NULL)
	{
		return false;
	}
	TNode* temp = n;
	while (true)
	{
		if (v > temp->element && temp->right != NULL)
		{
			temp = temp->right;
			continue;
		}
		else if (v < temp->element && temp->left != NULL)
		{
			temp = temp->left;
			continue;
		}
		else if (v > temp->element && temp->right == NULL)
		{
			return false;
		}
		else if (v < temp->element && temp->left == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}//Time complexity of theta(log(n)), space complexity of (1)

bool BSTSet::isIn(int v)
{
	if (root == NULL)
	{
		return false;
	}
	TNode* temp = root;
	while (true)
	{
		if (v > temp->element && temp->right != NULL)
		{
			temp = temp->right;
			continue;
		}
		else if (v < temp->element && temp->left != NULL)
		{
			temp = temp->left;
			continue;
		}
		else if (v > temp->element && temp->right == NULL)
		{
			return false;
		}
		else if (v < temp->element && temp->left == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}//Time complexity of theta(log(n)), space complexity of (1)

void BSTSet::add(int v)
{
	if (root == NULL)
	{
		root = new TNode(v, NULL, NULL);
		BSTSize++;
		return;
	}
	TNode* temp = root;
	while (v != temp->element)
	{
		if (v < temp->element && temp->left != NULL)
		{
			temp = temp->left;
		}
		else if (v > temp->element && temp->right != NULL)
		{
			temp = temp->right;
		}
		else if (v < temp->element && temp->left == NULL)
		{
			temp->left = new TNode(v, NULL, NULL);
			BSTSize++;
		}
		else
		{
			temp->right = new TNode(v, NULL, NULL);
			BSTSize++;
		}
	}
	return;
}//Time complexity of theta(log(n)), space complexity of(1)



bool BSTSet::removeHelperFunction(int v, TNode*& variable)
{
	if (variable == NULL)
	{
		return false;
	}
	else if (v < variable->element)
	{
		return removeHelperFunction(v, variable->left);
	}
	else if (v > variable->element)
	{
		return removeHelperFunction(v, variable->right);
	}
	else if (variable->left != NULL && variable->right != NULL)
	{
		TNode* temp = variable->right;
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		variable->element = temp->element;
		removeHelperFunction(variable->element, variable->right);
		BSTSize--;
		return true;
	}
	else if (root->left == NULL && root->right == NULL)
	{
		delete root;
		root = NULL;
		BSTSize--;
		return true;
	}
	else
	{
		TNode* OldNode = variable;
		if (variable->left != NULL)
		{
			variable = variable->left;
			delete OldNode;
			BSTSize--;
			return true;
		}
		else
		{
			variable = variable->right;
			delete OldNode;
			BSTSize--;
			return true;
		}
	}
}//Time complexity of log(n), space complexity of log(n) (log(n) activation records)
bool BSTSet::remove(int v)
{
	if (root == NULL)
	{
		return false;
	}
	else
	{
		bool x = removeHelperFunction(v, root);
		return x;
	}

}//Time complexity of theta(log(n)), space complexity of log(n) (log(n) activation records)

void BSTSet::UnionHelperFunction(TNode* y)
{
	if (y == NULL)
	{
		return;
	}

	add(y->element);
	UnionHelperFunction(y->left);
	UnionHelperFunction(y->right);
}//Time complexity of theta(n*log(n)) and space complexity of log(n)
void BSTSet::Union(const BSTSet& s)
{
	UnionHelperFunction(s.root);
}//Time complexity of theta(n*log(n)) and space complexity of log(n)
void BSTSet::intersectionHelperFunction(TNode* Root2, TNode* s)
{
	if (Root2 == NULL) {
		return;
	}

	intersectionHelperFunction(Root2->left, s);
	intersectionHelperFunction(Root2->right, s);
	if (!IsInV2(Root2->element, s))
	{
		remove(Root2->element);
	}
}//Time complexity of theta(n*(log(n)) and space complexity of theta(log(n))

void BSTSet::intersection(const BSTSet& s)
{
	if (s.root == NULL)
	{
		this->~BSTSet();
		return;
	}
	else
	{
		intersectionHelperFunction(root, s.root);
	}
}//Time complexity of theta(n*(log(n)) and space complexity of theta(log(n))
void BSTSet::differenceHelperFunction(TNode* Root2, TNode* s)
{
	if (Root2 == NULL) {
		return;
	}
	differenceHelperFunction(Root2->left, s);
	differenceHelperFunction(Root2->right, s);
	if (IsInV2(Root2->element, s))
	{
		remove(Root2->element);
	}
}//Time complexity of theta(n*log(n)), space complexity of theta(log(n))
void BSTSet::difference(const BSTSet& s)
{
	if (s.root == NULL)
	{
		return;
	}
	else
	{
		differenceHelperFunction(root, s.root);
	}
}//Time complexity of theta(n*log(n)), space complexity of theta(log(n))

int BSTSet::size()
{
	// TODO
	return BSTSize; //change this after completing this function
}//Time complexity of 1 and space complexity of 1

int BSTSet::heightHelperFunction(TNode* Root1)
{
	if (Root1 == NULL) {
		return -1;
	}
	int lh = heightHelperFunction(Root1->left);
	int rh = heightHelperFunction(Root1->right);
	if (lh > rh) {
		return lh + 1;
	}
	else
	{
		return rh + 1;
	}
}//Time complexity of theta(n), space complexity of theta(log(n)), worst case theta(n)
int BSTSet::height()
{
	if (root == NULL)
	{
		return -1;
	}
	return heightHelperFunction(root);
}//Time complexity of theta(n), space complexity of theta(log(n)), worst case theta(n)

// create and use class MyStack
void BSTSet::printNonRec()
{
	if (root == NULL)
	{
		cout << "";
		return;
	}
	TNode* temp = root;
	MyStack<TNode*> stack;
	for (int i = 0; i < BSTSize; i++)
	{
		while (temp != NULL)
		{
			stack.push(temp);
			temp = temp->left;
		}
		if (!stack.isEmpty())
		{
			TNode* data = stack.pop();
			temp = data->right;
			cout << data->element << ",";
		}
	}
}//time complexity of theta(n), space complexity of theta(n)

// Do not modify following provided methods

void BSTSet::printBSTSet()
{
	if (root == NULL)
		std::cout << "";
	else {
		printBSTSet(root);
	}
}

void BSTSet::printBSTSet(TNode* t)
{
	if (t != NULL) {
		printBSTSet(t->left);
		std::cout << t->element << ",";
		printBSTSet(t->right);
	}
}