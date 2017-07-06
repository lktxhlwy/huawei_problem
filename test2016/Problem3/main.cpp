#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
	int size = a.size();
	int type = 0;
	switch (size)
	{
	case(1):
		type = GEZI;
		break;
	case(3):
		type = DUIZI;
		break;
	case(5):
		if ((a == "joker") || (a == "JOKER"))
			type = GEZI;
		else
			type = SANGE;
		break;
	case(7):
		type = ZHADAN;
		break;
	case(9):
		type = SHUNZI;
		break;
	case(11):
		type = DUIWANG;
		break;
	default:
		break;
	}

	return type;
}

int main(void)
{
	char a[64], b[64];
	scanf("%[^-]-%[^\n]", a, b);
	string info1 = a;
	string info2 = b;

	if (gettype(info1) == DUIWANG)
		cout << info1.c_str();
	if (gettype(info2) == DUIWANG)
		cout << info2.c_str();

	return 0;
}