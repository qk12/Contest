#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
    ll x, T;
    cin >> T;
    while (T--)
    {
        cin >> x;
        if (x == (1LL << 31) - 1)
        {
            cout << (1LL << 31) << endl;
        }
        else
        {
            cout << (1LL << (__builtin_popcount(x) + 1)) << endl;
        }
    }
    return 0;
}
