#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    int cnt = 0;
    while (n--)
    {
        cin >> s;
        //if(s[0]=='0' && s[0]=='8' && s[0]=='3' && s[0]=='0')//错误
        if (s[0] == '0' && s[1] == '8' && s[2] == '3' && s[3] == '0')
            ++cnt;
    }
    cout << cnt << endl;
    return 0;
}