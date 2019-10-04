#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        multiset<int> S;
        for (int i = 0; i < n; ++i)
        {
            static int x;
            scanf("%d", &x);
            S.insert(x);
        }
        auto it_begin = S.begin();
        auto it_end = --S.end();
        int minn = *it_begin, maxx = *it_end;
        while (k--)
        {
            if (minn == maxx)
                break;
            S.erase(it_end);
            S.insert(maxx - 1);

            S.erase(it_begin);
            S.insert(minn + 1);

            it_begin = S.begin();
            it_end = --S.end();
            maxx = *it_end;
            minn = *it_begin;
        }
        int ans = maxx - minn;
        printf("%d\n", ans);
    }
    return 0;
}