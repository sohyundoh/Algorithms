#include <iostream>
#include <algorithm>
#include <cmath>
#define R 31
#define M 1234567891
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

    int length;
    cin >> length;
    string input;
    cin >> input;
    long long ans=0;
    long long r=1;

    for(int i=0;i<length;i++){
        int a = input[i]-'a'+1;
        ans = (ans+(a*r))%M;
        r = (r*R)%M;
    }
    cout << ans% M;
    return 0;
}
