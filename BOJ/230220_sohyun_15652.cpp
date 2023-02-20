#include <iostream>
#include <vector>

#define MAX 8
using namespace std;

bool visited[MAX + 1] = {false,};
int N, M;
vector<int> v;
void dfs(int cnt, int k) {
    if (cnt == M) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = k; i <= N; i++) {
        v.push_back(i);
        dfs(cnt + 1, i);
        v.pop_back();
    }
}

int main() {
    cin >> N >> M;
    dfs(0,1);
    return 0;
}
