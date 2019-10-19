#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool a[2000][2000];
void init()
{
    a[1][1] = a[1][2] = a[2][2] = true;
    a[2][1] = false;
    for (int k = 2; k <= 10; ++k)
    {
        int p = 1 << (k - 1);
        for (int i = p + 1; i <= p * 2; ++i)
        {
            for (int j = 1; j <= p; ++j)
            {
                a[i][j] = !a[i - p][j];
                a[j][i] = a[j][i - p];
            }
            for (int j = p + 1; j <= p * 2; ++j)
                a[i][j] = a[i - p][j - p];
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    init();
    while (T--)
    {
        int n;
        scanf("%d", &n);
        int k = 1 << n;
        for (int i = 1; i <= k; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                printf("%c", a[i][j] ? 'C' : 'P');
            }
            printf("\n");
        }
    }
    return 0;
}