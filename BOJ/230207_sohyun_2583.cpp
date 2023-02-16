#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100

using namespace std;
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;

        q.pop();

        visited[xx][yy] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] == 0 && visited[nx][ny] == 0) {
                q.push({nx, ny});
                visited[nx][ ny] = 1;
                cnt++;
            }
        }
    }
}

int main() {
    int K;
    cin >> M >> N >> K;
    vector<int> v;
    for (int i = 0; i < K; i++) {
        int sx, sy, kx, ky;
        cin >> sx >> sy >> kx >> ky;
        for (int j = sx; j < kx; j++) {
            for (int n = sy; n < ky; n++) {
                arr[j][n] = 1;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0 && visited[i][j] ==  0) {
                bfs(i, j);
                cnt++;
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

}
