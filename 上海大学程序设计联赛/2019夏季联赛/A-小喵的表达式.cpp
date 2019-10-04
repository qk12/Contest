#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    char op;
    cin >> a >> op >> b;
    int ans;
    if (op == '+')
        ans = a + b;
    else if (op == '-')
        ans = a - b;
    else if (op == '*')
        ans = a * b;
    else
    {
        if (b == 0)
        {
            cout << "divided by ZERO" << endl;
            return 0;
        }
        ans = a / b;
    }
    cout << ans << endl;
    return 0;
}