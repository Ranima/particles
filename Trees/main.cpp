#include <cassert>
#include "Trees.h"

void main()
{
	tree testTree;

	assert(testTree.IsEmpty() == true);

	testTree.insert(5);
	testTree.insert(7);
	testTree.insert(4);
	testTree.insert(6);

}