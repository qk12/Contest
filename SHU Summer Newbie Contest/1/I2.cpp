#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int maxn = 7e4;
bool ans[maxn];
int main()
{
    int delta = 32768, mx = delta + 32767;
    string s;
    while (getline(cin, s))
    {
        stringstream ss(s);
        string t1, t;
        if (ss >> t1)
            ;
        else
            break;
        ss >> t;
        int x;
        ss >> x;
        x += delta;
        string tmp;
        if (ss >> tmp && tmp[0] != '|')
        {
            ss >> t;
            ss >> t;
            int r;
            ss >> r;
            r += delta;
            for (int i = x; i <= r; i++)
                ans[i] = true;
        }
        else
        {
            if (t[0] == '>')
            {
                for (int i = x; i <= mx; i++)
                    ans[i] = true;
            }
            else
            {
                for (int i = x; i >= 0; i--)
                    ans[i] = true;
            }
        }
    }
    bool ok = 1;
    for (int i = 0; i <= mx; i++)
        if (ans[i])
            ok = 0;
    if (ok)
        cout << "false" << endl;
    else
    {
        bool sss = 1;
        for (int i = 0; i <= mx; i++)
            if (!ans[i])
                sss = 0;
        if (sss)
            cout << "true" << endl;
        else
        {
            vector<PII> ou;
            int pre = 0;
            for (int i = 0; i <= mx + 1; i++)
            {
                if (!ans[i])
                {
                    if (pre != i)
                        ou.push_back(make_pair(pre, i - 1));
                    pre = i + 1;
                }
            }
            for (int i = 0; i < ou.size(); i++)
            {
                auto u = ou[i];
                if (u.first == 0)
                    cout << "x <= " << u.second - delta;
                else if (u.second == mx)
                    cout << "x >= " << u.first - delta;
                else
                {
                    cout << "x >= " << u.first - delta << " && x <= " << u.second - delta;
                }
                if (i == ou.size() - 1)
                    cout << endl;
                else
                    cout << " ||" << endl;
            }
        }
    }
    return 0;
}