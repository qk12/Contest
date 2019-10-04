#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

const int maxn = 55;
string s1[maxn], s2[maxn];
int pos[maxn];
bool vis[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        memset(vis, false, sizeof(vis));
        memset(pos, -1, sizeof(pos));
        int n, m;
        bool flag = true;
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> s1[i] >> s2[i];
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (vis[j])
                    continue;
                bool ok = true;
                for (int k = 0; k < n; k++)
                {
                    if (s1[k][i] != s2[k][j])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    pos[i] = j;
                    vis[j] = true;
                    break;
                }
            }
            if (pos[i] == -1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            for (int i = 0; i < m; i++)
                cout << pos[i] + 1 << (i == m - 1 ? '\n' : ' ');
        else
            cout << -1 << endl;
    }
    return 0;
}