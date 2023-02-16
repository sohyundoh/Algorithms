#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for(int i = 0; i<T; i++){
        int N;
        cin>> N;
        vector<pair<int, int>> v;
        for(int k = 0; k<N; k++){
            int a, b;
            cin >> a >> b;
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        int cnt = 1;
//        for(int k = 0; k<N; k++){
//            cout << v[k].first<<" "<<v[k].second<<"\n";
//        }
        int min = v[0].second;
        for(int k = 1; k<N;k++){
            if(v[k].second < min){
                min = v[k].second;
                cnt ++;
            }
        }
        cout<< cnt<<"\n";
    }
    return 0;
}
