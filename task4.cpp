#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct tree{
	vector<int> node_list;
int value;
};
tree t[10];
int getTop(int* arr, int size) {
int top_value;
for(int i = 0; i < size; ++i) {
if(arr[i] == -1) { top_value = i; }
	}
return top_value;
}
void match_tree(int* arr, int size, int base, int position) {
for(int j = 0; j < size; ++j) {
if(arr[j] == position) {
			t[j].value = j;
if(position >= 0) {t[base].node_list.push_back(j); }
match_tree(arr, size, j, j);
		}
	}
}
void message_M(int* arr, int size) {
for(int z = 0; z < size; ++z) {
		cout << arr[z] << " ";
	}
}
void message_P(const tree& A) {
	cout << A.value << " ";
for(vector<int>::const_iterator iter = A.node_list.begin(); iter != A.node_list.end(); ++iter) {
message_P(t[*iter]);
	}
}
void message_O(const tree& A) {
for(vector<int>::const_iterator iter = A.node_list.begin(); iter != A.node_list.end(); ++iter) {
message_O(t[*iter]);
	}
	cout << A.value << " ";
}
void message_S(const tree& A) {
	vector<int>::const_iterator iter = A.node_list.begin();
if (iter != A.node_list.end())
message_S(t[*iter++]);
	cout << A.value << " ";
for(; iter != A.node_list.end(); ++iter) {
message_S(t[*iter]);
	}
}
int main() {
int arr[] = {-1,0,0,0,1,2,3,1,2,3};
int k = sizeof(arr)/sizeof(int);
int top = getTop(arr, k);
match_tree(arr, k, top, -1);
	cout << "Массив указателей на родительский элемент" << endl;
message_M(arr, k);
	cout << endl;
	cout << "Последовательность узлов в прямом порядке" << endl;
message_P(t[top]);
	cout << endl;
	cout << "Последовательность узлов в обратном порядке" << endl;
message_O(t[top]);
	cout << endl;
	cout << "Последовательность узлов в симметричном порядке" << endl;
message_S(t[top]);
	cout << endl;
return 0;
}