#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int cnt = (n - (x2 - x1 + 1)) * (m % 2);
    cnt += (x2 - x1 + 1) * ((y1 - 1) % 2);
    cnt += (x2 - x1 + 1) * ((m - y2) % 2);
    int ans = cnt / 2 + cnt % 2;
    printf("%d\n", ans);
    return 0;
}