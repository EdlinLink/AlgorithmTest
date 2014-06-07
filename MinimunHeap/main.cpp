#include "MinimunHeap.h"

int main(){                                                                                                                            
	Heap h(100);
	h.Add(13);
	h.Add(21);
	h.Add(16);
	h.Add(24);
	h.Add(31);
	h.Add(19);
	h.Add(68);
	h.Add(65);
	h.Add(26);
	h.Add(32);
	h.Print();
	h.Add(14);
	h.Print();
	
	h.DeleteMin();
	h.Print();

	return 0;
}
