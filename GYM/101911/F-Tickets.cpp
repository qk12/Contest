#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int ans[maxn], cnt[30];

int main()
{
    for (int i = 0; i < maxn; ++i)
    {
        int a = i % 10 + (i / 10) % 10 + (i / 100) % 10;
        int b = (i / 1000) % 10 + (i / 10000) % 10 + (i / 100000) % 10;
        int res = abs(a - b);
        int temp = 0;
        for (int j = res - 1; j >= 0; --j)
            temp += cnt[j];
        ans[i] = temp;
        ++cnt[res];
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        static int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    return 0;
}
