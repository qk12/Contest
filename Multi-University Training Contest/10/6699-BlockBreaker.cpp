#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e3 + 5;
bool vis[maxn][maxn];
int n, m, q;
struct node
{
    int x, y;
};
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
inline bool check(int a, int b)
{
    return 1 <= a && a <= n && 1 <= b && b <= m;
}
bool ok(int x, int y)
{
    if ((x + 1 > n || !vis[x + 1][y]) && (x - 1 <= 0 || !vis[x - 1][y]))
        return false;
    if ((y + 1 > m || !vis[x][y + 1]) && (y - 1 <= 0 || !vis[x][y - 1]))
        return false;
    return true;
}

int solve(int x, int y)
{
    if (vis[x][y])
        return 0;
    int sum = 1;
    vis[x][y] = true;
    node s{x, y};
    queue<node> q;
    q.push(s);
    while (!q.empty())
    {
        node temp = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            s.x = temp.x + dir[i][0], s.y = temp.y + dir[i][1];
            if (check(s.x, s.y) && !vis[s.x][s.y] && ok(s.x, s.y))
            {
                ++sum;
                q.push(s);
                vis[s.x][s.y] = true;
            }
        }
    }
    return sum;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &q);
        memset(vis, 0, sizeof(vis));
        int x, y;
        for (int i = 0; i < q; ++i)
        {
            scanf("%d%d", &x, &y);
            printf("%d\n", solve(x, y));
        }
    }
    return 0;
}