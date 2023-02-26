#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> stick;
    int length;
    for(int i = 0; i< N; i++){
        int l;
        cin >> l;
        stick.push_back(l);
    }

    sort(stick.begin(),stick.end());
    for(int i = stick.size()- 1; i>= 2; i--){
        if(stick[i] < stick[i-1]+ stick[i-2]){
            length = stick[i] + stick[i-1]+ stick[i-2];
            break;
        }else{
            length = -1;
        }
    }
    cout<< length;
    return 0;
}
