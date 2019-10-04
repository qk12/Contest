#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int big = 0, small = 0;
    for (int i = 0; i < n; ++i)
    {
        static int x;
        cin >> x;
        if (x >= m)
            ++big;
        else
            ++small;
    }
    cout << max(0, big - small) << endl;
    return 0;
}