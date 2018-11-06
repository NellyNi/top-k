// min.cpp
#include <unistd.h>
#include <iostream>
#include <string>
#include "min.h"
using namespace std;

class HeapEmptyException {};

MinHeap::MinHeap() {
	size = 0;
	wordArray = new string[CAPACITY];
	heapArray = new int[CAPACITY];
}

void MinHeap::heapify(int index) {
	int leftChild = 2 * index;
	int rightChild = 2 * index + 1;
	int smallestIndex = index;
 	
	if (leftChild <= size && 
    heapArray[leftChild] < heapArray[smallestIndex]) {
		smallestIndex = leftChild;
	}
	if (rightChild <= size &&
    heapArray[rightChild] < heapArray[smallestIndex]) {
		smallestIndex = rightChild;
	}
	if (smallestIndex != index) {
		string temp0 = wordArray[index];
		int temp1 = heapArray[index];
		t.update_data(wordArray[smallestIndex],index);
		t.update_data(wordArray[index],smallestIndex);
		wordArray[index] = wordArray[smallestIndex];
		heapArray[index] = heapArray[smallestIndex];
		wordArray[smallestIndex] = temp0;
		heapArray[smallestIndex] = temp1;
		heapify(smallestIndex);
	}
}

void MinHeap::insert(string e) {
	
	if (t.search(e)!=-1){ //in the hash
		int p=t.search(e);
		heapArray[p]=heapArray[p]+1;
		heapify(p);
		//update hash
		//t.update_data(e,new_data);
		//cout<<"1"<<endl;

	}else{
		if (size<(CAPACITY-1)){
			size++;
			wordArray[size] = e;
			heapArray[size] = 1;
			t.put(e,size);
			string temp0; 
			int temp1;
			int index = size;
			
			while (index > 1 && heapArray[index / 2] > heapArray[index]) {
			// swap parent and current node
				temp0 = wordArray[index];
				temp1 = heapArray[index];
				t.update_data(wordArray[index/2],index);
				t.update_data(wordArray[index],index/2);
				wordArray[index] = wordArray[index / 2];
				heapArray[index] = heapArray[index / 2];
				wordArray[index / 2] = temp0;
				heapArray[index / 2] = temp1;
				index = index / 2;
			}
			//update hash
			
			//cout<<"2"<<endl;
		} else{
			replaceMin(e);
			//cout<<"3"<<endl;
		}
		
		
	}
	
}

void MinHeap::replaceMin(string e){
	t.remove(wordArray[1]);
	wordArray[1]=e;
	t.put(e,1);
}

void MinHeap::printHeap() {
	cout<<"Min Heap"<<endl;
	for (int i = 1; i <= size; i++) {
		cout << "index: "<<i<<" word: " << wordArray[i] << " frequency: " << heapArray[i] << endl;
	}
}

void MinHeap::printHashTable(){
	cout<<endl<<"Hash Table"<<endl;
	cout<<t;
}

