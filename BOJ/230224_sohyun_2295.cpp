#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int input[1000];
vector<int> sum;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> input[i];

    //두 수의 합 구하기
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            sum.push_back(input[i] + input[j]);

    sort(input, input + n); //입력 수열 정렬
    sort(sum.begin(), sum.end());   // 두 수의 합 벡터 정렬

    for(int i = n - 1; i >= 0; i--){    // input을 큰 값부터 확인하기 때문에 찾으면 바로 종료
        for(int j = i; j >= 0; j--){
            int a = input[i] - input[j];
            bool exist = binary_search(sum.begin(), sum.end(), a);  // 이분탐색 수행
            if(exist) {
                cout << input[i] << "\n";
                return 0;
            }
        }
    }
}
