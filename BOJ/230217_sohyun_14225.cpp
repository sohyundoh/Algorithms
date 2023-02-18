#include <iostream>
#include <vector>
#include <algorithm>
#define N_MAX 20

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    vector<int> input;

    for(int i = 0; i< N; i++){
        int in;
        cin >> in;
        input.push_back(in);
//        int k = sum.size();
//        for(int j = 0; j < k; j++){
//            sum.push_back(input[i] + sum[j]);
//           cout <<i << " " << input[i] + sum[j]<<"\n";
//        }
//        sum.push_back(input[i]);
    }
    sort(input.begin(),input.end());
    int answer = 0;
    for(int i = 0; i<N; i++){
        if(input[i] - answer > 1) {
            cout << answer + 1;
            return 0;
        }
        answer += input[i];
    }
    cout<< answer+1;
    return 0;
}
