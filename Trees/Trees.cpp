#include "Trees.h"
#include <iostream>

bool tree::IsEmpty()
{
	return root == nullptr;
}

bool tree::insert(int value)
{
	node *temp = root;
	if (root == nullptr)
	{
		root = new node(value);
		return true;
	}
	
	while (true)
	{
		if (value == temp->val)
			return false;
		if (value < temp->val)
		{
			if (temp->left == nullptr)
			{
				temp->left = new node(value);
				return true;
			}
			temp = temp->left;
		}
		else
		{
			if (temp->right == nullptr)
			{
				temp->right = new node(value);
				return true;
			}
			temp = temp->right;
		}
	}
}

bool tree::find(int value)
{
	return false;
}

bool tree::remove(int value)
{
	return false;
}
