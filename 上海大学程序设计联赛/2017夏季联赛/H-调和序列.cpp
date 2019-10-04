#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int maxn = 20005;

vector<ll> e[maxn];
ll a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n; i++)
            e[i].clear();
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j += i)
            {
                e[i].push_back(a[j]);
            }
            sort(e[i].begin(), e[i].end(), greater<ll>());
        }
        for (int i = 1; i <= m; i++)
        {
            int k, s;
            cin >> k >> s;
            if (k >= n)
            {
                if (s > 1)
                    cout << "-1" << endl;
                else
                    cout << a[1] << endl;
            }
            else
            {
                if (e[k].size() < s)
                    cout << "-1" << endl;
                else
                    cout << e[k][s - 1] << endl;
            }
        }
    }
    return 0;
}