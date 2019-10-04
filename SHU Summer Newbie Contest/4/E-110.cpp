#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5005;
char s[maxn];
ll dp[maxn][111];

int main()
{
    scanf("%s", s);
    if (s[0] != '0')
        dp[0][s[0] - '0'] = 1;
    int len = strlen(s);
    for (int i = 1; i < len; ++i) //ä»Ž1å¼€å§‹
    {
        for (int j = 0; j < 110; ++j)
        {
            int k = (j * 10 + s[i] - '0') % 110;
            dp[i][k] += dp[i - 1][j];
        }
        if (s[i] != '0')
            ++dp[i][s[i] - '0'];
    }
    ll ans = 0;
    for (int i = 0; i < len; ++i)
    {
        ans += dp[i][0];
        //printf("%lld ", dp[i][0]);
    }
    printf("%lld\n", ans);
    return 0;
}