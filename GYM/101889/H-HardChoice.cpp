#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    int a1, b1, c1;
    cin >> a >> b >> c >> a1 >> b1 >> c1;
    cout << max(0, a1 - a) + max(0, b1 - b) + max(0, c1 - c) << endl;
    return 0;
}