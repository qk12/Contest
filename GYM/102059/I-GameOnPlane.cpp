#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 5;
int sg[maxn];

void SG(int n)
{
    sg[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        set<int> s;
        for (int j = 0; j <= i - 2; ++j)
        {
            s.insert(sg[j] ^ sg[i - j - 2]);
        }
        int g = 0;
        while (s.count(g) != 0)
            ++g;
        sg[i] = g;
    }
}

int main()
{
    int T;
    cin >> T;
    SG(maxn);
    while (T--)
    {
        int n;
        cin >> n;
        cout << (sg[n] ? "First" : "Second") << endl;
    }
    return 0;
}