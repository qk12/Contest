#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '8')
        {
            cout << "Ei";
        }
        else if (s[i] == 'E' && i != s.length() - 1 && s[i + 1] == 'i')
        {
            cout << '8';
            ++i;
        }
        else
            cout << s[i];
    }
    cout << endl;
    return 0;
}