#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int maxn = 105;
const int mod = 998244353;

int dp[maxn][maxn][maxn];
vector<P> vec[maxn];

void add(int &x, int y)
{
    (x += y) >= mod && (x -= mod);
}
int main()
{

    return 0;
}