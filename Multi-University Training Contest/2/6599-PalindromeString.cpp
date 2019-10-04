#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5 + 5;
char s[maxn], Ma[maxn << 1];
int Len[maxn << 1];
void Manacher(char s[], int lens)
{
    int pos = 0;
    Ma[pos++] = '$';
    Ma[pos++] = '#';
    for (int i = 0; i < lens; ++i)
        Ma[pos++] = s[i], Ma[pos++] = '#';
    Ma[pos] = 0;
    int mx = 0, mid = 0;
    for (int i = 0; i < pos; ++i)
    {
        Len[i] = (i < mx) ? min(Len[mid * 2 - i], mx - i) : 1;
        while (Ma[i + Len[i]] == Ma[i - Len[i]])
            ++Len[i];
        if (Len[i] + i > mx)
            mx = Len[i] + i, mid = i;
    }
}

struct Palindromic_Tree
{ //len[i]表示节点i表示的回文串长度
    int ch[maxn][26], f[maxn], len[maxn], s[maxn];
    ll cnt[maxn];    // 结点表示的本质不同的回文串的个数(调用count()后)
    int num[maxn];   // 结点表示的最长回文串的最右端点为回文串结尾的回文串个数
    int last, sz, n; //last指向上一个字符所在节点、节点指针、字符数组指针
    int newnode(int x)
    {
        memset(ch[sz], 0, sizeof(ch[sz]));
        cnt[sz] = num[sz] = 0, len[sz] = x;
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
    int begin[maxn], end[maxn];
    void add(int c)
    { // c-='a'
        s[++n] = c;
        int u = get_fail(last); //通过上一个回文串找这个回文串的匹配位置
        if (!ch[u][c])          //如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
        {
            int np = newnode(len[u] + 2);
            f[np] = ch[get_fail(f[u])][c]; //和AC自动机一样建立fail指针，以便失配后跳转
            num[np] = num[f[np]] + 1;
            ch[u][c] = np;
        }
        last = ch[u][c];
        end[last] = n;
        begin[last] = end[last] - len[last] + 1;
        ++cnt[last];
    }
    void count() //父亲累加儿子的cnt，因为如果fail[v]=u，则u一定是v的子回文串！
    {
        for (int i = sz - 1; i >= 0; --i)
            cnt[f[i]] += cnt[i];
    }
    bool check(int l, int r)
    {
        int m = (l + r) / 2;
        return Len[l + m] >= m - l + 1;
    }
    ll ans[maxn];
    void solve()
    {
        for (int i = 1; i <= n; ++i)
            ans[i] = 0;
        for (int i = 0; i < sz; ++i)
            if (len[i] > 0)
                ans[len[i]] += check(begin[i], end[i]) * cnt[i];
        for (int i = 1; i <= n; ++i)
            printf("%lld%c", ans[i], " \n"[i == n]);
    }
} pam;

int main()
{
    while (scanf("%s", s) != EOF)
    {
        pam.init();
        int n = strlen(s);
        Manacher(s, n);
        for (int i = 0; i < n; ++i)
            pam.add(s[i] - 'a');
        pam.count();
        pam.solve();
    }
    return 0;
}