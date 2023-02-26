#include <iostream>
#include <queue>

#define MAX 1001
using namespace std;
int N, M;
int map[MAX][MAX] = {0,};
int dist[MAX][MAX] = {0,};
int dst[2];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (nx <= 0 || nx > N || ny <= 0 || ny > M || map[nx][ny] == 0 || dist[nx][ny])
                continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[xx][yy] + 1;
        }
    }
//    q.push({x, y});
//
//    while (q.size()) {
//        int a = q.front().first;
//        int b = q.front().second;
//        q.pop();
//
//        for (int i = 0; i < 4; i++) // 상하좌우 갈수있는 땅 탐색
//        {
//            int nx = a + dx[i];
//            int ny = b + dy[i];
//
//            if (nx <= 0 || nx > N || ny <= 0 || ny > M || map[nx][ny] == 0 || dist[nx][ny])
//                continue; // 갈수 없거나 이미 방문한곳이면 컨티뉴
//
//            q.push({nx, ny});
//            dist[nx][ny] = dist[a][b] + 1;
//
//        }
//
//    }

    dist[dst[0]][dst[1]] = 0; // 2로 지정한 처음위치를 0으로 처리해줌.
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                dst[0] = i;
                dst[1] = j;
            }
        }
    }
    bfs(dst[0], dst[1]);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (dist[i][j] == 0 && map[i][j] == 1) // 갈수있는 땅이지만 가지못해서 방문배열이 0으로 처리된구역을 -1로 해줌
                dist[i][j] = -1;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
