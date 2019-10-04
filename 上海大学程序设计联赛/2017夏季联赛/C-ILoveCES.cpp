//字符串中最多可以组成多少个I LOVE CES（不区分大小写，没有空格，即只要有这8个字符就可以组成一个）

#include <cstring>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
int cnt[30];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int ans = INF;
    for (int i = 0; i < s.length(); ++i)
        if ('A' <= s[i] && s[i] <= 'Z')
            s[i] = 'a' + s[i] - 'A';
    for (int i = 0; i < s.length(); i++)
        ++cnt[s[i] - 'a' + 1];

    ans = min(ans, cnt['i' - 'a' + 1]);
    ans = min(ans, cnt['l' - 'a' + 1]);
    ans = min(ans, cnt['o' - 'a' + 1]);
    ans = min(ans, cnt['v' - 'a' + 1]);
    ans = min(ans, cnt['e' - 'a' + 1] / 2);
    ans = min(ans, cnt['c' - 'a' + 1]);
    ans = min(ans, cnt['s' - 'a' + 1]);

    cout << ans << endl;
    return 0;
}