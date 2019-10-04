#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int maxn = 1e6 + 5;
typedef long long ll;
int a[maxn];
int pre[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    if (a[1] != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    set<int> s;
    for (int i = 1; i <= n; ++i)
        if (a[i] == 0)
            s.insert(i);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
            continue;
        auto it = s.lower_bound(pre[a[i]]);
        if (it == s.end() || *it >= i)
        {
            cout << "NO" << endl;
            return 0;
        }
        s.erase(it);
        pre[a[i]] = i;
    }
    cout << "YES" << endl;
    return 0;
}