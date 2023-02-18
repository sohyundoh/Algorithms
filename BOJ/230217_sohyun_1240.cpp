#include <iostream>
#include <queue>
#include <cstring>

#define N_MAX 1001

using namespace std;

int map[N_MAX][N_MAX] = {0,};
bool hasDirect[N_MAX][N_MAX] = {false,};
int N, M;
long long dist;

void bfs(int s, int d) {
    queue<pair<int, int>> q;
    dist = 0;
    bool visited[1001];
    memset(visited, false, N + 1);
    q.push({s,0});
    visited[s] = true;
    while (!q.empty()) {
        int temp = q.front().first;
        visited[temp] = true;
        dist = q.front().second;
        q.pop();
        if (hasDirect[temp][d]) {
            dist += map[temp][d];
            return;
        }
        for (int i = 1; i <= N; i++) {
            if (hasDirect[temp][i] && !visited[i]) {
                visited[i] = true;
                q.push({i, dist+ map[temp][i]});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N - 1; i++) {
        int a, b, price;
        cin >> a >> b >> price;
        //양방향 간선이므로
        map[a][b] = price;
        map[b][a] = price;
        hasDirect[a][b] = true;
        hasDirect[b][a] = true;
    }
    for (int i = 0; i < M; i++) {
        int s, d;
        cin >> s >> d;
        bfs(s, d);
        cout << dist << "\n";
    }
    return 0;
}
