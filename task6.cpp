#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

template <typename ntype>
struct Heap {
	vector<ntype> vHeap;
	int count;

	Heap(): count(0) {}

	void add(ntype value) {
			++count;
			vHeap.push_back(value);
	}
	void del() {
		if(count > 0) {
			ntype min = vHeap[0];
			int pos = 0;
			for(int i = 0; i < count; ++i) {
				if(min < vHeap[i]) {
					min = vHeap[i];
					pos = i;
				}
			}
			--count;
			vHeap.erase(vHeap.begin() + pos);
		} else {
			throw runtime_error("STACK EMPTY IN DEL FUNCTION");
		}
	}
	void get() {
		if(count > 0) {
			ntype min = INT_MAX;
			for(int i = 0; i < count; ++i) {
				if(min > vHeap[i]) {
					min = vHeap[i];
				}
			}
			cout << "Minimal Value: " << min << endl;
		} else {
			throw runtime_error("STACK EMPTY IN GET FUNCTION");
		}
		
	}
};


int main() {
	try {
		Heap<int> Heap1;
    
		Heap1.add(5);
		Heap1.add(3);
		Heap1.add(4);
		Heap1.del();
		Heap1.get();

		Heap<double> Heap2;
    
		Heap2.add(5.5);
		Heap2.add(3.5);
		Heap2.add(4.5);
		Heap2.del();
		Heap2.get();		

    
	} catch(const exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}