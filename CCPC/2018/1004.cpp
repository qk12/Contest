// 费马大定理和奇偶数列法则

#include <cstdio>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    ll n, a, b, c;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &a);
        if (n > 2 || n == 0)
        {
            b = c = -1;
        }
        else if (n == 1)
        {
            b = 1, c = a + 1;
        }
        else if (a & 1)
        {
            ll k = a / 2;
            b = k * k + (k + 1) * (k + 1) - 1, c = b + 1;
        }
        else
        {
            ll k = a / 2;
            b = k * k - 1, c = b + 2;
        }
        printf("%lld %lld\n", b, c);
    }
    return 0;
}