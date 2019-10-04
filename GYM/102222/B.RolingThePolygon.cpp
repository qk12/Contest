#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> P;
const double PI = acos(-1.0);
const int maxn = 55;

struct point
{
    double x, y;
} a[maxn];
double cal(double x, double y)
{
    return sqrt(x * x + y * y);
}
double dot_product(P &x, P &y)
{
    return x.first * y.first + x.second * y.second;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%lf%lf", &a[i].x, &a[i].y);
        double xq, yq, ans = 0;
        scanf("%lf%lf", &xq, &yq);
        a[n] = a[0];
        a[n + 1] = a[1];
        for (int i = 1; i <= n; ++i)
        {
            P u, v;
            u.first = a[i - 1].x - a[i].x;
            u.second = a[i - 1].y - a[i].y;
            v.first = a[i + 1].x - a[i].x;
            v.second = a[i + 1].y - a[i].y;
            double x = cal(u.first, u.second), y = cal(v.first, v.second);
            double cita = PI - acos(dot_product(u, v) / x / y);
            double r = cal(xq - a[i].x, yq - a[i].y);
            ans += cita * r;
        }
        printf("Case #%d: %.3f\n", k, ans);
    }
    return 0;
}