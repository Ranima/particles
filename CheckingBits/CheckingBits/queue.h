#pragma once

class Queue
{
	const static int len = 150;
	int first = 0;
	int last = 0;
	bool isActive = false;

	void getLast();
	void getFirst();

	struct data {
		int value = 0;
		bool isFull = false;
	};

	data Qdata[len];

public:


	int pop();

	int push();
};