#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
struct team
{
    char name[15];
    int p, t;
} a[maxn];

bool cmp(const team &x, const team &y)
{
    if (x.p == y.p)
        return x.t < y.t;
    else
        return x.p > y.p;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, d;
        scanf("%d%d", &n, &d);
        for (int i = 0; i < n; ++i)
        {
            scanf("%s%d%d", a[i].name, &a[i].p, &a[i].t);
        }
        sort(a, a + n, cmp);
        int res = n * d % 10;
        if (res == 5)
        {
            int i = n * d / 10;
            printf("%s\n", a[i].name);
        }
        else
            printf("Quailty is very great\n");
    }
    return 0;
}