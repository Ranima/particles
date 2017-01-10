#pragma once

class tree 
{
private:
	struct node
	{
	public:
		int val;
		node *left, *right;
		node(int v) : val(v), left(nullptr), 
			right(nullptr) {}
	};
	node *root;

public:
	tree() : root(nullptr) {};
	bool IsEmpty();
	bool insert(int value);
	bool find(int value);
	bool remove(int value);
};
