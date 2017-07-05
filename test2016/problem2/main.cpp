#include<iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef struct {
	char *filename;
	char filepath[100];
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
	errorlog log[8];
	int totalcount = 0;
	errorlog temp;
	int sameflag = 0;
	while (cin >> temp.filepath >> temp.line) {
		sameflag = 0;
		temp.filename = get_filename(temp.filepath);
		int i = 0;
		for (i = 0; i < totalcount; i++) {
			if ((strcmp(log[i].filename,temp.filename)==0) && (log[i].line == temp.line)) {
				log[i].count++;
				sameflag = 1;
				break;
			}
		}
		if (sameflag == 1) {
			continue;
		}
		else if ((totalcount <= 8) && (i == totalcount))
		{
			log[i] = temp;
			log[i].count = 1;
			totalcount++;
		}
	}

	for (int j = 0; j < totalcount; j++)
	{
		print_filename(log[j].filename);
		cout << " " << log[j].line << " " << log[j].count;
		cout << endl;
	}

	return 0;

}