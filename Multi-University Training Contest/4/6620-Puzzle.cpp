#include <bits/stdc++.h>
using namespace std;

int mat[20];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int from = 0;
        for (int i = 1; i <= 16; ++i)
        {
            scanf("%d", &mat[i]);
            if (mat[i] == 0)
                from = (i - 1) / 4 + 1;
        }
        int cnt = 0;
        for (int i = 1; i <= 16; ++i)
            if (mat[i])
                for (int j = i; j <= 16; ++j)
                    if (mat[j] && mat[j] < mat[i])
                        ++cnt;
        if ((4 - from) % 2 == cnt % 2)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}