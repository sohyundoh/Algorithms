#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int t;
vector<int> va, vb;

int ft_sort(int a, int target, int blen)
{
    if (target == blen)
        return 0;
    if (vb[target] < a) 
        return blen - target;
    else
        return (ft_sort(a, target + 1, blen));
    return (0);
}

int main(void)
{
    fast_io();
    cin >> t;
    while (t--)
    {
        int a, b, res = 0;
        cin >> a >> b;
        va.resize(a);
        vb.resize(b);
        for (int i = 0; i < a; i++)
            cin >> va[i];
        for (int i = 0; i < b; i++)
            cin >> vb[i];
        sort(va.rbegin(), va.rend());
        sort(vb.rbegin(), vb.rend());
        for (int i = 0; i < a; i++)
            res += ft_sort(va[i], 0, b);
        cout << res<< "\n";
        va.clear();
        vb.clear();
    }
}
