#pragma once

class stack
{
private:
	const static int len = 150;

	int next = 0;

	int Sdata[len];
public:

	int pop();

	void push(int value);

	int peek();
};