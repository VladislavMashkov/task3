#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <climits>
using namespace std;



struct Heap {
	vector<int> vHeap;
	int count;

	Heap(): count(0) {}

	void add(int value) {
			++count;
			vHeap.push_back(value);
	}
	void del() {
		if(count > 0) {
			count--;
			vHeap.erase(vHeap.begin() + count);
		} else {
			throw runtime_error("STACK EMPTY IN DEL FUNCTION");
		}
	}
	void get() {
		if(count > 0) {

			cout << vHeap[count] << endl;
		} else {
			throw runtime_error("STACK EMPTY IN GET FUNCTION");
		}
		
	}
};


int main() {
	try {

		Heap Heap1;
    
		Heap1.add(5);
		Heap1.add(3);
		Heap1.add(4);
		Heap1.del();
		Heap1.get();		

    
	} catch(const exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}