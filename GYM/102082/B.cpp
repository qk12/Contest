#include <bits/stdc++.h>
using namespace std;

const int maxn = 5005;
int a[maxn];
set<int> s;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        s.insert(a[i]);
    }
    sort(a, a + n);
    int ans = 2;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int d = a[j] - a[i];
            int cnt = 2;
            if (!s.count(a[i] + ans * d)) //ans*d而不能是cnt*d，不然会超时
                continue;
            while (s.count(a[i] + cnt * d))
                ++cnt;
            ans = max(ans, cnt);
        }
    }
    printf("%d\n", ans);
    return 0;
}