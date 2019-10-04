#include <bits/stdc++.h>
using namespace std;

int a[26];
char s[25];
int n;

int solve(int n, int m)
{
    int temp1 = 1, temp2 = 1;
    for (int i = n - m + 1; i <= n; ++i)
        temp1 *= i;
    for (int i = 1; i <= m; ++i)
        temp2 *= i;
    return temp1 / temp2;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%s", &n, s);
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; ++i)
            ++a[s[i] - 'a'];
        int cnt = 0, id = 0;
        for (int i = 0; i < 26; ++i)
            if (a[i] % 2 == 1)
            {
                id = i;
                ++cnt;
            }
        if (cnt != (n % 2))
        {
            printf("0\n");
            continue;
        }
        if (n % 2 == 1)
            --a[id];
        int res = 1, sum = n / 2;
        for (int i = 0; i < 26; ++i)
        {
            if (a[i] != 0)
            {
                res *= solve(sum, a[i] / 2);
                sum -= a[i] / 2;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}