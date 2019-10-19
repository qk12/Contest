#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e7 + 5;
int kmp[maxn];
void initkmp(char x[], int m)
{
    int i = 0, pos = kmp[0] = -1;
    while (i < m)
    {
        while (pos != -1 && x[i] != x[pos])
        {
            pos = kmp[pos];
        }
        kmp[++i] = ++pos;
    }
}

char x[maxn], s[maxn];

int main()
{
    ll a, b;
    scanf("%lld%lld", &a, &b);
    scanf("%s", x);
    int m = strlen(x);
    int pos = 0;
    for (int i = 0; i < m; ++i)
    {
        if (x[i] == '.')
        {
            pos = i;
            break;
        }
    }
    int cnt = 0;
    for (int i = m - 1; i > pos; --i)
    {
        s[cnt++] = x[i];
    }
    initkmp(s, cnt);
    ll ans = -1e18, p, l;
    for (int i = cnt; i >= 1; --i)
    {
        if (kmp[i] == 0)
            p = l = i;
        else
            p = i, l = i - kmp[i];
        ans = max(ans, a * p - b * l);
        //cout << p << ' ' << l <<' '<< ans << endl;
    }
    printf("%lld\n", ans);
    return 0;
}