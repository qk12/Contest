#include <bits/stdc++.h>
using namespace std;

char mat[55][55];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                cin >> mat[i][j];
                if (mat[i][j] == '1')
                {
                    if (i == 1 || i == n || j == 1 || j == m)
                        ++cnt1;
                    else
                        ++cnt2;
                }
            }
        int tot = m * 2 + (n - 2) * 2;
        int res = tot - cnt1;
        if (res <= cnt2)
            cout << res << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}