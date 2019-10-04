#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int nxt[maxn][26];
int now[26];
void init(char s[], int len)
{
    memset(now, -1, sizeof(now));
    for (int i = len; i >= 0; --i)
    {
        for (int j = 0; j < 26; ++j)
            nxt[i][j] = now[j];
        now[s[i] - 'a'] = i;
    }
}
char s[maxn], t[maxn];
int n, m;

int main()
{
    scanf("%d%d%s%s", &n, &m, s + 1, t + 1);
    init(s, n);
    int res = -1, cur = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = t[i] - 'a' + 1; j < 26; ++j)
        {
            int pos = nxt[cur][j];
            if (pos != -1)
                res = max(res, (i - 1) + (n - pos + 1));
        }
        cur = nxt[cur][t[i] - 'a'];
        if (cur == -1)
            break;
    }
    if (cur != -1 && cur != n)
        res = max(res, m + (n - cur));
    printf("%d\n", res);
    return 0;
}