#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 2e6 + 5;
ll base[maxn], res[maxn];
struct Palindromic_Tree
{
    int ch[maxn][10], f[maxn], len[maxn], s[maxn];
    int last, sz, n;
    ll ans = 0;
    int newnode(int x)
    {
        memset(ch[sz], 0, sizeof(ch[sz]));
        len[sz] = x;
        return sz++;
    }
    void init()
    {
        sz = 0;
        newnode(0), newnode(-1);
        last = n = 0, s[0] = -1, f[0] = 1;
    }
    int get_fail(int u)
    {
        while (s[n - len[u] - 1] != s[n])
            u = f[u];
        return u;
    }
    void add(int c, int pos)
    { // c-='a'
        s[++n] = c;
        int u = get_fail(last);
        if (!ch[u][c])
        {
            int np = newnode(len[u] + 2);
            ans = (ans + (res[pos] - res[pos - len[np]] * base[len[np]] % mod + mod)) % mod;
            f[np] = ch[get_fail(f[u])][c];
            ch[u][c] = np;
        }
        last = ch[u][c];
    }
    ll query()
    {
        return ans;
    }
} pam;

char s[maxn];
int main()
{
    scanf("%s", s);
    int len = strlen(s);
    base[0] = 1, res[0] = s[0] - '0';
    for (int i = 1; i < len; ++i)
    {
        base[i] = base[i - 1] * 10 % mod;
        res[i] = (res[i - 1] * 10 % mod + (s[i] - '0')) % mod;
    }
    pam.init();
    for (int i = 0; i < len; ++i)
        pam.add(s[i] - '0', i);
    printf("%lld\n", pam.query());
    return 0;
}