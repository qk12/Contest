#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;
struct SAM
{
    int len[maxn << 1], link[maxn << 1], ch[maxn << 1][26];
    int sz, rt, last;
    int newnode(int x = 0)
    {
        len[sz] = x;
        link[sz] = -1;
        memset(ch[sz], -1, sizeof(ch[sz]));
        return sz++;
    }
    void init() { sz = last = 0, rt = newnode(); }
    void reset() { last = 0; }
    void extend(int c)
    {
        int np = newnode(len[last] + 1);
        int p = last;
        while (p != -1 && ch[p][c] == -1)
            ch[p][c] = np, p = link[p];
        if (p == -1)
            link[np] = rt;
        else
        {
            int q = ch[p][c];
            if (len[p] + 1 == len[q])
                link[np] = q;
            else
            {
                int nq = newnode(len[p] + 1);
                memcpy(ch[nq], ch[q], sizeof(ch[q]));
                link[nq] = link[q], link[q] = link[np] = nq;
                while (p != -1 && ch[p][c] == q)
                    ch[p][c] = nq, p = link[p];
            }
        }
        last = np;
    }
    ll dp[maxn];
    void solve(const char *s, int p, int q)
    {
        extend(s[0] - 'a');
        int u = ch[rt][s[0] - 'a'];
        dp[0] = p;
        for (int i = 1, j = 0; s[i]; ++i)
        {
            dp[i] = dp[i - 1] + p;
            while (true)
            {
                while (u != rt && len[link[u]] >= i - j - 1)
                    u = link[u];
                if (~ch[u][s[i] - 'a'])
                {
                    u = ch[u][s[i] - 'a'];
                    break;
                }
                else
                    extend(s[++j] - 'a');
            }
            dp[i] = min(dp[i], dp[j] + q);
        }
        int n = strlen(s);
        printf("%lld\n", dp[n - 1]);
    }
} sam;

char s[maxn];

int main()
{
    ll p, q;
    while (~scanf("%s", s))
    {
        sam.init();
        scanf("%lld%lld", &p, &q);
        sam.solve(s, p, q);
    }
    return 0;
}
