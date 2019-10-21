#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, n;
    cin >> v >> n;
    int t = v * n;
    for (int i = 1; i <= 9; ++i)
    {
        if (t * i % 10)
            cout << t * i / 10 + 1;
        else
            cout << t * i / 10;
        if (i < 9)
            cout << ' ';
    }
    cout << endl;
    return 0;
}