#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> test;
    if (info[0] == n) {
        answer.push_back(- 1);
        return answer;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n; j++) {
            test[i] = j;
        }
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> info;
    for (int i = 0; i < 10; i++) {
        cin >> info[i];
    }
    cout << '[';
    for (int i = 0; i < solution(n,info).size(); i++) {
        cout << solution(n, info)[i]<<' ';
    }
    cout << ']';
    return 0;
}
