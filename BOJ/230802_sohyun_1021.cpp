#include <iostream>
#include <deque>

using namespace std;

int main() {	

	deque <int> dq;

	int n,m;
	int left_cnt = 0, right_cnt = 0;
	int ans = 0;

	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	while (m--) {
		int num;
		cin >> num;

		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == num) {
				left_cnt = i;
				right_cnt = dq.size() - i;
				//break;
			}
		}

		if (left_cnt <= right_cnt) {
			while (true) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				}

				dq.push_back(dq.front());
				dq.pop_front();
				ans++;
			}
		}
		else {
			ans++;	
			while (true) {
				if (dq.back() == num) {
					dq.pop_back();
					break;
				}

				dq.push_front(dq.back());
				dq.pop_back();
				ans++;
			}
		}
	}

	cout << ans;
	return 0;
}
