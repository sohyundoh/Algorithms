#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;
string str;
int n = str.size();

bool palindrom(int i) {
	int half = (n - i) / 2;
	for (int j = 0; j < half; j++) {
		if (str[i + j] != str[n - 1 - j]) return false;
	}
	return true;
}

int main()
{
	cin >> str;
	n = str.size();

	for (int i = 0; i < n; i++) {
		if (palindrom(i)) {
			cout << n + i;
			return 0;
		}
	}
}
