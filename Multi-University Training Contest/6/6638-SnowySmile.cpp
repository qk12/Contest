#include <bits/stdc++.h>
using namespace std;
#define lson u * 2 + 1
#define rson u * 2 + 2
const int maxn = 2e3 + 10;
typedef long long ll;
typedef pair<int, ll> P;
struct node
{
    int x, y;
    ll w;
};
vector<int> vx, vy;
vector<P> v[maxn];
node a[maxn];
ll max_sub[maxn << 2], max_pre[maxn << 2], max_suf[maxn << 2], sum[maxn << 2];

int szx, szy, n;

inline void init1()
{
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());

    sort(vy.begin(), vy.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());

    szx = vx.size(), szy = vy.size();

    for (int i = 0; i < n; i++)
    {
        int fx = lower_bound(vx.begin(), vx.end(), a[i].x) - vx.begin();
        int fy = lower_bound(vy.begin(), vy.end(), a[i].y) - vy.begin();
        v[fx].push_back(P(fy, a[i].w));
    }
}

inline void pushup(int u)
{
    sum[u] = sum[lson] + sum[rson];
    max_pre[u] = max(sum[lson] + max_pre[rson], max_pre[lson]);
    max_suf[u] = max(sum[rson] + max_suf[lson], max_suf[rson]);
    max_sub[u] = max(max_sub[lson], max(max_sub[rson], max_suf[lson] + max_pre[rson]));
}

inline void update(int u, int L, int R, int p, ll w)
{
    if (L == R)
    {
        /*      printf("u = %d L = %d w = %d\n", u, L, w);

        printf("sum[u] = %d\n", sum[u]); */
        sum[u] += w;

        max_pre[u] += w;

        max_suf[u] += w;

        if (sum[u] > 0)
            max_sub[u] = sum[u];
        else
            max_sub[u] = 0;

        return;
    }
    int mid = L + R >> 1;

    if (p <= mid)
        update(lson, L, mid, p, w);
    else
        update(rson, mid + 1, R, p, w);

    pushup(u);
}
inline void init2()
{
    memset(sum, 0, sizeof(sum));
    memset(max_sub, 0, sizeof(max_sub));
    memset(max_pre, 0, sizeof(max_pre));
    memset(max_suf, 0, sizeof(max_suf));
}
int main()
{
    //  freopen("1005.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        vx.clear();
        vy.clear();
        for (int i = 0; i < n; i++)
        {
            v[i].clear();
            scanf("%d%d%lld", &a[i].x, &a[i].y, &a[i].w);
            vx.push_back(a[i].x);
            vy.push_back(a[i].y);
        }

        init1();
        init2();
        /* for (int i = 0; i < szx; i++){
            for (int j = 0; j < v[i].size(); j++)
            printf("%d/%d ", v[i][j].first, v[i][j].second);
            printf("\n");
        }*/

        ll ans = 0;

        for (int i = 0; i < szx; i++)
        {

            init2();
            for (int j = i; j < szx; j++)
            {

                int szv = v[j].size();

                for (int k = 0; k < szv; k++)
                {

                    P p = v[j][k];
                    update(0, 0, szy - 1, p.first, p.second);
                }

                ans = max(ans, max_sub[0]);
            }
            /*  puts("sum:\n");
            for (int j = 0; j < 10; j++)
                printf("%d ", sum[j]);
            printf("\n");
    puts("max_sub:\n");
            for (int j = 0; j < 10; j++)
                printf("%d ", max_sub[j]);
            printf("\n");
        puts("max_pre:\n");
            for (int j = 0; j < 10; j++)
                printf("%d ", max_pre[j]);
printf("\n");
puts("max_suf:\n");
            for (int j = 0; j < 10; j++)
                printf("%d ", max_suf[j]);
        printf("\n"); */
        }
        printf("%lld\n", ans);
    }
}