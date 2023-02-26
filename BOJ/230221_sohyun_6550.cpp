#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string s, t;
    while(cin>> s>>t)
    {
        bool flag = false;
        int j = 0;
        for(int i = 0; i<t.length();i++){
            if(s[j] == t[i]){
                j++;
            }
            if(j == s.length()){
                flag = true;
            }
        }
        if(flag){
            cout <<"Yes"<<"\n";
        }else cout << "No"<<"\n";
    }
    return 0;
}
