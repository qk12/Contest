#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int maxn = 5e6 + 5;
int sg[maxn];

void SG(int n, int x)
{
    vector<int> v;
    for (int i = 1; i <= n; i *= x)
        v.push_back(i);
    sg[0] = 0; //轮到自己时剩0枚必败
    //当前状态的Grundy值是除任意一步所能转移到的转态的Grundy值以外的最小非负整数
    for (int i = 1; i <= n; ++i)
    {
        set<int> s;
        for (auto &j : v)
        {
            if (j > i)
                break;
            s.insert(sg[i - j]);
        }
        int g = 0;
        while (s.count(g) != 0)
            ++g;
        sg[i] = g; //最小的不属于S的非负整数
    }
}

int main()
{
    int x, n;
    scanf("%d%d", &x, &n);
    if (x == 1)
    {
        printf(n & 1 ? "YES\n" : "NO\n");
        return 0;
    }
    SG(n, x);
    printf(sg[n] ? "YES\n" : "NO\n");
    return 0;
}