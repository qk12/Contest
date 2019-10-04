#include <cstdio>
#include <queue>
#include <vector>
#define MAXN 51234
using namespace std;
typedef long long ll;
typedef pair<ll, int> pq_e;
typedef priority_queue<pq_e, vector<pq_e>, greater<pq_e>> pq_t;
typedef vector<pq_e> edges_t;
typedef vector<ll> ans_t;
pq_t pq;
edges_t edges[MAXN];
ll ans[MAXN];
int ks[MAXN];
ll mx;
const bool dbg = true;
int main()
{
    int T;
    scanf("%d", &T);
    int u, v;
    ll dis;
    int n, m, q;
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &q);
        pq = pq_t();
        mx = 0;
        for (int i = 1; i <= n; i++)
            edges[i].clear();
        //ans=ans_t();
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%lld", &u, &v, &dis);
            edges[u].push_back(pq_e(dis, v));
        }
        for (int i = 1; i <= n; i++)
            pq.push(pq_e(0ll, i));
        int anssize = 0;
        int mxk = 0;
        for (int iq = 0; iq < q; iq++)
        {
            scanf("%d", &ks[iq]);
            mxk = max(mxk, ks[iq]);
        }
        for (int iq = 0; iq < q; iq++)
        {
            int k;
            k = ks[iq];

            while (anssize < k)
            {
                int u = pq.top().second;
                ll u_dis = pq.top().first;
                mx = max(mx, u_dis);
                pq.pop();
                if (u_dis != 0)
                    ans[anssize++] = u_dis;
                for (int i = 0; i < edges[u].size(); i++)
                {
                    int v = edges[u][i].second;
                    ll v_dis = edges[u][i].first + u_dis;
                    if (v_dis > mx && (pq.size() > (mxk + 5 - anssize)))
                        continue;
                    if (dbg)
                        printf("\t\tu %d dis %lld->v %d dis %lld\n", u, u_dis, v, v_dis);
                    mx = max(mx, v_dis);
                    pq.push(pq_e(v_dis, v));
                }
            }
            printf("%lld\n", ans[k - 1]);
        }
        if (dbg)
            for (int i = 0; i < anssize; i++)
            {
                printf("%lld ", ans[i]);
            }
    }
}
