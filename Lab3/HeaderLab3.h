#pragma once
#include "Iterator.h"
class Binaryheap
{
private:
	const int maxsize = 100;
	int* heap;
	int heapsize;

public:
	Binaryheap();
	bool contains(int); // ����� �������� � ������ �� �����
	void insert(int); // ���������� �������� � ������ �� �����. ������ �������� �� O(logN)
	void remove(int); // �������� �������� ������ �� �����
	Iterator *create_dft_iterator(); // �������� ���������, ������������ ���� �� ������� ������ � ������� (depth-first traverse)
	Iterator *create_bft_iterator(); // �������� ���������, ������������ ������ ������ � ������ (breadth-first traverse)
	void Heapify(int);
	class dft_iterator : public Iterator
	{
	public:
		dft_iterator(int* start, int max)
		{
			current = start;
			stack = new int[max];
			stack[0] =0;
			last = 0;
			heapsize = max;
		};
		~dft_iterator()
		{
			delete current;
			delete stack;
		};
		int next() override;
		bool has_next() override;
	private:
		int* stack;
		int* current;
		int last;
		int heapsize;
	};
	class bft_iterator : public Iterator
	{
	public:
		bft_iterator(int* start, int max)
		{
			current = start;
			queue = new int[max];
			queue[0] = 0;
			end = 0;
			heapsize = max;
		};
		~bft_iterator()
		{
			delete queue;
			delete current;
		};
		int next() override;
		bool has_next() override;
	private:
		int* current;
		int* queue;
		int end;
		int heapsize;
	};
};