#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int i = 0;
        while (i < s.length() && s[i] == 'y')
            ++i;
        if (i < s.length() && s[i] == 'z') //若不含'z'，右移不能降低字典序，第一轮立即终止
            s[i] = 'b';
        cout << s << endl;
    }
    return 0;
}