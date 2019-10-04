#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            g[i][j] = (gcd(a[i], a[j]) != 1);
    vector<int> bit;
    for (int i = 0; i < (1 << n); ++i)
    {
        bit.clear();
        for (int j = 0; j < n; ++j)
            if ((i >> j) & 1)
                bit.push_back(j);
        bool flag = true;
        for (auto &x : bit)
            for (auto &y : bit)
                flag &= g[x][y];
        if (flag)
            ans = max(__builtin_popcount(i), ans);
    }
    printf("%d\n", ans);
    return 0;
}