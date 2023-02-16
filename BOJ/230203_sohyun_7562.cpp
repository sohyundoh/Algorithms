#include <iostream>
#include <queue>

using namespace std;


int mx[4] = {-2,-1,1,2};
int my[4][2] = {{-1,1},{-2,2},{-2,2},{-1,1}};
int bfs(int I, int x, int y, int dx, int dy) {
    int** hits = new int*[I];
    bool** visited = new bool*[I];
    for(int i = 0; i< I; i++){
        hits[i] = new int[I];
        visited[i] = new bool[I];
    }
    for (int j = 0; j < I; j++) {
        for (int k = 0; k < I; k++) {
            hits[j][k] = 0;
            visited[j][k] = false;
        }
    }
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        visited[xx][yy] = true;
        q.pop();
        for(int i = 0; i<4; i++){
            for(int j = 0; j<2; j++){
                int nx = xx + mx[i];
                int ny = yy + my[i][j];
                if(nx >= 0 && nx<= I-1 && ny >= 0 && ny <= I-1 && !visited[nx][ny]){
                    q.push({nx, ny});
                    if(hits[nx][ny] > 0) hits[nx][ny] = min(hits[nx][ny],hits[xx][yy] + 1);
                    else hits[nx][ny] = hits[xx][yy] + 1;
                    visited[nx][ny] = true;
                }
            }
        }
    }
    return hits[dx][dy];
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int I;
        cin >> I;
        int x, y, dx, dy;
        cin >> x >> y;
        cin >> dx >> dy;
        cout << bfs(I, x, y, dx, dy) << "\n";
    }
    return 0;
}
