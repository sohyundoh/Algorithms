#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int fx, fy;
//맥주의 갯수를 따로 따로 저장하는 것이 챌린지다.
bool exist(vector<pair<int, int>> v, pair<int, int> p){
    if(find(v.begin(),v.end(), p) != v.end() ) return true;
    return false;
}
bool bfs(int hx, int hy, vector<pair<int,int>> v){
    queue<pair<int, int>> q;
    q.push({hx,hy});
    vector<pair<int, int>> visited;
    while(!q.empty()){
        int i = 0;
        int x = q.front().first;
        int y = q.front().second;
        visited.push_back({x,y});
        q.pop();
        if(abs(fx - x) + abs(fy - y) <= 1000) return true;
        for(i ; i<v.size(); i++){
            if(abs(v[i].first - x) + abs(v[i].second - y) <= 1000 && !exist(visited, v[i])){
                int nx = v[i].first;
                int ny = v[i].second;
                visited.push_back({nx,ny});
                q.push({nx,ny});
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int i = 0; i<T; i++){
        int c;
        cin >> c;
        int hx,hy;
        cin >> hx >> hy;
        vector<pair<int,int>> convenience;
        for(int j = 0; j< c;j++){
            int x, y;
            cin >> x >> y;
            convenience.push_back({x,y});
        }
        cin >> fx >> fy;
        if(bfs(hx, hy, convenience)) cout<<"happy"<<"\n";
        else cout<<"sad"<<"\n";
    }
    return 0;
}
