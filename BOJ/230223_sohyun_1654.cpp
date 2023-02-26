#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int K, N;
    cin >> K >> N;
    vector<long long> lan;
    long long maxL = 0;
    for(int i = 0; i< K; i++) {
        int l;
        cin >> l;
        lan.push_back(l);
        maxL = (l > maxL) ? l : maxL;
    }
    long long low = 1;
    long long high = maxL;
    long long mid = (low + high)/2;
    int ans = 0;
    while(low<=high){
        long long cnt = 0;
        for(int i = 0; i< K; i++){
            cnt += lan[i]/mid;
        }
        if(cnt >= N ) {
            if(ans < mid){
                ans = mid;
            }
            low = mid+1;
        }else if(cnt <N){
            high = mid - 1;
        }
        mid = (low + high)/2;
    }
    cout<< ans;
    return 0;
}
