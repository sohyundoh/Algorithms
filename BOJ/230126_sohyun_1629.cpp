#include <iostream>
using namespace std;


long long multiply(long long a, long long b, long long c)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % c;

    long long tmp = multiply(a, b / 2, c);

    if (b % 2 == 0)
        return tmp * tmp % c;
    else
        return a * (tmp * tmp % c) % c;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    cin >> a >> b >> c;

    cout << multiply(a, b, c);
}
