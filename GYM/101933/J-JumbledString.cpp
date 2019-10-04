#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (!a && !b && !c && !d)
    {
        cout << 1;
        return 0;
    }
    if (a == 0)
    {
        if (d > 0)
        {
            ll n1 = (1.0 + sqrt(1.0 + 8.0 * (double)d)) / 2.0;
            if (n1 * (n1 - 1) / 2 != d)
            {
                cout << "impossible";
                return 0;
            }
            if (b + c == n1)
            {
                for (int i = 0; i < c; i++)
                    cout << 1;
                cout << 0;
                for (int i = 0; i < b; i++)
                    cout << 1;
                return 0;
            }
            else if (b == 0 && c == 0)
            {
                for (int i = 0; i < n1; i++)
                    cout << 1;
                return 0;
            }
            else
            {
                cout << "impossible";
                return 0;
            }
        }
        else if (d == 0)
        {
            if (b == 0 && c == 0)
                cout << 1;
            else if (b == 1 && c == 0)
                cout << "01";
            else if (b == 0 && c == 1)
                cout << "10";
            else
            {
                cout << "impossible";
                return 0;
            }
            return 0;
        }
    }
    if (d == 0)
    {
        if (a > 0)
        {
            ll n0 = (1.0 + sqrt(1.0 + 8.0 * (double)a)) / 2.0;
            if (n0 * (n0 - 1) / 2 != a)
            {
                cout << "impossible";
                return 0;
            }
            if (b + c == n0)
            {
                for (int i = 0; i < b; i++)
                    cout << 0;
                cout << 1;
                for (int i = 0; i < c; i++)
                    cout << 0;
                return 0;
            }
            else if (b == 0 && c == 0)
            {
                for (int i = 0; i < n0; i++)
                    cout << 0;
                return 0;
            }
            else
            {
                cout << "impossible";
                return 0;
            }
        }
        else if (a == 0)
        {
            if (b == 0 && c == 0)
                cout << 1;
            else if (b == 1 && c == 0)
                cout << "01";
            else if (b == 0 && c == 1)
                cout << "10";
            else
            {
                cout << "impossible";
                return 0;
            }
            return 0;
        }
    }

    // a != 0 && d != 0
    ll n0 = (1.0 + sqrt(1.0 + 8.0 * (double)a)) * 0.5;

    ll n1 = (1.0 + sqrt(1.0 + 8.0 * (double)d)) * 0.5;

    if (n0 * (n0 - 1) / 2 != a || n1 * (n1 - 1) / 2 != d)
    {
        //printf("cant solve n0 n1 impossible,n0=%lld,n1=%lld",n0,n1);
        cout << "impossible";
        return 0;
    }

    if (b + c != n0 * n1)
    {
        cout << "impossible";
        return 0;
    }

    ll k1 = n1;
    ll bb = b;
    //   cout << n0 << ' ' << n1 << endl;
    //   cout << bb << ' ' << cc << endl;
    for (int i = 0; i < n0 + n1; i++)
    {
        if (k1 > bb)
        {
            cout << 1;
            k1--;
        }
        else
        {
            cout << 0;
            bb -= k1;
        }
    }
    return 0;
}