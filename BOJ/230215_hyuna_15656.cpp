#include <bits/stdc++.h>
using namespace std;
#define MAX 10

int n, m;
int arr[MAX];
int ans[MAX];

void dfs(int depth) { 
    if(depth == m) {
        for(int i = 0; i < m; i++){
            cout << ans[arr[i]] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 0; i < n; i++) {
        arr[depth] = i; 
        dfs(depth + 1); 
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> ans[i];
    }
    
    sort(ans, ans + n);
    dfs(0);
    return 0;
}