#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[25][25] = {{false,}};
int arr[25][25] = {{0,}};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int cnt = 0;

void bfs(int N, int x, int y) {
    queue<pair<int, int>> q;
    q.push(pair<int, int>(x, y));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = true;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx <= N - 1 && ny >= 0 && ny <= N - 1 && !visited[nx][ny] && arr[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push(pair<int, int>(nx, ny));
                cnt++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> house;
    for (int i = 0; i < N; i++) {
        char *s = new char[N];
        cin >> s;
        for (int j = 0; j < N; j++) {
            char c = s[j];
            if (c == '1') arr[i][j] = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1 && !visited[i][j]) {
                bfs(N, i, j);
                cnt++;
                house.push_back(cnt);
                cnt = 0;
            }
        }
    }
    cout << house.size() << "\n";
    sort(house.begin(), house.end());
    for (int i = 0; i < house.size(); i++) {
        cout << house[i] << "\n";
    }
    return 0;
}
