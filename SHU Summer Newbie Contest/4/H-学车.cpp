#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
vector<P> vec;

int main()
{
    int n;
    scanf("%d", &n);
    int l, r;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &l, &r);
        vec.emplace_back(l, 1);
        vec.emplace_back(r, -1);
    }
    sort(vec.begin(), vec.end());
    int ans = 0, cnt = 0;
    for (auto &i : vec)
    {
        cnt += i.second;
        ans = max(cnt, ans);
    }
    printf("%d\n", ans);
    return 0;
}