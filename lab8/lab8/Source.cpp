#include<iostream>
using namespace std;
void min_heap(int tree[], int t_ln) {
	
	for (int mid = t_ln / 2;mid > 0;mid--) {
		int c_in, mid_el;
		mid_el = tree[mid];
		c_in = 2 * mid;
		while (c_in <= t_ln) {
			if (c_in < t_ln && tree[c_in + 1] < tree[c_in]) {
				c_in = c_in + 1;
			}				
			if (mid_el < tree[c_in])
			{
				break;
			}
			else if (mid_el >= tree[c_in]) 
			{
				tree[c_in / 2] = tree[c_in];
				c_in = 2 * c_in;
			}
		}
		tree[c_in / 2] = mid_el;
	}
}
void print(int tree[], int t_ln) {
	for (int i = 1;i <= t_ln;i++) {
		cout << tree[i]<<endl;
	}	
}
int main() {
	int tree[100];
	int t_el,t_ln;
	cout << "Enter no of elements:";
	cin >> t_ln;
	for (int i = 1;i <= t_ln;i++) {
		cout << "Enter element:";
		cin >> tree[i];
	}
	min_heap(tree, t_ln);
	print(tree,t_ln);
	getchar();
	getchar();
	getchar();
	return 0;
}