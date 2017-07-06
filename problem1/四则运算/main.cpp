/*
* TestRPN.h
*
* C++ʵ��������������
*
* ���������裬 һ��convert2RPN������ͨ����׺���ʽ�ĳɺ�׺���ʽ���沨�����ʽ��RPN����
* ����calculateRPN�����������ʽ�õ����
*
*  Created on: 2015��3��17��
*      Author: L
*/

#pragma once
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <sstream>
using namespace std;

/*
* ����׺���ʽ�ĳɺ�׺���ʽ
* �����ַ�������������֣��������ͬʱ���Ͽո�ͺ�����ַ��ָ�
* ������ţ���2�������
* 1 ����ǣ�����ջ
* 2 ����ǣ�����ջ�����Ӧ�ģ��Լ�������ķ��ų�ջ
* ����Ƿ��ţ��ܵĹ�����ֻҪջ���ķ��ŵ����ȼ������ڵ�ǰ���ţ����ջ���ķ���һһ��ջ��
* ֱ������ջ���ķ��ŵ����ȼ����ڵ�ǰ����Ϊֹ��������2�������
* 1 �����+��-����ջ���ķ���һһ��ջ��ֱ����������ջ����Ϊֹ��Ȼ�������ѹջ
* 2 �����*��/����ջ�����*��/��ջ��ֱ�������������Ż�ջ����Ϊֹ��Ȼ�������ѹջ
*/
void convert2RPN(string &s) {
	stringstream ss;
	stack<char> stk;
	for (size_t i = 0; i < s.length(); i++) {
		if (isdigit(s.at(i))) {
			ss << s.at(i);
			// �����һλ�������֣������Ѿ������һλ���ͼ��Ͽո�
			if ((i < s.length() - 1 && !isdigit(s.at(i + 1)))
				|| i == s.length() - 1) {
				ss << ' ';
			}
		}
		else {
			if (stk.empty()) {
				stk.push(s.at(i));
			}
			else {
				switch (s.at(i)) {
				case '(':
					stk.push(s.at(i));
					break;
				case ')':
					// �����׵�'('��֮�ϵķ��ų�ջ
					while (stk.top() != '(') {
						ss << stk.top();
						stk.pop();
					}
					stk.pop();
					break;
				case '+':
				case '-':
					// '+' '-' '*' '/'����ջ
					while (!stk.empty() && stk.top() != '(') {
						ss << stk.top();
						stk.pop();
					}
					stk.push(s.at(i));
					break;
				case '*':
				case '/':
					// '*'��'/'��ջ
					while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
						ss << stk.top();
						stk.pop();
					}
					stk.push(s.at(i));
					break;
				}
			}
		}
	}
	// �������ˣ���ʱ��ջ��Ԫ�ض�pop����
	while (!stk.empty()) {
		ss << stk.top();
		stk.pop();
	}
	s = ss.str();
}

/*
* �����׺���ʽ
* ������׺���ʽ����������֣���ѹջ������Ƿ��ţ����ջ����pop�������֣�Ȼ��ͷ�����
* ��Ӧ�����㣬ͬʱ�ѽ��ѹջ������ջ���������
*/
float calculateRPN(const string &s) {
	stack<float> stk;
	for (size_t i = 0; i < s.length(); i++) {
		// ��������֣��ͺ�֮ǰ�������������
		if (isdigit(s.at(i))) {
			int e = atoi(&s.at(i));
			int t = e / 10;
			while (t > 0) {
				i++;
				t /= 10;
			}
			i++;
			stk.push(e);
		}
		else {
			float r = stk.top();
			stk.pop();
			float l = stk.top();
			stk.pop();
			float result;
			switch (s.at(i)) {
			case '+':
				result = l + r;
				break;
			case '-':
				result = l - r;
				break;
			case '*':
				result = l * r;
				break;
			case '/':
				result = l / r;
				break;
			}
			stk.push(result);
		}
	}
	return stk.top();
}

void testRPN() {
	//	string s = "9+(3-1)*3+10/2";
	string s = "9+3*10*6";
	convert2RPN(s);
	cout << calculateRPN(s) << endl;
}
