#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct point
{
    ll x, y;
    point(ll a = 0, ll b = 0) { x = a, y = b; }
    point operator-(const point &b) const { return point(x - b.x, y - b.y); }
    // 叉积(以原点为基准)
    ll operator^(const point &b) const { return x * b.y - y * b.x; }
    //利用叉积按极角从小到大排序
    //叉积 = 0是指两向量平行（重合）
    //叉积 > 0，则向量a在向量b的顺时针方向（粗略的理解为在a在b的下方）
    //叉积 < 0，则向量a在向量b的逆时针方向（粗略的理解为在a在b的上方）
    point base() const //共线向量看作相同的元素，统一映射到x轴上方比较，否则共线向量
    {                  //会因为和其他向量的比较结果不同而被看做不同的向量
        if (x < 0 || (x == 0 && y < 0))
            return point(-x, -y);
        return *this;
    }
    bool operator<(const point &b) const
    {
        point p1 = base(), p2 = b.base();
        return (p1 ^ p2) > 0;
    }
};

const int maxn = 2005;
point p[maxn], a[maxn];
int ans[maxn];
map<point, int> mp;

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", &p[i].x, &p[i].y);
    for (int i = 1; i <= q; ++i)
    {
        int res = 0;
        scanf("%lld%lld", &a[i].x, &a[i].y);
        //如果A是直角顶点，对n个点关于A做一个极角排序
        for (int j = 1; j <= n; ++j)
            ++mp[p[j] - a[i]];
        //统计有多少个点对(B,C)，使得AB垂直AC
        point temp;
        for (auto &it : mp)
        { //点乘为0说明是直角
            temp = point(-it.first.y, it.first.x);
            if (mp.count(temp))
                res += mp[temp] * it.second;
        }
        ans[i] = res / 2;
        mp.clear();
    }
    //如果A不是直角顶点，考虑离线做法，枚举n个给定点
    for (int i = 1; i <= n; ++i)
    {
        //对于每个给定点B，将其他n+q-1个点关于B进行极角排序
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                continue;
            ++mp[p[j] - p[i]];
        }
        point temp;
        for (int j = 1; j <= q; ++j)
        {
            temp = a[j] - p[i];
            temp = point(-temp.y, temp.x);
            if (mp.count(temp))
                ans[j] += mp[temp];
        }
        mp.clear();
    }
    for (int i = 1; i <= q; ++i)
        printf("%d\n", ans[i]);
    return 0;
}