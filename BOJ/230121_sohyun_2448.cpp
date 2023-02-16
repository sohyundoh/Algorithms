#include <iostream>
using namespace std;

char board[3200][6300];
int N;

void draw(int x, int y) {

	board[x][y] = '*';
	board[x + 1][y - 1] = '*';
	board[x + 1][y + 1] = '*';
	for (int i = 0; i < 5; i++) {
		board[x + 2][y - 2 + i] = '*';
	}
}
void recursive(int n, int x, int y) {
	
	if (n == 3) {
		draw(x, y);
		return;
	}
	recursive(n / 2, x, y);
	recursive(n / 2, x + n/ 2, y - n / 2);
	recursive(n / 2, x + n / 2, y + n / 2);
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2 * N; j++)
			board[i][j] = ' ';
	recursive(N, 0, N - 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) cout << board[i][j];
		cout << "\n";
	}
}
