#include <bits/stdc++.h>
using namespace std;

int d[370];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int day;
        scanf("%d", &day);
        d[day] = 1;
    }
    int uncleaned = 0, dirtiness = 0, ans = 0;
    for (int i = 1; i <= 365; ++i)
    {
        dirtiness += uncleaned;
        if (dirtiness >= 20)
        {
            ++ans;
            dirtiness = uncleaned = 0;
        }
        if (d[i])
        {
            ++uncleaned;
        }
    }
    if (uncleaned)
        ++ans;
    printf("%d\n", ans);
    return 0;
}
