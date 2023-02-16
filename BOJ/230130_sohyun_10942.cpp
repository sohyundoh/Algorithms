#include <iostream>
#define N_MAX 2001

using namespace std;
int input[N_MAX];
int dp[N_MAX][N_MAX] = {{0,}};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for(int i = 1; i<=N;i++){
        cin >> input[i];
        dp[i][i] = 1;
        if(i!=1 && input[i-1] == input[i]){
            dp[i-1][i] = 1;
        }
    }
    for(int i = 2; i<=N-1; i++){
        for(int j = 1; i+j<=N; j++){
            if(input[j] == input[i + j] && dp[j+1][i+j -1] == 1){
                dp[j][i+j] = 1;
            }
        }
    }
    int M;
    cin>> M;
    for(int i = 0; i< M ; i++){
        int s,e;
        cin >> s >> e;
        cout<<dp[s][e]<< "\n";
    }
    return 0;
}
