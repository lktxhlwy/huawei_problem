#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string s;
	while (cin >> s) {
		char a[256] = { 0 };
		string res;
		for (int i = 0; i < s.size(); i++) {
			if (a[s[i]] == 0) {
				a[s[i]] = 1;
				res+=s[i];
			}
		}

		cout << res.c_str() << endl;
	}

	return 0;
}