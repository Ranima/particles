#pragma once



class tree {
private:
	struct node {
		int val;
		node *left, *right;
	};
	node *root;

public:
	bool IsEmpty();
	void insert(int value);
	bool find(int value);
};