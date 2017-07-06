/*
* TestRPN.h
*
* C++实现整数四则运算
*
* 有两个步骤， 一是convert2RPN，把普通的中缀表达式改成后缀表达式（逆波兰表达式，RPN），
* 二是calculateRPN，计算后序表达式得到结果
*
*  Created on: 2015年3月17日
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
* 把中缀表达式改成后缀表达式
* 遍历字符串，如果是数字，则输出，同时加上空格和后面的字符分隔
* 如果括号，有2种情况：
* 1 如果是（，进栈
* 2 如果是），将栈里面对应的（以及它上面的符号出栈
* 如果是符号，总的规则是只要栈顶的符号的优先级不低于当前符号，则把栈顶的符号一一出栈，
* 直到遇到栈顶的符号的优先级低于当前符号为止。具体有2种情况：
* 1 如果是+或-，将栈顶的符号一一出栈，直到遇到（或栈空了为止；然后把自身压栈
* 2 如果是*或/，将栈里面的*或/出栈，直到遇到其他符号或栈空了为止；然后把自身压栈
*/
void convert2RPN(string &s) {
	stringstream ss;
	stack<char> stk;
	for (size_t i = 0; i < s.length(); i++) {
		if (isdigit(s.at(i))) {
			ss << s.at(i);
			// 如果下一位不是数字，或者已经是最后一位，就加上空格
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
					// 把配套的'('和之上的符号出栈
					while (stk.top() != '(') {
						ss << stk.top();
						stk.pop();
					}
					stk.pop();
					break;
				case '+':
				case '-':
					// '+' '-' '*' '/'都出栈
					while (!stk.empty() && stk.top() != '(') {
						ss << stk.top();
						stk.pop();
					}
					stk.push(s.at(i));
					break;
				case '*':
				case '/':
					// '*'和'/'出栈
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
	// 运算完了，此时把栈的元素都pop出来
	while (!stk.empty()) {
		ss << stk.top();
		stk.pop();
	}
	s = ss.str();
}

/*
* 计算后缀表达式
* 遍历后缀表达式，如果是数字，则压栈，如果是符号，则从栈里面pop两个数字，然后和符号做
* 相应的运算，同时把结果压栈，最后把栈顶结果返回
*/
float calculateRPN(const string &s) {
	stack<float> stk;
	for (size_t i = 0; i < s.length(); i++) {
		// 如果是数字，就和之前的数字组合起来
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
