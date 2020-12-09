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
	if (heapsize == maxsize)
	{
		heap = (int*)realloc(heap, (2 * maxsize + 1) * sizeof(int));//Increase the size of the array.
		maxsize = (2 * maxsize + 1);
	}
	int parrent = (heapsize - 1) / 2;
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
Binaryheap::Stack::Stack()
{
	reset_stack();
	size = 0;
}

Binaryheap::Stack::~Stack()
{
	while (empty())
	{
		pop();
	}
}

void Binaryheap::Stack::reset_stack()
{
	head = nullptr;
	tail = nullptr;
}

void Binaryheap::Stack::push(int Newelement)
{
	if (size == 0)//We add the new element first.
	{
		head = new Element(Newelement);
		tail = head;
	}
	else//We add the new element last.
	{
		Element* current = new Element(Newelement);
		tail->next = current;
		current->prev = tail;
		tail = current;
	}
	size++;
}

void Binaryheap::Stack::pop()
{
	if (size == 0)return;//Exit the function.
	if (size == 1)//We remove the first element and reset the list.
	{
		delete head;
		reset_stack();
	}
	else
	{
		Element* current = tail->prev;
		current->next = nullptr;
		tail->prev = nullptr;
		delete tail;
		tail = current;
	}
	size--;
}

int Binaryheap::Stack::top()
{
	return tail->data;
}

bool Binaryheap::Stack::empty()
{
	if (size == NULL)
		return false;
	else
		return true;
}
int Binaryheap::dft_iterator::next()
{
	int lastid = stack.top();
	stack.pop();
	if ((2 * lastid + 2) < heapsize)
	{
		stack.push(2 * lastid + 2);
	}
	if ((2 * lastid + 1) < heapsize)
	{
		stack.push(2 * lastid + 1);
	}
	return current[lastid];
}

bool Binaryheap::dft_iterator::has_next()
{
	return (stack.empty());
}

int Binaryheap::bft_iterator::next()
{
	int returned= queue.front();
	if ((2 * returned + 1) < heapsize)
	{
		queue.push(2 * returned + 1);
	}
	if ((2 * returned + 2) < heapsize)
	{
		queue.push(2 * returned + 2);
	}
	queue.pop();
	return current[returned];
}

bool Binaryheap::bft_iterator::has_next()
{
	return (queue.empty());
}

Binaryheap::Queue::Queue()
{
	reset_queue();
	size = 0;
}

Binaryheap::Queue::~Queue()
{
	while (empty())
	{
		pop();
	}
}

void Binaryheap::Queue::reset_queue()
{
	head = nullptr;
	tail = nullptr;
}

void Binaryheap::Queue::push(int Newelement)
{
	if (size == 0)//We add the new element first.
	{
		head = new Element(Newelement);
		tail = head;
	}
	else//We add the new element last.
	{
		Element* current = new Element(Newelement);
		tail->next = current;
		tail = current;
	}
	size++;
}

void Binaryheap::Queue::pop()
{
	if (size == 0) return;//Exit the function.
	if (size == 1)//We remove the first element and reset the list.
	{
		delete head;
		reset_queue();
	}
	else//We remove the first element
	{
		Element* current = head->next;
		head->next = nullptr;
		delete head;
		head = current;
	}
	size--;
}

int Binaryheap::Queue::front()
{
	return head->data;
}

bool Binaryheap::Queue::empty()
{
	if (size == NULL)
		return false;
	else
		return true;
}
