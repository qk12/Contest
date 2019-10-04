#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;
struct node
{
    int num, id;
    int t;
} a[maxn];
bool cmp(node &x, node &y)
{
    return x.num < y.num;
}
bool cmp2(node &x, node &y)
{
    return x.id < y.id;
}
int main()
{
    int n;
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i].num);
        sum += (ll)a[i].num;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n - 1, cmp);
    for (int i = 1; i <= n - 1; ++i)
    {
        a[i].t = i;
        sum -= (ll)i;
    }
    sort(a + 1, a + 1 + n - 1, cmp2);
    for (int i = 1; i <= n - 1; ++i)
    {
        printf("%d ", a[i].t);
    }
    printf("%lld\n", sum);
    return 0;
}