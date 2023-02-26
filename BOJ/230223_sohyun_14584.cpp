#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string c;
    cin >> c;

    int k = 0;
    cin >> k;

    string word[20];
    for(int i = 0; i<k; i++){
        cin >> word[i];
    }
    for (int i = 0; i < 25; i++) {
        for(int j = 0; j< k; j++){
            if(c.find(word[j]) != string::npos){
                cout<< c;
                return 0;
            }
        }
        for(int m = 0; m<c.length();m++){ //한칸씩 밀기
            c[m] = (c.at(m) - 'a' + 1)%26 + 'a';
        }
    }
    return 0;
}
