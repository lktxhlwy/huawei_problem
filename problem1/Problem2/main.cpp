#include<iostream>
using namespace std;

int main(void)
{
	int n;
	int temp;
	
	//freopen("data.txt", "r", stdin);
	while (cin >> n) {
		int number[1001] = { 0 };
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			if (number[temp] == 0)
				number[temp] = 1;
		}

		for (int i = 0; i < 1001; i++) {
			if (number[i] == 1)
				cout << i << endl;
		}

	}
	return 0;
}