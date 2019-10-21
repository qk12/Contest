#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, first;
    bool flag = true;
    cin >> n >> first;
    for (int i = 1; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x > first)
            flag = false;
    }
    if (flag)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}