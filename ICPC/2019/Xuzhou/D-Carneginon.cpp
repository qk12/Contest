#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
void initkmp(char x[], int m, int kmp[])
{
    int i = 0, pos = kmp[0] = -1;
    while (i < m)
    {
        while (pos != -1 && x[i] != x[pos])
            pos = kmp[pos];
        kmp[++i] = ++pos;
    }
}
int KMP(char x[], int m, char y[], int n, int kmp[])
{
    int i = 0, pos = 0, cnt = 0;
    while (i < n)
    {
        while (pos != -1 && y[i] != x[pos])
            pos = kmp[pos];
        ++i, ++pos;
        if (pos >= m)
        {
            ++cnt, pos = kmp[pos];
            return 1;
        }
    }
    return 0;
}

char x[maxn], y[maxn];
int kmp[maxn], kmp2[maxn];
int main()
{
    scanf("%s", x);
    int m = strlen(x);
    initkmp(x, m, kmp);
    int q;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%s", y);
        int n = strlen(y);
        if (m == n)
        {
            if (strcmp(x, y) == 0)
                puts("jntm!");
            else
                puts("friend!");
        }
        else if (n > m)
        {
            if (KMP(x, m, y, n, kmp))
                puts("my teacher!");
            else
                puts("senior!");
        }
        else
        {
            initkmp(y, n, kmp2);
            if (KMP(y, n, x, m, kmp2))
                puts("my child!");
            else
                puts("oh, child!");
        }
    }
    return 0;
}