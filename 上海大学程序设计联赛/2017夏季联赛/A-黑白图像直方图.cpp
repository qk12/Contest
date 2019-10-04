//输出矩阵中每一列1的个数

#include <iostream>
using namespace std;

const int maxn = 105;
int a[maxn][maxn];

int main()
{
    int n, m;
    while (cin >> n >> m, m)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        }
        for (int i = 1; i <= m; i++)
        {
            int ans = 0;
            for (int j = 1; j <= n; j++)
            {
                if (a[j][i] == 1)
                    ans++;
            }
            cout << ans << ' ';
        }
        cout << endl;
    }
    return 0;
}