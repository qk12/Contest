#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int a[maxn];
int n;
inline int getsum()
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= a[i];
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (getsum() == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    while (true)
    {
        int sum = getsum();
        for (int i = 0; i < n; ++i)
            if ((a[i] ^ sum) < a[i])
            {
                cout << i << " " << (a[i] - (a[i] ^ sum)) << endl;
                fflush(stdout);
                a[i] ^= sum;
                break;
            }
        bool flag = true;
        for (int i = 0; i < n; ++i)
            if (a[i])
            {
                flag = false;
                break;
            }
        if (flag)
            break;
        int id, val;
        cin >> id >> val;
        a[id] -= val;
    }
    return 0;
}