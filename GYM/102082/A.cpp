#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
string in[maxn];

bool comp(const string &a, const string &b)
{
    int lena = a.length(), lenb = b.length();
    int len = min(lena, lenb);

    for (int i = 0; i < len; ++i)
    {
        if (isdigit(a[i]) && isdigit(b[i])) //两个都是数字，爆long long
        {
            int k1 = i, k2 = i;
            while (k1 + 1 < lena && isdigit(a[k1 + 1]))
                ++k1;
            while (k2 + 1 < lenb && isdigit(b[k2 + 1]))
                ++k2;
            if (k1 != k2)
                return k1 > k2;
            else
            {
                for (int j = i; j <= k1; ++j)
                    if (a[j] != b[j])
                        return a[j] > b[j];
            }
            i = k2;
        }
        else if (isdigit(a[i]))
            return false;
        else if (isdigit(b[i]))
            return true;
        else //都不是数字
        {
            if (a[i] != b[i])
                return a[i] > b[i];
        }
    }
    return lena > lenb; //前面都一样
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i)
        cin >> in[i];
    for (int i = 1; i <= n; ++i)
    {
        if (comp(in[0], in[i]))
            cout << '-' << endl;
        else
            cout << '+' << endl;
    }
    return 0;
}