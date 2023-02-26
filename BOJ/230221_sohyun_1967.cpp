#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<pair<int, int>> node[10002];
bool visited[10002] = {false, };
int result = 0;
int endL = 0;

void dfs(int p, int diameter){
    if(visited[p]) return;
    visited[p] = true;

    if(result <diameter){
        result = diameter;
        endL = p;
    }
    for(int i = 0; i< node[p].size(); i++){
        dfs(node[p][i].first, diameter + node[p][i].second);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i<n-1; i++){
        int s,d, value;
        cin >> s>> d>> value;

        node[s].push_back({d,value});
        node[d].push_back({s,value});
    }

    dfs(1,0);

    result = 0;
    memset(visited, false, sizeof(visited));

    dfs(endL,0);
    cout<<result;
    return 0;
}
