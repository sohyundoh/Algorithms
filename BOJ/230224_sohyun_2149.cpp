#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<char, int>> v;
char answer[102][102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

    string key, encrypt;
    cin >> key >> encrypt;

    int row = encrypt.length() / key.length();
    for(int i = 0; i< key.length(); i++){
        v.push_back({key[i], i});
    }

    sort(v.begin(), v.end());
    
    for(int i = 0; i<key.length(); i++){
        for(int j = 0; j<row; j++){
            answer[v[i].second][j] = encrypt[i*row + j];
        }
    }
    
    for(int i = 0; i<row ; i++){
        for(int j = 0; j<key.length(); j++){
            cout<< answer[j][i];
        }
    }
}
