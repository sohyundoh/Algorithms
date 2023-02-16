#include<iostream>
#include<queue>
#include<vector>
using namespace std;
queue<pair <int, int>> q;
bool check[1000001];
int parent[1000001];
int N, K;
vector<int> path;
void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int time = q.front().second;
        check[x] = true;
        q.pop();
        if (x == K) { // parent를 통해 역추적
            int idx = x;
            while (idx != N) {
                path.push_back(idx);
                idx = parent[idx];
            }
            cout << time << "\n";
            break;
        }
        if (x-1 >= 0 && x-1 <= 200000 && check[x-1] == false) {
            q.push(make_pair(x-1, time + 1));
            check[x-1] = true;
            parent[x-1] = x;
        }

        if (x+1 >= 0 && x+1 <= 200000 && check[x+1] == false) {
            q.push(make_pair(x+1, time + 1));;
            check[x+1] = true;
            parent[x+1] = x;
        }

        if (x*2 >= 0 && x * 2 <= 200000 && check[x * 2] == false) {
            q.push(make_pair(x * 2, time + 1));
            check[x * 2] = true;
            parent[x * 2] = x;
        }
    }
}




int main(void) {
    cin >> N >> K;
    q.push(make_pair(N, 0));
    bfs();
    cout << N<< ' ';
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << ' ';

    return 0;
}
