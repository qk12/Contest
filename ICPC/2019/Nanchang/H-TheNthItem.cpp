#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
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
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
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
mat A(2, vec(2));
void init()
{
    A[0][0] = 3, A[0][1] = 2;
    A[1][0] = 1, A[1][1] = 0;
}
unordered_map<ll, int> mp;

int main()
{
    init();
    ll q, n;
    scanf("%lld%lld", &q, &n);
    ll ans = 0, res;
    mat c;
    while (q--)
    {
        if (mp.count(n))
            res = mp[n];
        else
        {
            c = matpow(A, n - 1);
            res = mp[n] = c[0][0];
        }
        ans ^= res;
        n = n ^ (res * res);
    }
    printf("%lld\n", ans);
    return 0;
}