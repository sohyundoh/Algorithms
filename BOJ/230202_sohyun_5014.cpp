#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;


void elebator(int F) {
    queue<int> q;
    int visited[F+1];
    int hits[F+1];

    for (int i = 0; i < F + 1; i++) {
        visited[i] = 0; //초기화
        hits[i] = 0;
    }
    q.push(S);
    while (!q.empty()) {
        int floor = q.front();
        q.pop();
        if(visited[floor] ==1) continue;
        visited[floor] = 1;
        if (floor + U <= F && visited[floor + U] != 1) {
            q.push(floor + U);
            if (hits[floor + U] > 0 && visited[floor + U] != 1)
                hits[floor + U] = min(hits[floor + U], hits[floor] + 1);
            else
                hits[floor + U] = hits[floor] + 1;
        }

        if (floor - D >= 1 && visited[floor - D] != 1) {
            q.push(floor - D);
            if (hits[floor - D] > 0)
                hits[floor - D] = min(hits[floor - D], hits[floor] + 1);
            else
                hits[floor - D] = hits[floor] + 1;
        }

    }
    if (visited[G] != 0)
        cout<< hits[G];
    else
        cout<<"use the stairs";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> F >> S >> G >> U >> D;
    elebator(F);

    return 0;
}
