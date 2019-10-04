#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;
const int maxn = 1e3 + 5;
set<P> points;
map<P, int> centers;
P a[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &a[i].first, &a[i].second);
        a[i].first *= 2, a[i].second *= 2; //确保为整数
        points.insert(a[i]);
    }
    if (n <= 2)
        printf("0\n");
    else
    { //两个点可以确定一个中心点
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                P center = {(a[i].first + a[j].first) / 2, (a[i].second + a[j].second) / 2};
                ++centers[center];
            }
        //对于中心点(x,y)，需要补上的点的个数为
        //n - 2*cnt[x][y] - (点(x,y)在原来的点集里出现的次数)
        int res = n;
        for (auto &i : centers)
        {
            int val = n - i.second * 2 - points.count(i.first);
            res = min(res, val);
        }
        printf("%d\n", res);
    }
    return 0;
}