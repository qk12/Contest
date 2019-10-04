#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
const LL kk = 233;
const LL mo = 1e9 + 7;
LL h[maxn];
bool compare(const string &s, const string &t)
{
    int lens = s.length(), lent = t.length();
    LL hs = 0, ht = 0;
    for (int i = 0; i < lent; i++)
    {
        hs = ((hs * kk % mo) + s[i]) % mo;
        ht = ((ht * kk % mo) + t[i]) % mo;
    }
    for (int i = 0; i + lent - 1 < lens; i++)
    {
        if (hs == ht)
        {
            return true;
        }
        hs = (hs - s[i] * h[lent - 1] % mo + mo) * kk % mo + s[i + lent];
        hs %= mo;
    }
    return false;
}
int main()
{
    string T;
    cin >> T;
    int n, lent = T.length();
    cin >> n;
    h[0] = 1;
    for (int i = 1; i <= maxn; i++)
        h[i] = h[i - 1] * kk % mo;
    while (n--)
    {
        string S;
        cin >> S;
        int lens = S.length();
        if (lens == lent)
        {
            if (T == S)
                puts("jntm!");
            else
                puts("friend!");
        }
        else if (lens < lent)
        {
            bool cmp = compare(T, S);
            if (cmp)
                puts("my child!");
            else
                puts("oh, child!");
        }
        else if (lens > lent)
        {
            bool cmp = compare(S, T);
            if (cmp)
                puts("my teacher!");
            else
                puts("senior!");
        }
    }
}