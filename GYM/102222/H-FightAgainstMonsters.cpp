#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
struct monster
{
    ll hp, atk;
    double rate;
} a[maxn];
bool cmp(const monster &x, const monster &y)
{
    return x.rate > y.rate;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k)
    {
        int n;
        scanf("%d", &n);
        ll sum = 0, ans = 0;
        for (int i = 0; i < n; ++i)
        {
            double u;
            scanf("%lf%lld", &u, &a[i].atk);
            // x <= (1+n)*n/2 æ±‚æ ¹å…¬å¼�
            a[i].hp = (ll)ceil((sqrt(8 * u + 1) - 1) / 2);
            sum += a[i].atk;
            a[i].rate = (1.0 * a[i].atk) / (1.0 * a[i].hp);
        }
        sort(a, a + n, cmp);
        for (int i = 0; i < n; ++i)
        {
            ans += sum * a[i].hp;
            sum -= a[i].atk;
        }
        printf("Case #%d: %lld\n", k, ans);
    }
    return 0;
}