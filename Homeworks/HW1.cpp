#include<iostream>
using namespace std;

class GrowArray {
private:
	int* p;
	uint32_t size; // the number of elements used
	uint32_t capacity; // the amount of memory
	void checkGrow() {
		
		if(size >= capacity) {
			capacity = capacity << 1;
			int* nums = new int [capacity];

			for(int i=0; i<(size-1); ++i){
				nums[i] = p[i];
			}
			p = nums;
		}
	}
public:

	GrowArray (uint32_t _size, uint32_t _capacity){
		p = new int [_capacity];
		capacity = _capacity;
		size = _size;
		

		
	}
	int* getValue()
   	{
       return p;
   	}

	uint32_t getCap() {
		return capacity;
	}

	uint32_t getSize() {
		return size;
	}


	void addEnd(int v) {
		checkGrow();
		p[size] = v;
		size++;
		
	}


	void addStart(int v) {
		checkGrow();

		int* nums = new int [capacity];
		nums[0] = v;

		for(int i = 0; i < size; i++){
			nums[(i+1)] = p[i];
		}

		p = nums;
		size++;


	}

	void display() {
		for (int i = 0; i < (size-1); i++)
		cout<<p[i]<<" ";
	}
	void removeStart() {
		int* nums = new int [capacity];
		for(int i = 1; i < (size - 1); i++){
			nums[i-1] = p[i];
		}
		
		p = nums;

		size--;
	}
	
	void removeEnd() {
		int* nums = new int [capacity];

		for(int i = 0; i < (size - 1); i++){
			nums[i] = p[i];
		}

		p = nums;

		size--;
	}

	void removeEvens() {
		int* nums = new int [capacity];
		int j = 0;
		int val = (size - 1);

		for (int i = 0; i < val; i++){
			if ((p[i]%2) != 0) {
				nums[j] = p[i];
				size--;
				j++;
			}
		}
		p = nums;
	}
};

int main() {
	GrowArray a(0,500); // empty list, with 500 elements


	for (int i = 0; i < 500; i++){
		a.addEnd(i);
	}
		 // really fast!
	
	

	for (int i = 0; i < 100000; i++){a.addEnd(i);}
		 // every time you need to grow, double

	
	a.addStart(5);
	// 5 0 1 2 3 4 5 6 7 8....   499 0 1 2 3 4 5 6 .... 99999	
	

	for (int i = 0; i < 90500; i++){a.removeEnd();}
		

	for (int i = 0; i < 9000; i++){a.removeStart();}
	
	
	// 999 1000 1001 1002 1003 1004 1005 .... .... 1999	

  a.removeEvens();

  a.display();
	
	
}