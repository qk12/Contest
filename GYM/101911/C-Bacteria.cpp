#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;
priority_queue<ll, vector<ll>, greater<ll>> que;
ll a[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &a[i]);
        que.push(a[i]);
    }
    bool flag = true;
    int ans = 0;
    while (que.size() > 1)
    {
        ll q1 = que.top();
        que.pop();
        ll q2 = que.top();
        que.pop();
        if (q1 == q2)
        {
            que.push(q1 * 2);
        }
        else
        {
            while (q1 < q2)
            {
                q1 *= 2;
                ++ans;
            }
            if (q1 > q2)
            {
                flag = false;
                break;
            }
            que.push(q1 * 2);
        }
    }
    cout << (flag ? ans : -1) << endl;
    return 0;
}