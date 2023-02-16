#include <iostream>
#include <string>

using namespace std;

string video[64];

void recursive(int size, int y, int x)
{
    char curr = video[y][x];

    for (int i = y; i < y + size; i++)
        for (int j = x; j < x + size; j++)
            if (video[i][j] != curr)
            {
                cout << '(';
                recursive(size / 2, y, x);
                recursive(size / 2, y, x + size / 2);
                recursive(size / 2, y + size / 2, x);
                recursive(size / 2, y + size / 2, x + size / 2);
                cout << ')';
                return;
            }

    cout << curr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> video[i];

    recursive(N, 0, 0);

    return 0;
}
