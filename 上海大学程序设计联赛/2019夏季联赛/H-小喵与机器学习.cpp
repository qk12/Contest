#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10];
    string s = "#uvwxy";
    int cnt = 0;
    for (int i = 1; i <= 6; ++i)
    {
        cin >> a[i];
        if (a[i] == 0)
            ++cnt;
    }
    if (cnt == 6)
        cout << 0 << endl;
    else
    {
        bool first = true;
        for (int i = 1; i <= 5; ++i)
        {
            if (first)
            {
                if (a[i] == 0)
                    continue;
                if (a[i] == -1)
                    cout << '-' << s[i];
                else if (a[i] == 1)
                    cout << s[i];
                else
                    cout << a[i] << s[i];
                first = false;
            }
            else
            {
                if (a[i] == 0)
                    continue;
                if (a[i] == -1)
                    cout << '-' << s[i];
                else if (a[i] < 0)
                    cout << a[i] << s[i];
                else if (a[i] == 1)
                    cout << '+' << s[i];
                else
                    cout << '+' << a[i] << s[i];
                first = false;
            }
        }
        if (a[6] > 0)
        {
            if (first)
                cout << a[6];
            else
                cout << '+' << a[6];
        }
        else if (a[6] < 0)
            cout << a[6];
        cout << endl;
    }
    return 0;
}