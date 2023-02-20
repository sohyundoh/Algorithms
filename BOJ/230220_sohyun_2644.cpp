#include <iostream>
#include <queue>
#include <cstring>

#define N_MAX 101

using namespace std;

int map[N_MAX][N_MAX] = {0,};
bool hasDirect[N_MAX][N_MAX] = {false,};
int N;
int dist;

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
    dist = -1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N ;
    int s, d;
    cin >> s >> d;
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        //양방향 간선이므로
        map[a][b] = 1;
        map[b][a] = 1;
        hasDirect[a][b] = true;
        hasDirect[b][a] = true;
    }
    bfs(s, d);
    cout << dist << "\n";
    return 0;
}
