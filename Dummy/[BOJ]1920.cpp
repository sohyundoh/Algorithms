#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 //이분 탐색하는 함수 정의하기
void search_X(vector<int> a, int x, int start, int end) {
	if (start > end) cout<<'0'<<'Wn';
	int mid = (start + end) / 2;
	if (a[mid] == x) cout<<'1'<<'\n';
	else if (a[mid] < x) return search_X(a, x, mid + 1, end);
	else if (a[mid] > x) return search_X(a, x, start, mid - 1);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	vector<int> A;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}

	int start = 0;
	int end = N - 1;
	sort(A.begin(), A.end());

	cin >> M;
	int* X = (int*)malloc(sizeof(int) * M);
	//배열이 왜 안되는지 생각해보기 
	//여기서 오류 나는 듯
	/*vector<int> X;*/
	for (int i = 0; i < M; i++) {
		/*int x;
		cin >> x;
		X.push_back(x);*/
		cin >> X[i];
	}
	for (int i = 0; i < M; i++) {

		search_X(A, X[i], start, end);
	}
	//시간 초과 발생하는 이유
	//이분 탐색으로 구현해보기
	//for (int k = 0; k < M; k++) {
	//	int flag = 0;
	//	for (int i = 0; i < N; i++) {
	//		if (X[k] == A[i]) {
	//			flag = 1;
	//		}
	//	}
	//	cout << flag << '\n';
	//}
}
