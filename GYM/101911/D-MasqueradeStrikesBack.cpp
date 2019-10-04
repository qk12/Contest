#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> mp;

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> ans(n);
    for (int i = 0; i < n; ++i)
    {
        static int x;
        scanf("%d", &x);
        mp[x].push_back(i);
    }
    for (auto &it : mp)
    {
        int x = it.first;
        int m = it.second.size();
        int cnt = 0;
        for (int i = 1; i * i <= x; ++i)
            if (x % i == 0)
            {
                if (cnt < m)
                    ans[it.second[cnt++]] = {i, x / i};
                if (i != x / i && cnt < m)
                    ans[it.second[cnt++]] = {x / i, i};
            }
        if (cnt != m)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}