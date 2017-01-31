#include "stack.h"

int stack::pop()
{
	--next;
	return Sdata[next + 1];
}

void stack::push(int value)
{
	Sdata[next] = value;
	++next;
}

int stack::peek()
{
	return Sdata[next - 1];
}
