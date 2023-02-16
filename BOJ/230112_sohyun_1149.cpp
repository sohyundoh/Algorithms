#include <iostream>
#define MAX 1000
#define COLORS 3
using namespace std;

int dp[MAX][COLORS] = {{0,0,0}}; // 총 비용 저장하는 배열
//각각 색깔 비용 저장 배열
int color[MAX][COLORS] = {{0,0,0}};
int MIN(int a, int b){
    return (a >= b)? b: a;
}
int MIN_FINAL(int final[]){
    int temp = final[0];
    if(temp >= final[1]) temp = final[1];
    if(temp >= final[2]) temp = final[2];
    return temp;
}
int max_func(int N){
    for(int i = 0; i<COLORS;i++) { //초기화
        dp[0][i] = color[0][i];
    }
    for(int i = 1; i<N ; i++){
        for(int j = 0; j<COLORS;j++){
            dp[i][j]= MIN(dp[i-1][(j+1)%COLORS]+ color[i][j], dp[i-1][(j+2)%COLORS]+ color[i][j]);
        }
    }
    return MIN_FINAL(dp[N-1]);
}
int main(){
    int N;
    cin >> N;
    for(int i = 0; i<N;i++){
        cin >> color[i][0]>> color[i][1] >>color[i][2];
    }
    cout << max_func(N);
    return 0;
}
