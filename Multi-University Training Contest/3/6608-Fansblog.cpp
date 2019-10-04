#include <bits/stdc++.h>
using namespace std;

typedef __int128 ll;
const int maxn = 1e7 + 5;
int prime[665000];
bool is_prime[maxn];
void getPrime(int n)
{
    for (int i = 0; i <= n; ++i)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= n; ++j)
        {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}
bool isPrime(ll n)
{
    for (int i = 1; i <= prime[0] && 1LL * prime[i] * prime[i] <= n; ++i)
        if (n % prime[i] == 0)
            return false;
    return true;
}

ll mod;
ll mod_pow(ll x, ll n)
{
    ll res = 1;
    if (n == 0)
        return res %= mod;
    while (n > 0)
    {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod, n >>= 1;
    }
    return res;
}

void output(ll x)
{
    if (x < 0)
    {
        x = -x;
        putchar('-');
    }
    if (x > 9)
        output(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
    getPrime(1e7);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long temp;
        ll p, q;
        scanf("%lld", &temp);
        p = temp;
        mod = p;
        ll ans = p - 1;
        for (ll i = p - 1;; --i)
        {
            if (isPrime(i))
            {
                q = i;
                break;
            }
            ans = ans * mod_pow(i, p - 2) % mod;
        }
        output(ans);
        printf("\n");
    }
    return 0;
}