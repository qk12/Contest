#include <bits/stdc++.h>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
typedef long long ll;
const int maxn = 2e5 + 10;
ll a[maxn], sum[maxn << 2]; //sum[i]表示区间[1,i]上的数的和
ll num[maxn << 2];          //num是区间上的数的出现次数
vector<ll> v;
inline int getid(ll x)
{
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
void pushup(int rt)
{
    sum[rt] = sum[lson] + sum[rson];
    num[rt] = num[lson] + num[rson];
}
void update(int x, int l, int r, int rt)
{
    if (l == r)
    {
        ++num[rt], sum[rt] += v[l - 1];
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m)
        update(x, Lson);
    else
        update(x, Rson);
    pushup(rt);
}
ll query(int x, int l, int r, int rt) //查询,在 <= x 的情况下,最多能保留多少个数字
{
    if (l == r) //区间范围为1(即只有一个数)的时候,返回能保留多少个这个数字
    {
        return x / v[l - 1];
    }
    int m = (l + r) >> 1;
    if (x > sum[lson]) //保留左子树上的所有数字,查询右子树
        return num[lson] + query(x - sum[lson], Rson);
    else //从左子树中找应该保留哪些数
        return query(x, Lson);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(sum, 0, sizeof(sum));
        memset(num, 0, sizeof(num));
        v.clear();
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld", a + i);
            v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int N = v.size();
        /*
        for (int i = 1; i <= n; i++)
            cout << getid(a[i]) << ' ';
        cout << endl;
        */
        for (int i = 1; i <= n; ++i)
        {
            ll ans = 0;
            //当 sum[1 ~ i-1]+a[i] <= m 时不查询
            if (sum[1] + a[i] > m)
                ans = i - 1 - query(m - a[i], 1, N, 1);
            update(getid(a[i]), 1, N, 1);
            printf("%lld ", ans); //PE?
        }
        printf("\n");
    }
    return 0;
}