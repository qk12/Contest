#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
set<int> S[maxn];
queue<int> q;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int u, v;
    while (m--)
    {
        scanf("%d%d", &u, &v);
        S[u].insert(v);
        S[v].insert(u);
    }
    for (int i = 1; i <= n; ++i)
        if (S[i].size() == 2)
            q.push(i);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        if (S[u].size() != 2)
            continue;
        int x = *S[u].begin();
        S[u].erase(S[u].begin());
        int y = *S[u].begin();
        S[u].erase(S[u].begin());
        S[x].erase(u), S[y].erase(u);
        S[x].insert(y), S[y].insert(x);
        if (S[x].size() == 2)
            q.push(x);
        if (S[y].size() == 2)
            q.push(y);
    }
    int cnt = 0;
    bool ok = true;
    for (int i = 1; i <= n; ++i)
    {
        if (S[i].size() == 1)
            ++cnt;
        if (S[i].size() >= 2)
            ok = false;
    }
    if (ok && cnt == 2)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}