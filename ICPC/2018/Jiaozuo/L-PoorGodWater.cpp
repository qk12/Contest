#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
const int mod = 1e9 + 7;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
mat mul(mat &A, mat &B)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); ++i)
        for (int k = 0; k < B.size(); ++k)
            if (A[i][k])
                for (int j = 0; j < B[0].size(); ++j)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod; //中间也要取模，不然会爆
    return C;
}
mat matpow(mat A, ll k)
{
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); ++i)
        B[i][i] = 1;
    for (; k; k >>= 1, A = mul(A, A))
        if (k & 1)
            B = mul(B, A);
    return B;
}

struct Trie
{
    int ch[maxn][3], f[maxn], val[maxn];
    int sz, rt;
    int newnode()
    {
        memset(ch[sz], -1, sizeof(ch[sz])), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    int idx(char c) { return c - 'A'; };
    void insert(const char *s) //插入模式串
    {
        int u = 0;
        for (int i = 0; s[i]; ++i)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1)
                ch[u][c] = newnode();
            u = ch[u][c];
        }
        ++val[u]; //字符串结尾
    }
    mat base;
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 3; ++c)
        {
            if (~ch[rt][c])
                f[ch[rt][c]] = rt, q.push(ch[rt][c]);
            else
                ch[rt][c] = rt;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            // val[u] |= val[f[u]]; // +=
            for (int c = 0; c < 3; ++c)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
        mat A(sz, vec(sz));
        for (int i = 0; i < sz; ++i)
            if (!val[i])
                for (int j = 0; j < 3; ++j)
                    if (!val[ch[i][j]])
                        ++A[i][ch[i][j]];
        base = A;
    }
    ll query(ll n)
    {
        mat A = matpow(base, n);
        ll ans = 0;
        for (int i = 0; i < sz; ++i)
            ans = (ans + A[0][i]) % mod;
        return ans;
    }
} ac;

int main()
{
    ac.init();
    ac.insert("AAA"), ac.insert("BBB"), ac.insert("CCC");
    ac.insert("ACB"), ac.insert("BCA"), ac.insert("CAC");
    ac.insert("CBC");
    ac.build();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll n;
        scanf("%lld", &n);
        printf("%lld\n", ac.query(n));
    }
    return 0;
}