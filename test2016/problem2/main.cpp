#include<iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
using std::vector;

typedef struct {
	char *filename;
	char filepath[1000];
	int line;
	int count;
}errorlog;

char * get_filename(char* filepath)
{

	int pathlength = strlen(filepath);
	int namelength = pathlength;
	for (int i = pathlength - 1; i >= 0; i--) {
		if (filepath[i] == '\\') {
			namelength = pathlength - 1 - i;
			break;
		}
	}

	char * name = (char*)malloc((namelength + 1) * sizeof(char));
	for (int i = 0; i <= namelength; i++) {
		name[i] = filepath[pathlength - namelength + i];
	}

	return name;
}

void print_filename(char* filename)
{
	int length = strlen(filename);
	if (length <= 16) {
		cout << filename;
	}
	else {
		char *s = &filename[length - 16];
		cout << s;
	}
}


int main(void) {
	vector<errorlog> log;
	errorlog temp;
	int sameflag = 0;

	while (cin >> temp.filepath >> temp.line) {
		sameflag = 0;
		temp.filename = get_filename(temp.filepath);
		int i = 0;
		for (i = 0; i < log.size(); i++) {
			if ((strcmp(log[i].filename, temp.filename) == 0) && (log[i].line == temp.line)) {
				log[i].count++;
				sameflag = 1;
				break;
			}
		}
		if (sameflag == 1) {
			continue;
		}
		else{
			log.push_back(temp);
			log[i].count = 1;
		}
	}

	int printsize = (log.size() > 8) ? 8 : log.size();
	for (int i = 0; i < printsize; i++)
	{
		int maxNum = 0;
		int max = 0;
		int j = 0;
		for (j = 0; j < log.size(); j++) {
			if (log[j].count > max) {
				max = log[j].count;
				maxNum = j;
			}
		}
		print_filename(log[maxNum].filename);
		cout << " " << log[maxNum].line << " " << log[maxNum].count;
		cout << endl;
		vector<errorlog>::iterator k = log.begin() + maxNum;
		log.erase(k);

	}

	return 0;
}