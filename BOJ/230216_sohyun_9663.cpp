#include <iostream>

#define MAX 14
using namespace std;

int n;

int cnt = 0;

int queen_column[MAX];

bool can_go(int row){
    //전 행에 놓인 퀸들과 충돌하지 않는 지 => 그러므로 행의 중복 여부는 검사하지 않아도 된다.
    for(int i=0; i<row; ++i){
        if ((queen_column[i] == queen_column[row]) || (row - i == (abs(queen_column[row] - queen_column[i])))){
            return false;
        }
    }
    return true;
}

void nqueen(int row){

    // n번째 행까지 n개의 퀸을 놓는 하나의 경우의 수를 찾았다면, 함수 종료
    if (row == n){
        cnt++;
        return;
    }
    else{
        for (int col=0; col<n; ++col){//현재 행에서 모든 열에 대해 검사한다.
            queen_column[row] = col;
            // 현재 행, 열 위치가 퀸의 위치로 문제 없다면, 다음 행 검사
            if (can_go(row)){
                nqueen(row + 1);
            }
            // 현재 행, 열 위치가 퀸의 위치로 문제가 있다면, 다른 위치를 찾아본다.(행을 바꿔가며)
        }
    }
}

int main(void){
    cin >> n;
    nqueen(0);
    cout << cnt;
    return 0;
}
