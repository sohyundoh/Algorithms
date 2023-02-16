#include <iostream>

using namespace std;
int N, white, blue;
int arr[129][129];

void recursive(int x, int y, int len){
    int color = arr[x][y];
    
    for(int i = x; i< x+ len; i++){
        for(int j = y; j< y+ len; j++){
            if(color != arr[i][j]){
                recursive(x, y, len/2);
                recursive(x, y+ len/2, len/2);
                recursive(x+len/2,y,len/2);
                recursive(x+len/2, y+len/2, len/2);
                return;
            }
        }
    }
    if(color == 1) blue++;
    else white ++;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N;j++){
            cin >> arr[i][j];
        }
    }
    
    recursive(0,0,N):
    cout<< white << "\n" << blue;
    return 0;
}
