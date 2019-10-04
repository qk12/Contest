#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e7 + 5;
deque<int> que;
int ans[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        while (!que.empty())
            que.pop_back();
        for (int i = n; i >= 2; --i)
        {
            que.push_front(i);
            for (int j = 0; j < m; ++j)
            {
                int x = que.back();
                que.pop_back();
                que.push_front(x);
            }
        }
        que.push_front(1);
        for (int i = 0; i < n; ++i)
        {
            ans[i] = que.front();
            que.pop_front();
        }
        while (q--)
        {
            int x;
            scanf("%d", &x);
            printf("%d\n", ans[x - 1]);
        }
    }
    return 0;
}