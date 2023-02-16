#include <iostream>
#include <queue>

using namespace std;


int bfs(int N, int K) {
    int cnt = 0;
    queue<int> q;

    int visited[100001] = {0,};
    int hits[100001] = {0,};
    q.push(N);
    while (!q.empty()) {
        int top = q.front();
        visited[top] = 1;
        q.pop();
        if (top == K) break;
        if (2*top >= 0 && 2*top <= 100000 &&visited[2 * top] != 1) {
            q.push(2 * top);
            if(hits[2*top] > 0){
                hits[2 * top] = min(hits[top] + 1, hits[2*top]);
            }else{
                hits[2 * top] = hits[top] + 1;
            }
        }
        if (top - 1 >= 0 && top -1 <= 100000 && visited[top - 1] != 1) {
            q.push(top - 1);
            if(hits[top - 1] > 0){
                hits[top - 1] = min(hits[top] + 1, hits[top-1]);
            }else {
                hits[top - 1] = hits[top] + 1;
            }
        }
        if (top + 1 >= 0 && top + 1 <= 100000 && visited[top + 1] != 1) {
            q.push(top + 1);
            if(hits[top +1] > 0){
                hits[top + 1] = min(hits[top] + 1, hits[top+1]);
            }else {
                hits[top + 1] = hits[top] + 1;
            }
        }
    }
    return hits[K];
}


int main() {

    int N, K;
    cin >> N >> K;
    cout << bfs(N, K);

    return 0;
}
