#include<iostream>
#include<string>
#include<vector>
using namespace std;
using std::vector;

char trans(string &num) {
	int sum = 0;
	for (int i = 0; i < num.size(); i++) {
		if (num[i] == '.')
			sum = sum * 2 + 1;
		else if (num[i] == '-')
			sum = sum * 2;
		else
			return 0;
	}

	switch (sum) {
	case(0):
		return 'F';
	case(1):
		return 'G';
	case(2):
		return 'R';
	case(3):
		return 'S';
	case(4):
		return 'T';
	case(5):
		return 'L';
	case(6):
		return 'M';
	case(7):
		return 'N';
	case(8):
		return 'O';
	case(9):
		return 'P';
	case(10):
		return 'Q';
	case(11):
		return 'W';
	case(12):
		return 'X';
	case(13):
		return 'Y';
	case(14):
		return 'Z';
	case(15):
		return 'U';
	case(16):
		return 'A';
	case(17):
		return 'G';
	case(18):
		return 'H';
	case(19):
		return 'I';
	case(20):
		return 'J';
	case(21):
		return 'K';
	case(22):
		return 'B';
	case(23):
		return 'C';
	case(24):
		return 'D';
	case(25):
		return 'E';
	case(26):
		return 'l';
	case(27):
		return 'm';
	case(28):
		return 'n';
	case(29):
		return 'o';
	case(30):
		return 'p';
	case(31):
		return 'i';
	case(32):
		return 'j';
	case(33):
		return 'k';
	case(34):
		return 'f';
	case(35):
		return 'g';
	case(36):
		return 'h';
	case(37):
		return 'a';
	case(38):
		return 'b';
	case(39):
		return 'c';
	case(40):
		return 'd';
	case(41):
		return 'e';
	case(42):
		return 'q';
	case(43):
		return 'r';
	case(44):
		return 'w';
	case(45):
		return 'x';
	case(46):
		return 'y';
	case(47):
		return 'z';
	case(48):
		return 's';
	case(49):
		return 't';
	case(50):
		return 'u';
	case(51):
		return 'v';
	default:
		return 0;

	}

}


int main(void) {
	string s;
	while (cin >> s) {
		string result;
		string num;
		int error_flag = 0;
		for (int i = 0; i < s.size(); i++) {
			if ((s[i] == '#') || (s[i]=='\0')) {
				if (num.empty() == 0) {
					char ret = trans(num);
					if (ret == 0) {
						error_flag = 1;
						break;
					}
					else {
						result += ret;
						num.clear();
					}
				}
			}
			else {
				num += s[i];
			}
			if (i == s.size() - 1) {
				if (num.empty() == 0) {
					char ret = trans(num);
					if (ret == 0) {
						error_flag = 1;
						break;
					}
					else {
						result += ret;
						num.clear();
					}
				}
			}

		}
		if (error_flag) {
			cout << "ERROR" << endl;
		}
		else {
			cout << result.c_str()<<endl;
		}

	}

	return 0;
}

