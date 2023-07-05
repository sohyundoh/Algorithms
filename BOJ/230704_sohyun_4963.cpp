#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
int map[51][51];
bool visit[51][51];
int w, h;
int dx[] = {0,0,-1,1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,-1,1};
int cnt = 0;
void bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < w && ny >=0 && ny < h){
                if(!visit[ny][nx] && map[ny][nx] == 1){
                    q.push(make_pair(nx, ny));
                    visit[ny][nx] = true;
                }
            }
        }
    }
}
int main(){
    while(1){
        cin >> w >> h;
        if(w==0 && h==0){
            break;
        }
        cnt = 0;
        memset(visit, false, sizeof(visit));
        queue<pair<int, int>> queue;
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w;j++){
                cin >> map[i][j];
                if(map[i][j]==1){
                    queue.push(make_pair(j, i));
                }
            }
        }
        while(!queue.empty()){
            int xx = queue.front().first;
            int yy = queue.front().second;
            if(!visit[yy][xx]){
                visit[yy][xx] = true;
                bfs(xx, yy);
                cnt++;
            }
            queue.pop();
        }
        cout << cnt << '\n';
    }
    return 0;
}
