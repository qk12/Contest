#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn];
int ans[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    stack<int> s;
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && a[s.top()] < a[i])
        {
            ans[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    for (int i = 1; i <= n; ++i)
        if (i == 1)
            printf("%d", ans[i]);
        else
            printf(" %d", ans[i]);
    printf("\n");
    return 0;
}
