#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10;
int G[maxn][maxn];

bool solve(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
                if (G[i][j] & G[j][k] & G[k][i])
                    return false;
                else if (!G[i][j] & !G[j][k] & !G[k][i])
                    return false;
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, x;
        scanf("%d", &n);
        memset(G, 0, sizeof(G));
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                scanf("%d", &x);
                if (n < 6)
                    G[i][j] = G[j][i] = x;
            }
        if (n <= 2)
        {
            printf("Great Team!\n");
            continue;
        }
        if (n >= 6)
        {
            printf("Bad Team!\n");
            continue;
        }
        printf(solve(n) ? "Great Team!\n" : "Bad Team!\n");
    }
    return 0;
}