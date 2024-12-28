#include <iostream>
#include <iomanip>
#include<stdio.h>
using namespace std;

void main() {
	int (*array)[3] = new int[4][3]{ {1,2,3},{4,5,6},{7,8,9},{10,11,12} };
	int* ptr = (int*)array;
	for (int i = 0; i < 12; i++) {
		cout << setw(3) << *ptr;
		if (i % 3 != 0)
			cout << ",";
		else
			cout << endl;
		ptr++;
	}
	delete[]array;
	getchar();
}
//ÌâÄ¿Á·Ï°