#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<algorithm>

using namespace std;
using std::string;

#define GEZI	1
#define DUIZI	2
#define SANGE	3
#define SHUNZI	4
#define ZHADAN	5
#define DUIWANG	6

int gettype(string a)
{
	int size = count(a.begin(), a.end(), ' ')+1;
	int type = 0;
	switch (size)
	{
	case(1):
		type = GEZI;
		break;
	case(2):
		if (a.find("joker") != -1)
			type = DUIWANG;
		else
			type = DUIZI;
		break;
	case(3):
		type = SANGE;
		break;
	case(4):
		type = ZHADAN;
		break;
	case(5):
		type = SHUNZI;
		break;
	default:
		break;
	}

	return type;
}

int infopos(string a) {
	string total_str = "345678910JQKA2jokerJOKER";
	int pos = 0;
	string substr;
	switch(gettype(a))
	{
	case(GEZI):
		pos = total_str.find(a);
		break;
	case(DUIZI):
	case(SANGE):
	case(ZHADAN):
	case(SHUNZI):
	case(DUIWANG):
		substr = a.substr(0, a.find(' '));
		pos = total_str.find(substr);
		break;
	default:
		break;
	}
	return pos;
}

void infocmp(string a, string b)
{
	if (infopos(a)<infopos(b))
		cout << b.c_str() << endl;
	else
		cout << a.c_str() << endl;

	return;
}

int main(void)
{
	char a[64], b[64];
	scanf("%[^-]-%[^\n]%*c", a, b);
	string info1 = a;
	string info2 = b;
	string total_str = "345678910JQKA2jokerJOKER";
	int type1 = gettype(info1);
	int type2 = gettype(info2);

	if ((type1 == DUIWANG) || (type2 == DUIWANG))
		cout << "joker JOKER" << endl;
	else if ((type1 == ZHADAN) || (type2 == ZHADAN)) {
		if ((type1 == ZHADAN) && (type2 == ZHADAN))
			infocmp(info1, info2);
		else if (type1 == ZHADAN)
			cout << info1.c_str() << endl;
		else
			cout << info2.c_str() << endl;
	}
	else if (type1 == type2) {
		infocmp(info1, info2);
	}
	else {
		cout << "ERROR" << endl;
	}

	return 0;
}