#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int max_v = 1e5 + 5;
int father[max_v];
void init(int n)
{
    for (int i = 1; i <= n; ++i)
        father[i] = i;
}
int find(int x)
{
    if (father[x] != x)
        father[x] = find(father[x]);
    return father[x];
}
void unite(int x, int y)
{
    x = find(x), y = find(y);
    father[x] = y;
}
bool same(int x, int y) { return find(x) == find(y); }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    int q, u, v;
    int ans = n - 1;
    while (m--)
    {
        scanf("%d", &q);
        if (q == 1)
        {
            scanf("%d%d", &u, &v);
            if (!same(u, v))
            {
                unite(u, v);
                --ans;
            }
        }
        else if (q == 0)
            printf("%d\n", ans);
    }
    return 0;
}
