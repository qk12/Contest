#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
int num[maxn];
int n, t;
bool vis[3605];
int cnt[3605];
void bfs()
{
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < n; ++i)
        {
            int val = min(3600, max(0, cur + num[i]));
            if (!vis[val])
            {
                q.push(val);
                vis[val] = true;
                cnt[val] = cnt[cur] + 1;
            }
        }
    }
    for (int i = t; i < 3601; ++i)
    {
        if (vis[i])
        {
            printf("%d %d\n", cnt[i], i - t);
            break;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i)
        scanf("%d", &num[i]);
    bfs();
    return 0;
}