#include<iostream>
#include<vector>
using namespace std;
using std::vector;

int main(void)
{
	int n;
	while (cin >> n) {
		if (n > 1000)
			n = 1000;
		vector<int> a(n, 1);
		int deleted = 0;
		int index = 0;
		while (deleted < n) {
			while (a[index] == 0)
			{
				index++;
				if (index > n - 1)
					index = 0;
			}
			index++;
			if (index > n - 1)
				index = 0;
			while (a[index] == 0)
			{
				index++;
				if (index > n - 1)
					index = 0;
			}
			index++;
			if (index > n - 1)
				index = 0;
			while (a[index] == 0)
			{
				index++;
				if (index > n - 1)
					index = 0;
			}
			a[index] = 0;
			deleted++;
		}
		cout << index << endl;
	}

	return 0;
}