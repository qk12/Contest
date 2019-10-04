#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
const int maxn = 25;
int a[maxn];
map<int, int> mp;
vector<int> v[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        v[i].push_back(a[i]);
        for (int j = 0; j < n; ++j)
            if (i != j && gcd(a[i], a[j]) != 1)
            {
                v[i].push_back(a[j]);
            }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        bool flag = true;
        //cout << v[i].size() << endl;
        for (int j = 0; j < v[i].size(); ++j)
            if (v[i].size() > v[mp[v[i][j]]].size())
                flag = false;
        if (flag)
            ans = max(ans, (int)v[i].size());
    }
    cout << ans << endl;
    return 0;
}