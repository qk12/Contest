#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int kmp[maxn];
int x[maxn];
void initkmp(int m)
{
    int i = 0, pos = kmp[0] = -1;
    while (i < m)
    {
        while (pos != -1 && x[i] != x[pos])
            pos = kmp[pos];
        kmp[++i] = ++pos;
    }
}

int main()
{
    int m;
    scanf("%d", &m);
    for (int i = m - 1; i >= 0; --i)
        scanf("%d", &x[i]);
    initkmp(m);
    int ans = -1;
    for (int i = m; i >= 2; --i)
        if (kmp[i] != 0 && i % (i - kmp[i]) == 0)
        {
            ans = (i - kmp[i]);
            break;
        }
    printf("%d\n", ans);
    return 0;
}