#include<iostream>
using namespace std;
int main(void)
{
	int n, m;
	cin >> n >> m;
	int grade[30001];
	int temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		grade[i] = temp;
	}
	char cmd;
	int a, b;
	int max;
	for (int i = 1; i <= m; i++) {
		max = 0;
		cin >> cmd;
		cin >> a >> b;
		if (cmd == 'Q') {
			if (a <= b) {
				for (int j = a; j <= b; j++) {
					if (grade[j] > max)
						max = grade[j];
				}
			}
			else {
				for (int j = b; j <= a; j++) {
					if (grade[j] > max)
						max = grade[j];
				}
			}
			cout << max << endl;
		}
		else if (cmd == 'U') {
			grade[a] = b;
		}
	}
}