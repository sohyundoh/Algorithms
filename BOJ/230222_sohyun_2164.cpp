#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    deque<int> card;

    for (int i = 1; i <= n; i++) {
        card.push_back(i);
    }
    while (card.size() != 1) {
        card.pop_front();
        int temp = card.front();
        card.pop_front();
        card.push_back(temp);
    }
    cout << card[0];
    return 0;
}
