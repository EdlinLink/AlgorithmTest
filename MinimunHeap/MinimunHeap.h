/************************************************************************** 
 *  Title   : The Minimum Heap
 *  Author  : Edlin
 *  Date    : June 4, 2014
 **************************************************************************/

#ifndef MINIMUNHEAP_H
#define MINIMUNHEAP_H

#include <iostream>
#include <cmath>
using namespace std;

#define ElementType int

class Heap{
public:
	Heap(int size);
	~Heap();
	void Add(ElementType element);
	ElementType DeleteMin();
	void Print();

private:
	int Layer(int index);
	void Swap(ElementType& a, ElementType& b);

	ElementType* heap;
	int size;
	int count;
};

Heap::Heap(int size){
	heap = new ElementType[size+1];
	this->size = size;
	count = 0;
}

Heap::~Heap(){
	delete []heap;
}

void Heap::Swap(ElementType& a, ElementType& b){
	ElementType temp = a;
	a = b;
	b = temp;
}

void Heap::Add(ElementType element){
	count++;
	heap[count] = element;
	
	int current = count;
	int layer = Layer(current);
	while(--layer){
		int compare = pow(2.0,(layer-1)) + (current-pow(2.0,layer))/2;
		
		if(heap[compare] > heap[current]){
			Swap(heap[compare], heap[current]);
			current = compare;	
		}
	}
}

int Heap::Layer(int index){
	int layer = 0;
	while(index!=0){
		index/=2;
		layer++;
	}
	return layer;
}


ElementType Heap::DeleteMin(){
	//	If these is no element, then error;
	//	If these is only one element, just delete it;
	//	If these are multi element, move the last one to the top and adjust the heap.
	
	if(count==0){
		cerr << "[Fail] Heap is empty." << endl;
		return 0;
	}
	else if(count==1){
		count = 0;
		return heap[1];
	}
	else{
		ElementType min_element = heap[1];
		Swap(heap[1], heap[count]);
		count--;

		int current = 1;

		int bottom_layer = Layer(count);
		int layer = Layer(current);
		bool has_child1 = true;
		bool has_child2 = true;

		int child1_index = pow(2.0, layer) + (current-pow(2.0, layer-1)) * 2;
		int child2_index = child1_index + 1;
	
		if(child1_index > count)	
			has_child1 = false;
		if(child2_index > count)	
			has_child2 = false;

		while(has_child1 || has_child2){
			if(has_child1 && has_child2){
				if(heap[child1_index] < heap[child2_index]){
					if(heap[child1_index] < heap[current]){
						Swap(heap[current], heap[child1_index]);
						current = child1_index;
					}
					else
						break;
				}
				else{
					if(heap[child2_index] < heap[current]){
						Swap(heap[current], heap[child2_index]);
						current = child2_index;
					}
					else
						break;
				}
			}
			else if(has_child1 && !has_child2){
				if(heap[child1_index] < heap[current]){
					Swap(heap[current], heap[child1_index]);
					current = child1_index;
				}
				else
					break;
			}
			else{
				if(heap[child2_index] < heap[current]){
					Swap(heap[current], heap[child2_index]);
					current = child2_index;
				}
				else
					break;
			}

			layer = Layer(current);
			child1_index = pow(2.0, layer) + (current-pow(2.0, layer-1)) * 2;
			child2_index = child1_index + 1;

			if(child1_index > count)	
				has_child1 = false;
			if(child2_index > count)	
				has_child2 = false;
		}

		return min_element;
	}
}

void Heap::Print(){
	for(int i=1; i<count; i++){
		cout<<heap[i]<<" ";
	}
	cout<<heap[count]<<endl;
}

#endif
