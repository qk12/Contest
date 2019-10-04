#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int a[maxn];

bool check(int sum1, int sum2, int max_last1, int max_last2)
{
    if (sum1 - sum2 > max_last2)
        return true;
    if (sum2 - sum1 > max_last1)
        return true;
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int sum1 = 0, sum2 = 0, ans = 1005;
    int max_last1 = 0, max_last2 = 0;
    int hong_num = 15;
    int temp = 27;
    bool flag = true;
    for (int i = 1; i <= n; ++i)
    {
        if (flag)
        {
            if (hong_num)
            {
                sum1 += a[i];
                hong_num -= a[i];
                if (a[i])
                    max_last1 = hong_num * 8 + 27 + 7;
                else
                    max_last1 = hong_num * 8 + 27;
                max_last2 = hong_num * 8 + 27;
                if (check(sum1, sum2, max_last1, max_last2))
                    ans = min(ans, i);
                if (a[i])
                {
                    ++i;
                    sum1 += a[i];
                    max_last1 = hong_num * 8 + 27;
                    max_last2 = hong_num * 8 + 27;
                    if (check(sum1, sum2, max_last1, max_last2))
                        ans = min(ans, i);
                }
            }
            else if (temp)
            {
                sum1 += a[i];
                temp -= a[i];
                max_last2 = temp;
                if (check(sum1, sum2, max_last1, max_last2))
                    ans = min(ans, i);
            }
            else if (hong_num == 0 && temp == 0 && ans == 1005 && sum1 == sum2)
            {
                if (a[i])
                    ans = min(ans, i);
            }
            if (a[i] == 0)
                flag = false;
        }
        else
        {
            if (hong_num)
            {
                sum2 += a[i];
                hong_num -= a[i];
                if (a[i])
                    max_last2 = hong_num * 8 + 27 + 7;
                else
                    max_last2 = hong_num * 8 + 27;
                max_last1 = hong_num * 8 + 27;
                if (check(sum1, sum2, max_last1, max_last2))
                    ans = min(ans, i);
                if (a[i])
                {
                    ++i;
                    sum2 += a[i];
                    max_last1 = hong_num * 8 + 27;
                    max_last2 = hong_num * 8 + 27;
                    if (check(sum1, sum2, max_last1, max_last2))
                        ans = min(ans, i);
                }
            }
            else if (temp)
            {
                sum2 += a[i];
                temp -= a[i];
                max_last1 = temp;
                if (check(sum1, sum2, max_last1, max_last2))
                    ans = min(ans, i);
            }
            else if (hong_num == 0 && temp == 0 && ans == 1005 && sum1 == sum2)
            {
                if (a[i])
                    ans = min(ans, i);
            }
            if (a[i] == 0)
                flag = true;
        }
    }
    cout << ans << endl;
    return 0;
}