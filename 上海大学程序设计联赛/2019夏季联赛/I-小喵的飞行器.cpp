#include <bits/stdc++.h>
using namespace std;

int main()
{
    int y1 = 0, y2, n;
    scanf("%d", &n);
    double ans = 0;
    while (n--)
    {
        scanf("%d", &y2);
        ans += sqrt(1.0 + (double)(y1 - y2) * (y1 - y2));
        y1 = y2;
    }
    printf("%.9f\n", ans);
    return 0;
}