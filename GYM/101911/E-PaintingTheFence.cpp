#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
set<int> pos[maxn];
bool vis[maxn];
int ans[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        static int c;
        scanf("%d", &c);
        ans[i] = c;
        pos[c].insert(i); //用set记录每种颜色出现的所有位置，
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        static int c;
        scanf("%d", &c);
        if (vis[c] || pos[c].size() < 2)
        { //若一个数已经被改变过，再对它改变没有用
            vis[c] = true;
            continue;
        }
        int l = *pos[c].begin(), r = *pos[c].rbegin(); //左右位置
        for (int j = l + 1; j <= r - 1; ++j)
        {
            pos[ans[j]].erase(j); //删除中间要改变数字记录的位置
            if (vis[ans[j]] && pos[ans[j]].size() > 0)
            { //若发现当前位置已被改变过则直接跳到这个数的最右端，因为中间已经被删除了
                j = *pos[ans[j]].rbegin();
                pos[ans[i]].erase(j);
            }
        }
        vis[c] = true;
    }
    for (int i = 1; i < maxn; ++i)
    {
        if (vis[i] && pos[i].size() >= 2)
        {
            int l = *pos[i].begin(), r = *pos[i].rbegin();
            for (int j = l; j <= r; ++j)
            {
                ans[j] = i;
            }
        }
    }
    for (int i = 1; i < n; ++i)
        printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
    return 0;
}