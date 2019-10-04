#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int v;
    while (T--)
    {
        cin >> v;
        int temp = v, sum = 0;
        while (temp > 0)
        {
            sum += temp % 10;
            temp /= 10;
        }
        //cout<<sum<<endl;
        vector<int> ans;
        int cnt = 0;
        for (int i = 1; i <= sum; ++i)
        {
            if (v % i == 0 && sum % i == 0)
            {
                ans.push_back(i);
                ++cnt;
            }
        }
        cout << cnt << endl;
        bool ok = true;
        for (auto &i : ans)
            if (ok)
            {
                cout << i;
                ok = false;
            }
            else
            {
                cout << ' ' << i;
            }
        cout << endl;
    }
    return 0;
}