#include <iostream>
#include <vector>

#define MAX 8
using namespace std;
bool visited[MAX + 1] = {false,};
int N, M;
vector<int> v;
void dfs(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= N; i++) {
        v.push_back(i);
        dfs(cnt + 1);
        v.pop_back();
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
    return 0;
}
