#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn * 2];
bool vis[maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = n; i >= 1; --i)
    {
        scanf("%d", &a[i]);
        vis[i] = false;
    }
    for (int i = n + 1; i <= n + m; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = n + m; i >= 1; --i)
    {
        if (!vis[a[i]])
        { //There should be one space after each number
            printf("%d ", a[i]);
        }
        vis[a[i]] = true;
    }
    // printf("\n");  Presentation Error ?
    return 0;
}