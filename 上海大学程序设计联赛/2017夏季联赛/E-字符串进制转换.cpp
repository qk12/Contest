// 输入一个字符串 a代表0···z代表25 相当于26进制数 把它转换成m进制数

#include <iostream>
#include <stack>
using namespace std;

typedef long long LL;

int a[15];
int len;
LL base[15];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    base[0] = 1;
    for (int i = 1; i <= 10; i++)
        base[i] = base[i - 1] * 26;
    string s;
    int m;
    while (cin >> s >> m)
    {
        memset(a, 0, sizeof(a));
        len = 0;
        stack<int> ss;
        for (int i = 0; i < s.length(); i++)
            a[++len] = s[i] - 'a';
        LL ans = 0;
        for (int i = len; i >= 1; i--)
            ans += base[len - i] * a[i];
        if (ans == 0)
        {
            cout << "0" << endl;
            continue;
        }
        while (ans)
        {
            ss.push(ans % m);
            ans /= m;
        }
        while (!ss.empty())
        {
            cout << ss.top();
            ss.pop();
        }
        cout << endl;
    }
    return 0;
}