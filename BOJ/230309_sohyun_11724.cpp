#include <iostream>
#include <queue>
#define N_MAX 1001
using namespace std;

int N, M;
bool graph[N_MAX][N_MAX] = {false,};
bool visited[N_MAX] = {false,};
int cnt = 0;

void bfs(int col) {
    visited[col] = true;
    queue<int> q;
    q.push(col);
    while(!q.empty()){
        int next = q.front();
        visited[next] = true;
        q.pop();
        for(int i = 1; i<= N; i++){
            if((graph[next][i] || graph[i][next])&& !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        graph[s][e] = true;
        graph[e][s] = true;
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cnt++;
            visited[i] = true;
            bfs(i);
        }
    }
    cout << cnt;
    return 0;
}
