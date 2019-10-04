#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 550;
int a[maxn];
bool win[3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        bool flag = false;
        int point = 0;
        char cur = 'D';
        memset(win, 0, sizeof(win));
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (cur == 'S')
                break;
            if (!flag)
            {
                if (a[i] == 1)
                    point += 10;
                if (a[i] == 0)
                {
                    point -= 5;
                    if (point < 0)
                        point = 0;
                }
                if (point >= 100)
                    flag = true;
                continue;
            }
            if (flag)
            {
                if (a[i] == 1)
                    win[cnt++] = true;
                if (a[i] == 0)
                    win[cnt++] = false;
                if (cnt == 2 && win[0] == true && win[1] == true)
                {
                    if (cur == 'A')
                        cur = 'S';
                    else
                        cur -= 1;
                    point = 0, memset(win, 0, sizeof(win)), cnt = 0, flag = false;
                    continue;
                }
                if (cnt == 2 && win[0] == false && win[1] == false)
                {
                    point = 60, memset(win, 0, sizeof(win)), cnt = 0, flag = false;
                    continue;
                }
            }
            if (cnt == 3)
            {
                int f = 0;
                for (int i = 0; i < 3; i++)
                    if (win[i] == true)
                        f++;
                if (f >= 2)
                {
                    if (cur == 'A')
                        cur = 'S';
                    else
                        cur -= 1;
                    point = 0;
                }
                else
                    point = 60;
                memset(win, 0, sizeof(win)), cnt = 0, flag = false;
            }
        }
        cout << cur << endl;
    }
    return 0;
}