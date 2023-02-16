#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define max_num 1000 + 1 

int cmp(const string& A, const string& B ) {
    int A_size = A.size(), B_size = B.size();
    if (A_size != B_size) return A_size < B_size;

    int A_sum = 0, B_sum = 0;
    for (int i= 0; i < A_size; i++) {
        if (isdigit(A[i]))   A_sum += A[i] - '0';
        if (isdigit(B[i]))   B_sum += B[i] - '0';
    }
    if (A_sum != B_sum) return A_sum < B_sum;

    return A < B;
}

int main() {
    int n;
    cin >> n;
    string str[max_num];
    for (int j = 0; j < n; j++)
        cin >> str[j];
    sort(str, str + n, cmp);

    for (int l = 0; l < n; l++)
        cout << str[l] << "\n";
    return 0;
}
