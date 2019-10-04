#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int cnt1 = 4, cnt2 = 2, ans = 0;
    while (cnt1 > 0 || cnt2 > 0)
    {
        int minn = 1005, x = 0, y = 0;
        for (int i = 0; i <= cnt1; ++i)
            for (int j = 0; j <= cnt2; ++j)
            {
                int temp = n - a * i - b * j;
                if (temp >= 0 && temp < minn)
                {
                    x = i, y = j, minn = temp;
                }
            }
        cnt1 -= x, cnt2 -= y;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}