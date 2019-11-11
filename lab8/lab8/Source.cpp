#include<iostream>
using namespace std;
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//builtHeap function
//this function will convert the array into min heap
void builtHeap(int tree[], int t_ln) {
	
	for (int mid = t_ln / 2;mid > 0;mid--) {
		int c_in, mid_el;
		mid_el = tree[mid];
		c_in = 2 * mid;//left child index
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
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//method to display the min heap (array)
void print(int tree[], int t_ln) {
	for (int i = 1;i <= t_ln;i++) {
		cout << tree[i]<<endl;
	}	
}
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//this function will gives the height of the tree
void height(int t_ln) {
	int h=0;
	while (t_ln > 1) {
		t_ln = t_ln / 2;//this gives the parent node index
		h++;
	}
	cout << "Height of the tree is " << h << endl;
}
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//this gives the size of the tree
void size(int t_ln) {
	cout << "Size of the tree is " << t_ln << endl;
}
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//this method gives that either the tree is empty or not
void isEmpty(int t_ln) {
	if (t_ln == 0) {
		cout << "Tree is empty!" << endl;
	}
	else {
		cout << "Tree is not empty!" << endl;
	}
}
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//this method returns the top (root of tree) if tree is non empty
//if tree is emty than simply print that tree is empty
void top(int tree[],int t_ln) {
	if (t_ln == 0) {
		cout << "Tree is empty!" << endl;
	}
	else {
		cout << "Top of tree is " << tree[1] << endl;
	}
}
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//this will add new element in the array
void push(int tree[], int &t_ln, int inp) {
	t_ln++;//increment in tree size
	tree[t_ln]=inp;
	builtHeap(tree, t_ln);//again form the tree to maintain the min heap property
}
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
//this will simply remove the root of the tree
void pop(int tree[], int &t_ln) {
	tree[1] = tree[t_ln];
	t_ln--;//decrement in size of tree
	builtHeap(tree, t_ln);//again form the tree to maintain the min heap property
}
//------------------------------------------------------------------------//
//------------------------------------------------------------------------//
int main() {
	int tree[100];
	int fun_no,t_ln;
	char flag;
	cout << "Enter no of elements:";
	cin >> t_ln;//ask no of elements to be stored in tree
	for (int i = 1;i <= t_ln;i++) {//take elements from user and store them in an array
		cout << "Enter element:";
		cin >> tree[i];
	}
	builtHeap(tree, t_ln);//call method which form the min tree
	cout << "List of functions:"<<endl;
	cout<< "1: Top" << endl 
		<< "2: Pop" << endl 
		<< "3: Push" << endl 
		<< "4: isEmpty" << endl 
		<< "5: size" << endl
		<< "6: height" << endl 
		<< "7: print"<<endl;
	do
	{
		cout << "Which function you want to perform:";
		cin >> fun_no;//ask which function user want to perform
		switch (fun_no)
		{
		case 1:
			top(tree, t_ln);
			break;
		case 2:
			pop(tree, t_ln);
			break;
		case 3:
			int inp;
			cout << "Enter element:";
			cin >> inp;
			push(tree, t_ln, inp);
			break;
		case 4:
			isEmpty(t_ln);
			break;
		case 5:
			size(t_ln);
			break;
		case 6:
			height(t_ln);
			break;
		case 7:
			print(tree, t_ln);
			break;
		}
		cout << "Do you want to again perform any function (y/n)";
		cin >> flag;
	} while (flag == 'y' || flag == 'Y');//check user wants to again perform any function or not
	getchar();
	getchar();
	getchar();
	return 0;
}