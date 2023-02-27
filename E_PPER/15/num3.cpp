#include <iostream>
using namespace std;
int solution(int N, int M){
	int cnt = 0;
	int notebook = N;
	while(1){
		for(int i = 0; i< M ; i++){
			if(notebook == 0) return cnt;
			cnt ++;
			notebook --;
		}
		notebook ++;
	}	
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	cout << solution(N, M);
	return 0;
}
