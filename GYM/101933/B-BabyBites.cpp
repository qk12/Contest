#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool flag = true;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        if (s != "mumble")
        {
            int res = 0;
            for (int j = 0; j < s.length(); ++j)
            {
                res = res * 10 + s[j] - '0';
            }
            if (res != i)
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
        cout << "makes sense" << endl;
    else
        cout << "something is fishy" << endl;
    return 0;
}