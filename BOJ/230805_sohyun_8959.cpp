#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    char arr[n][80];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 80; j++) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int score = 0, tmp = 1;
        for (int j = 0; arr[i][j] != 0; j++) {
            if (arr[i][j] == 'O') {
                score += tmp;
                tmp++;
            } else if (arr[i][j] == 'X') {
                tmp = 1;
            }
        }
        cout << score << "\n";
    }
    return 0;
}
