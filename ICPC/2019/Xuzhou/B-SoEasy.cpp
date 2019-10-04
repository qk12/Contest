#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> fa;
int find(int x)
{
    if (!fa.count(x))
        return x;
    return fa[x] = find(fa[x]);
}
void unite(int x)
{
    int xx = find(x), yy = find(x + 1);
    fa[xx] = yy;
}
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    while (q--)
    {
        int op, x;
        scanf("%d%d", &op, &x);
        if (op == 1)
            unite(x);
        else
        {
            if (!fa.count(x))
                printf("%d\n", x);
            else
                printf("%d\n", find(x));
        }
    }
    return 0;
}
