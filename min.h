#ifndef minheap_h
#define minheap_h
#include<iostream>
#include <unistd.h>
#include<string>
#include "table.h"
using namespace std;

class MinHeap {
private:
	Table t;
    string* wordArray;
	int* heapArray;
    const static int CAPACITY = 16;
   // string heapArray[2][CAPACITY];
	int size;	
	void heapify(int index);

public:
	MinHeap();
	//int removeMin() throw (HeapEmptyException);
	void insert(string e);
	void replaceMin(string e);
	int getSize() { return size; }
	void printHeap();
    void printHashTable();
};

#endif