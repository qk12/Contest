#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int k = 1; k <= T; ++k)
    {
        int n, m;
        cin >> n >> m;
        string str1, str2, str3;
        cin >> str1 >> str2 >> str3;
        int temp = (str2[0] - str1[0] + 26) % 26;
        cout << "Case #" << k << ": ";
        for (int i = 0; i < m; ++i)
        {
            char ch = (str3[i] - 'A' - temp + 26) % 26 + 'A';
            cout << ch;
        }
        cout << endl;
    }
    return 0;
}