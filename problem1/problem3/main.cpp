#include <iostream>
#include<string>
#include<sstream>
using namespace std;
using std::stringstream;
int main()
{
	stringstream ss;
	string s;

	while (cin >> s) {
		ss.clear();
		ss.str(s);
		int a;
		ss >> hex >> a;
		cout << a << endl;
	}

	return 0;
}