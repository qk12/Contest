#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e5 + 5;
int ans[maxn];
struct node
{
    int w, id;
} a[maxn];
bool cmp(const node &a, node &b)
{
    if (a.w == b.w)
        return a.id > b.id;
    return a.w > b.w;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i].w);
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    int head = 1, maxx = -1;
    for (int i = 1; i <= n; ++i)
    {
        while (a[head].w - m >= a[i].w)
            maxx = max(maxx, a[head].id), ++head;
        if (maxx == -1)
            ans[a[i].id] = -1;
        else if (maxx > a[i].id)
            ans[a[i].id] = maxx - a[i].id - 1;
        else
            ans[a[i].id] = -1;
    }
    for (int i = 1; i <= n - 1; ++i)
        printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
    return 0;
}