#include <iostream>
#include <algorithm>//max
#define Max 1500001
using namespace std;

int N;
int T[Max];
int P[Max];
int DP[Max] = { 0, };

void solution() {
	DP[1] = 0;
	int ans = 0;
	for (int i = 1; i <= N + 1; i++) {
		ans = max(ans, DP[i]);
		if (i + T[i] > N + 1)
			continue;
		else {
			DP[i + T[i]] = max(DP[i + T[i]], ans + P[i]);
		}
	}
	
	cout << ans << '\n';
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	solution();
	return 0;
}
