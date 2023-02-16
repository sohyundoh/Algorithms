#include <iostream>
#include <vector>

using namespace std;

/*
 * 230111_sohyun_15649.cpp
 * N과 M(1) - silver3 (백트래킹)
 */
vector<vector<int>> arrofArr;

bool contains(vector<int> vec, int elem) {
    bool result = false;
    if (find(vec.begin(), vec.end(), elem) != vec.end()) {
        result = true;
    }
    return result;
}

void make_array(int n, int N, int m) {
    for (int i = 0; i < N; i++) {
        vector<int> arr;
        arr.push_back(n);
        for (int j = 0; j < m; j++) {
            if(contains(arr, i+ j) || i+j == 0) continue;
            arr.push_back(i+ j);
        }
        if(arr.size() != m) continue;
        arrofArr.push_back(arr);
    }
}

void print_array(int N, int M) {
    for (int i = 0; i < N * (N - M + 1) + 1; i++) {
        for (int j = 0; j < M; j++) {
            cout << arrofArr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int N, M;
    for (int i = 1; i <= 4; i++) {
        make_array(i, 4, 4);
    }
    print_array(4, 4);
    return 0;
}
