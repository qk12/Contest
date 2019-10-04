/*
如果做不出k题，那么也就是复习时间最少的 n−k+1 道题的难度都小于等于复习的时间。
因此想要做出 k 题，只要让复习时间最少的 n−k+1 道题的复习时间总和 >m 即可。
也就是 n−k+1 道题的复习时间总和为 m+1，剩下 k−1 道题的复习时间不是
最少的 k−1 道题即可
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n, m, k;
        scanf("%lld%lld%lld", &n, &m, &k);
        ll ans = m + 1 + (m / (n - k + 1) + 1) * (k - 1);
        printf("%lld\n", ans);
    }
    return 0;
}