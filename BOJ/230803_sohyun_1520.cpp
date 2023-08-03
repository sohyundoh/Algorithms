#include <iostream>
#include <algorithm>

using namespace std;

int board[503][503];
int dp[503][503];
bool check[503][503];
int M, N;

int dfs(int x, int y) {
	if (x < 0 || y < 0 || y >= M || x >= N) return 0;
	if (check[x][y] == true) return dp[x][y];
	if (board[x][y] < board[x - 1][y]) dp[x][y] += dfs(x - 1, y);
	if (board[x][y] < board[x][y - 1]) dp[x][y] += dfs(x, y - 1);
	if (board[x][y] < board[x][y + 1]) dp[x][y] += dfs(x, y + 1);
	if (board[x][y] < board[x + 1][y]) dp[x][y] += dfs(x + 1, y);
	check[x][y] = true;
	return dp[x][y];
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	dp[0][0] = 1;
	cout << dfs(N - 1, M - 1) << "\n";
}
