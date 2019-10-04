#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        double ans1 = (n == 1) ? 1.0 : 0.5;
        double ans2 = double(m + 1) / (2 * m);
        printf("Case #%d: %.6f %.6f\n", k, ans1, ans2);
    }
    return 0;
}