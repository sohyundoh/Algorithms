#include <iostream>
#include <vector>

#define MAX 8
using namespace std;
/*
 * 문제 : 자연수의 크기 MAX : M , 수열의 길이: N
 * 중복 없이! 중복이 있는 것을 제외해야함 !  중복이 있는 것을 체크해야함.
 *
 */
bool visited[MAX + 1] = {false,};
int N, M;
vector<int> v;
void dfs(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= N; i++) {
        if(visited[i] != true){
            visited[i] = true;
            v.push_back(i);
            dfs(cnt + 1);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
    return 0;
}
