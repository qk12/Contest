#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> P;
const int maxn = 1e5 + 10;
P a[maxn];
vector<P> u, d, l, r;
vector<int> vx, vy;
priority_queue<P, vector<P>, greater<P>> U, L, R;
priority_queue<P, vector<P>, less<P>> D, _L, _R;
int n, m, k, bitl[maxn], bitr[maxn], ans;

inline int lowbit(int x) { return x & (-x); }

int fx(int x) { return lower_bound(vx.begin(), vx.end(), x) - vx.begin(); }

int fy(int x) { return lower_bound(vy.begin(), vy.end(), x) - vy.begin(); }

void add_L(int x, int k)
{
    for (int i = x; i <= n + 1; i += lowbit(i))
        bitl[i] += k;
}

int getL(int x)
{
    int res = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        res += bitl[i];
    return res;
}

void add_R(int x, int k)
{
    for (int i = x; i <= n + 1; i += lowbit(i))
        bitr[i] += k;
}

int getR(int x)
{
    int res = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        res += bitr[i];
    return res;
}

void init_U() // OK
{
    for (int i = 0; i < u.size(); i++)
    {
        int yy = fy(u[i].second), xx = fx(u[i].first);
        U.push(P(yy, xx));
    }
}
void init_D() // OK
{
    for (int i = 0; i < d.size(); i++)
    {
        int yy = fy(d[i].second), xx = fx(d[i].first);
        D.push(P(yy, xx));
    }
}
void init_L()
{
    for (int i = 0; i < l.size(); i++)
    {
        int yy = fy(l[i].second), xx = fx(l[i].first);
        L.push(P(yy, xx));
        add_L(n - xx + 1, 1);
    }
}
void init_R()
{
    for (int i = 0; i < r.size(); i++)
    {
        int yy = fy(r[i].second), xx = fx(r[i].first);
        R.push(P(yy, xx));
        add_R(xx + 1, 1);
    }
}
void init__L()
{
    for (int i = 0; i < l.size(); i++)
    {
        int yy = fy(l[i].second), xx = fx(l[i].first);
        _L.push(P(yy, xx));
        add_L(n - xx + 1, 1);
    }
}
void init__R()
{
    for (int i = 0; i < r.size(); i++)
    {
        int yy = fy(r[i].second), xx = fx(r[i].first);
        _R.push(P(yy, xx));
        add_R(xx + 1, 1);
    }
}
void init()
{
    memset(bitl, 0, sizeof(bitl)), memset(bitr, 0, sizeof(bitr));
    vx.clear(), vy.clear();
    u.clear(), d.clear(), l.clear(), r.clear();
    while (!L.empty())
        L.pop();
    while (!R.empty())
        R.pop();
    while (!_L.empty())
        _L.pop();
    while (!_R.empty())
        _R.pop();
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++)
    {
        char ch;

        scanf("%d%d %c", &a[i].first, &a[i].second, &ch);

        if (ch == 'U')
            u.push_back(a[i]);
        if (ch == 'D')
            d.push_back(a[i]);
        if (ch == 'L')
            l.push_back(a[i]);
        if (ch == 'R')
            r.push_back(a[i]);
        if ((ch == 'U' && a[i].second == 0 && a[i].first != 0 && a[i].first != n) ||
            (ch == 'D' && a[i].second == m && a[i].first != 0 && a[i].first != n) ||
            (ch == 'R' && a[i].first == 0 && a[i].second != m && a[i].second != 0) ||
            (ch == 'L' && a[i].first == n && a[i].second != m && a[i].second != 0))
            ans++;
        vx.push_back(a[i].first);
        vy.push_back(a[i].second);
    }

    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());

    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());

    n = vx.size();
    init_U();
    init_D();
    init_L();
    init_R();
}

int main()
{
    //  freopen("test.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        init();

        while (!U.empty())
        {
            P p = U.top();
            U.pop();
            int x = p.second, y = p.first;
            if (!L.empty())
            {
                P now = L.top();
                //       cout << now.second << ' ' << now.first<< endl;
                while (now.first < y)
                {
                    add_L(n - now.second + 1, -1);
                    L.pop();
                    if (L.empty())
                        break;
                    now = L.top();
                }
                ans += getL(n - x + 1); // !!!!!!!!!!!!!!!1
            }
            //cout << ans << endl;
            if (R.empty())
                continue;
            P now = R.top();
            while (now.first < p.first)
            {
                add_R(now.second + 1, -1);
                R.pop();
                if (R.empty())
                    break;
                now = R.top();
            }
            ans += getR(x + 1); // !!!!!!!!!!!
            //cout << ans << endl;
        }

        memset(bitl, 0, sizeof(bitl));
        memset(bitr, 0, sizeof(bitr));

        init__L();
        init__R();
        while (!D.empty())
        {
            P p = D.top();
            D.pop();
            int x = p.second, y = p.first;
            if (!_L.empty())
            {
                P now = _L.top();
                while (now.first > y)
                {
                    add_L(n - now.second + 1, -1);
                    _L.pop();
                    if (_L.empty())
                        break;
                    now = _L.top();
                }
                ans += getL(n - x + 1); // !!!!!!!!!!!!
            }

            if (_R.empty())
                continue;
            P now = _R.top();
            while (now.first > y)
            {
                add_R(now.second + 1, -1);
                _R.pop();
                if (_R.empty())
                    break;
                now = _R.top();
            }
            ans += getR(x + 1); // !!!!!!!!!!!!!!!
        }

        printf("%d\n", ans + 1);
    }
    return 0;
}