#include<iostream>
#include<vector>
using namespace std;
using std::vector;

int getsum(int a) {
	int n1, n2, n3;
	int sum;
	n1 = a / 100;
	n2 = (a - n1 * 100) / 10;
	n3 = a % 10;
	sum = n1*n1*n1 + n2*n2*n2 + n3*n3*n3;
	return sum;
}
int main(void) {
	int total = 0;
	int totalNum = 0;
	for (int i = 100; i <= 999; i++) {
		if (i == getsum(i)) {
			cout << "第"<<totalNum+1<<"个水仙花数: "<< i << endl;
			total += i;
			totalNum++;
		}
	}

	cout << "水仙花数总和为: "<<total << endl;

	return 0;
}