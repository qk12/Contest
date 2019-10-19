#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        while (x % 2 == 0)
            x /= 2;
        while (x % 5 == 0)
            x /= 5;
        if (x != 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}