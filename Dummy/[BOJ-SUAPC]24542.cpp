#include <iostream>
using namespace std;

int combination(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	else
		return combination(n - 1, r - 1) + combination(n - 1, r);
}
int main(void) {
	int N;
	cin >> N;
	int a[N], b[N];
	int answer[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i];
		if (a[i] > b[i]) {
			for (int j = 1; j < b[i]; j++) {
				answer[i] = combination(b[i], j) + combination(a[i], j);
			}
		}
		else {
			for (int k =10; k < a[i]; k++) {
				answer[i] = combination(b[i], k) + combination(a[i], k);
			}
		}
	}
	int printnum = 1;
	for (int i = 0; i < N; i++) {
		printnum *= answer[i];
	}
	cout << printnum;
	return 0;
}
