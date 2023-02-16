#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N, K, M;
vector<vector<int>> v;
vector<vector<int>> element;
queue<pair<int, int>> q;

bool visited[1001] = {false,};
bool visitednode[100001] = {false,};

int bfs() {
    q.push({1, 1});
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (cur == N) {
            cout << cnt;
            return 0;
        }
        int len = v[cur].size();

        for (int i = 0; i < len; ++i) {
            int next = v[cur][i];
            int ncnt = cnt + 1;

            if (!visited[next]) {
                visited[next] = true;

                int nnum = element[next].size();

                for (int j = 0; j < nnum; ++j) {
                    if (element[next][j] == cur) {
                        continue;
                    }

                    if (!visitednode[element[next][j]]) {
                        q.push({element[next][j], ncnt});
                        visitednode[element[next][j]] = true;
                    }
                }
            }
        }
    }
    cout << "-1";
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K >> M;

    v.resize(N + 1);
    element.resize(M + 1);
    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j < K; ++j) {
            int n;
            cin >> n;
            v[n].push_back(i);
            element[i].push_back(n);
        }
    }
    bfs();
    return 0;
}
