#include "HeaderLab3.h"
#include<iostream>
using namespace std;
int main()
{
	Binaryheap tree1;
	tree1.insert(1);
	tree1.insert(2);
	tree1.insert(3);
	tree1.insert(6);
	tree1.insert(7);
	tree1.insert(4);
	tree1.insert(9);
	Iterator* iter=tree1.create_bft_iterator();
	while (iter->has_next())
		cout << iter->next()<<" ";
	cout << endl;
	Iterator* iter2 = tree1.create_dft_iterator();
	while (iter2->has_next())
		cout << iter2->next() << " ";
	return 0;
}