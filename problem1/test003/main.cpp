#include<iostream>
#include<string>
#include<vector>
using namespace std;
using std::vector;

typedef struct {
	string a;
	string b;
}guanxi;

int search_call(string &caller, string &goal,string &origin_caller,vector<guanxi> &guanxibiao) {
	for (int i = 0; i < guanxibiao.size(); i++) {
		if (guanxibiao[i].a.compare(caller) == 0) {
			if (guanxibiao[i].b.compare(goal) == 0) {
				return 1;
			}
			else if (guanxibiao[i].b.compare(caller) == 0) {
				return 1;
			}
			else if (guanxibiao[i].b.compare(origin_caller) == 0) {
				return 1;
			}
			else if (search_call(guanxibiao[i].b, goal, origin_caller,guanxibiao) == 1) {
				return 1;
			}
		}
	}

	return 0;
}

int main(void) {
	int n;	
	while (cin >> n) {
		vector<guanxi> guanxibiao;
		guanxi temp;
		string qa, qb;
		int result1, result2;
		for (int i = 0; i < n; i++) {
			cin >> temp.a;
			cin >> temp.b;
			guanxibiao.push_back(temp);
		}

		cin >> qa >> qb;
		result1 = search_call(qa, qb, qa, guanxibiao);
		result2 = search_call(qb, qa, qb, guanxibiao);
		if ((result1 == 1) && (result2 == 1))
			cout << "T" << endl;
		else
			cout << "F" << endl;

	}
	return 0;
}