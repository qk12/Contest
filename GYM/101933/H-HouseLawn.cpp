#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
char name[maxn][maxn];
ll p[maxn], c[maxn], t[maxn], r[maxn];
bool vis[maxn];

int main()
{
    ll l, m;
    scanf("%lld%lld", &l, &m);
    char ch;
    ll ans = INF;
    for (int i = 1; i <= m; ++i)
    {
        int cnt = 0;
        scanf(" %c", &ch); //前面可能有空格，坑！
        while (ch != ',')
        {
            name[i][cnt++] = ch;
            ch = getchar();
        }
        scanf("%lld,%lld,%lld,%lld", &p[i], &c[i], &t[i], &r[i]);
        getchar();
        double temp = t[i] * c[i];
        double T = 10080.0 / (double)(t[i] + r[i]) * temp;
        if (T >= (double)l)
        {
            ans = min(ans, p[i]);
            vis[i] = true;
        }
    }
    if (ans == INF)
        printf("no such mower\n");
    else
    {
        for (int i = 1; i <= m; ++i)
            if (p[i] == ans && vis[i])
                printf("%s\n", name[i]);
    }
    return 0;
}