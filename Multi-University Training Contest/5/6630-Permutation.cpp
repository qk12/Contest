#include <bits/stdc++.h>
#define mo 998244353
long long mem[100005];
long long get(long long n)
{
    if (mem[n] != -1)
        return mem[n];
    if (n <= 3)
        return 1;
    mem[n] = get(n - 1) + get(n - 3);
    return mem[n];
}
int main()
{
    int T;
    scanf("%d", &T);

    mem[1] = mem[2] = mem[3] = 1;
    for (int i = 4; i < 100004; i++)
        mem[i] = (mem[i - 1] + mem[i - 3]) % mo;
    while (T--)
    {
        long long n, x, y;
        scanf("%lld%lld%lld", &n, &x, &y);
        if (x == y - 1)
        {
            if (x == 1 || y == n)
            {
                printf("1\n");
                continue;
            }
            else
            {
                printf("0\n");
                continue;
            }
        }
        if (x != 1)
            x = x + 1;
        if (y != n)
            y = y - 1;
        printf("%lld\n", mem[y - x + 1]);
    }
    return 0;
}