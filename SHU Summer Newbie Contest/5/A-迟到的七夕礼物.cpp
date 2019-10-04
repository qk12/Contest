#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{

    int n;
    cin >> n;
    if (n & (n + 1))
        cout << 0 << endl;
    else
        cout << 1 << endl;
    return 0;
}