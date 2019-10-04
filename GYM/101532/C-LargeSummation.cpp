#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int a[maxn];
struct node
{
    int num, id;
} b[maxn];
bool cmp(const node &x, const node &y)
{
    if (x.num == y.num)
        return x.id < y.id;
    return x.num < y.num;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            b[i].num = a[i], b[i].id = i;
        }
        sort(b + 1, b + 1 + n, cmp);
        for (int i = 1; i <= n; ++i)
        {
            int temp = (mod - a[i] - 1) % mod;
            int l = 1, r = n + 1;
            while (l < r)
            {
                int m = l + (r - l) / 2;
                if (b[m].num <= temp)
                    l = m + 1;
                else
                    r = m;
            }
            int res = (l == 1 ? n : l - 1);
            if (b[res].id == i)
            {
                if (res == 1)
                    res = n;
                else
                    --res;
            }
            //cout << res << ' ';
            if (i == n)
                printf("%d\n", (a[i] + b[res].num) % mod);
            else
                printf("%d ", (a[i] + b[res].num) % mod);
        }
    }
    return 0;
}