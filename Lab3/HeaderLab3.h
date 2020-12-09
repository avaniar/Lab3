#pragma once
#include "Iterator.h"
class Binaryheap
{
private:
	int maxsize=1;
	int* heap;
	int heapsize;

public:
	Binaryheap();
	bool contains(int); // search for an element in the tree by key
	void insert(int); // adding an element to the tree by key
	void remove(int); // deleting a tree element by key
	Iterator *create_dft_iterator(); // creating an iterator that implements one of the depth - first traversal methods
	Iterator *create_bft_iterator(); // creating an iterator that implements breadth - first traversal methods
	void Heapify(int);
	class Stack
	{
	private:
		class Element
		{
		public:
			Element(int data, Element* next = nullptr, Element* prev = nullptr) {
				this->data = data;
				this->next = next;
				this->prev = prev;
			};
			~Element() {};
			int data;
			Element* next;
			Element* prev;
		};
		Element* head;
		Element* tail;
		size_t size;
	public:
		Stack();
		~Stack();
		void reset_stack();
		void push(int Newelement); // добавление в конец списка
		void pop(); // удаление последнего элемент
		int top();
		bool empty();
	};
	class dft_iterator : public Iterator
	{
	public:
		dft_iterator(int* start, int max)
		{
			current = start;
			heapsize = max;
			stack.push(0);
		};
		~dft_iterator()
		{
			delete current;
		};
		int next() override;
		bool has_next() override;
	private:
		Stack stack;
		int* current;
		int heapsize;
	};
	class Queue
	{
	private:
		class Element
		{
		public:
			Element(int data, Element* next = nullptr) {
				this->data = data;
				this->next = next;
			};
			~Element() {};
			int data;
			Element* next;
		};
		Element* head;
		Element* tail;
		size_t size;
	public:
		Queue();
		~Queue();
		void reset_queue();
		void push(int Newelement); // добавление в конец списка
		void pop(); // удаление последнего элемент
		int front();
		bool empty();
	};
	class bft_iterator : public Iterator
	{
	public:
		bft_iterator(int* start, int max)
		{
			queue.push(0);
			current = start;
			heapsize = max;
		};
		~bft_iterator()
		{
			delete current;
		};
		int next() override;
		bool has_next() override;
	private:
		Queue queue;
		int* current;
		int heapsize;
	};
};