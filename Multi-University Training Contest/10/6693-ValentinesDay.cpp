#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;
const double eps = 1e-10;
double a[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        double maxx = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf", &a[i]);
            maxx = max(maxx, a[i]);
        }
        sort(a, a + n, greater<double>());
        double mul = 1.0 - a[0], ans = a[0];
        for (int i = 1; i < n; ++i)
        {
            double temp = ans * (1.0 - a[i]) + mul * a[i];
            if (temp - ans > eps)
            {
                ans = temp;
                mul *= (1.0 - a[i]);
            }
        }
        printf("%.12f\n", ans);
    }
    return 0;
}