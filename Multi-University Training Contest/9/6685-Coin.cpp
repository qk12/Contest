/*
给出n种物品的价格，现在要从无限枚10分，20分，50分，1元的硬币中
选出最少的硬币，满足能购买任何一种物品都不用找零。
[题解]
显然如果个位不为零时没有可行方案。接下来考虑可行方案的求解。
首先10分的硬币最多只会用一个，如果用了两个，直接替换成一个10分一个20分一定不亏。
20分的硬币最多只会用三个，如果用了四个，直接替换成一个10分两个20分一个50分一定不亏。
50分的硬币最多只会用一个，如果用了两个，直接替换成一个50分和一个1元一定不亏。
对于任何一种情况，重复使用上述规则一定会达到一个10分硬币最多一个，20分最多三个，
50分最多一个的情况，不会陷入重复甩锅的死循环
因此枚举这三种硬币分别用了多少个，然后整百的部分直接用一元硬币填，取最少的答案就行了。
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 105;
int w[maxn];

bool judge(int n, int num50, int num20, int num10)
{
    for (int i = 0; i <= num50; ++i)
        for (int j = 0; j <= num20; ++j)
            for (int k = 0; k <= num10; ++k)
                if (i * 50 + j * 20 + k * 10 == n)
                    return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        bool flag = true;
        for (int i = 0; i < n; ++i)
        {
            cin >> w[i];
            if (w[i] % 10 != 0)
                flag = false;
        }
        if (flag == false)
        {
            cout << -1 << endl;
            continue;
        }
        int ans = INF;
        for (int num50 = 0; num50 <= 1; ++num50)
            for (int num20 = 0; num20 <= 3; ++num20)
                for (int num10 = 0; num10 <= 1; ++num10)
                {
                    bool flag = true;
                    int num100 = 0;
                    for (int i = 0; i < n; ++i)
                    {
                        if (w[i] < 100)
                        {
                            if (judge(w[i], num50, num20, num10))
                            {
                                continue;
                            }
                            else
                            {
                                flag = false;
                                break;
                            }
                        }
                        else
                        {
                            if (judge(w[i] % 100 + 100, num50, num20, num10))
                            {
                                num100 = max(num100, (w[i] - 100) / 100);
                            }
                            else if (judge(w[i] % 100, num50, num20, num10))
                            {
                                num100 = max(num100, w[i] / 100);
                            }
                            else
                            {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if (flag)
                    {
                        ans = min(ans, num100 + num50 + num20 + num10);
                    }
                }
        cout << ans << endl;
    }
    return 0;
}