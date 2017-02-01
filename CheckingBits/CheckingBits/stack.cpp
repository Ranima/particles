#include "stack.h"

int Stack::pop()
{
	--next;
	return Sdata[next + 1];
}

void Stack::push(int value)
{
	Sdata[next] = value;
	++next;
}

int Stack::peek()
{
	return Sdata[next - 1];
}
