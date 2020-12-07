#include "HeaderLab3.h"
#include<iostream>
using namespace std;
Binaryheap::Binaryheap()
{
	heap = new int[maxsize];
	heapsize = 0;
}
bool Binaryheap::contains(int key)
{
	for (int i = 0;i < heapsize;i++)
	{
		if (heap[i] == key)//We find the key.
			return heap[i];
	}
	return false;
}
void Binaryheap::Heapify(int i)
{
	int left, right;
	left = 2 * i + 1;//Lef tand right sons.
	right = 2 * i + 2;
	if ((heap[left] < heap[i])&&(left<=heapsize))
	{
		int help = heap[left];//Replacement of elements.
		heap[left] = heap[i];
		heap[i] = help;
		Heapify((i-1)/2);
	}
	if ((heap[right] < heap[i]) && (right <=heapsize))
	{
		int help = heap[right];//Replacement of elements.
		heap[right] = heap[i];
		heap[i] = help;
		Heapify((i-1)/2);
	}
		
}
void Binaryheap::insert(int newelement)
{
	int parrent=(heapsize-1)/2;
	heap[heapsize] = newelement;//Added a new element to the end.
	Heapify(parrent);
	heapsize++;
}

void Binaryheap::remove(int key)
{
	if (key < heapsize)
	{
		int help = heap[key];
		heap[key] = heap[heapsize - 1];//Replacement of elements.
		heap[heapsize - 1] = help;
		heap[heapsize - 1] = NULL;//deleting the last item.
		heapsize--;
		Heapify(key);
	}
}

Iterator* Binaryheap::create_dft_iterator()
{
	return new dft_iterator(heap,heapsize);
}

Iterator* Binaryheap::create_bft_iterator()
{
	return new bft_iterator(heap, heapsize);
}

int Binaryheap::dft_iterator::next()
{
	int lastid = stack[last];
	last--;
	if ((2 * lastid + 2) < heapsize)
	{
		stack[last + 1] = 2 * lastid + 2;
		last++;
	}
	if ((2 * lastid + 1) < heapsize)
	{
		stack[last + 1] = 2 * lastid + 1;
		last++;
	}
	return current[lastid];
}

bool Binaryheap::dft_iterator::has_next()
{
	return (last >= 0);
}

int Binaryheap::bft_iterator::next()
{
	int returned= current[queue[0]];
	if ((2 * queue[0] + 1) < heapsize)
	{
		queue[end + 1] =2 * queue[0] + 1;
		end++;
	}
	if ((2 * queue[0] + 2) < heapsize)
	{
		queue[end + 1] = 2 * queue[0] + 2;
		end++;
	}
	for (int i = 0;i < end;i++)
	{
		queue[i] = queue[i + 1];
	}
	end--;
	return returned;
}

bool Binaryheap::bft_iterator::has_next()
{
	return (end>=0);
}
