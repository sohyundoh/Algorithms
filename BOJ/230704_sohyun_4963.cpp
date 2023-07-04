#include <iostream>
#include <queue>

using namespace std;
int dx[] = {0, 0, 1, -1, 1, 1, -1 , -1};
int dy[] = {1,-1,0,0, - 1, 1 , 1, -1};

int solution(int w, int h){
    int island = 0;
    bool map[51][51] = {false, };
    //입력받기
    for(int i = 1; i<= w; i++){
        for(int j = 1; j<=h; j++){
            int i;
            cin >> i;
            if( i == 0){
                continue;
            }
            map[i][j] = true;
        }
    }
    //그래프 탐색

}
int main(){
    int w,h;
    cin >> w >> h;
    while(w != 0  && h!=0){
        cout << solution(w, h);
        cin >> w >> h;
    }
    return 0;
}
