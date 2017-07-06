#include<iostream>
#include<stdio.h>
using namespace std;
int main(void) {
	int drinked;
	int empty;
	while (cin >> empty) {
		drinked = 0;
		while (empty >= 3) {
			drinked = drinked + empty / 3;
			empty = empty - empty / 3 * 2;
		}
		if (empty == 2)
			drinked++;
		cout << drinked << endl;
	}
	return 0;
}