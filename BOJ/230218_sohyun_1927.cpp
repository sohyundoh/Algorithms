#include <iostream>
#include <queue>

using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int,vector<int>,greater<int>> p;
    for(int i = 0; i<N;i++){
        int k;
        cin >> k;
        if(k == 0){
            if(p.empty()) cout<< "0"<<"\n";
            else {
                cout<< p.top()<<"\n";
                p.pop();
            }
        }else{
            p.push(k);
        }
    }
    return 0;
}
