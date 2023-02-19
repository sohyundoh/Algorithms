#include <iostream>
#include <map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<string, string> m;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string id, pw;
        cin >> id >> pw;
        m.insert({id,pw});
    }
    for(int i = 0; i<M; i++){
        string find;
        cin >> find;
        cout << m.lower_bound(find)->second<<"\n";
    }
    return 0;
}
