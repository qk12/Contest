#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    string t = "jessie";
    string s;
    while (T--)
    {
        cin >> s;
        for (int i = 0; i < s.length(); ++i)
            if ('A' <= s[i] && s[i] <= 'Z')
                s[i] = s[i] - 'A' + 'a';
        if (s == t)
            cout << "Good guy!" << endl;
        else
            cout << "Dare you say that again?" << endl;
    }
    return 0;
}