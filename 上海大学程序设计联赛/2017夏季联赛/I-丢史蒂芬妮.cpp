#include <iostream>
using namespace std;

const int maxn = 505;
int prime[maxn];     //存素数
bool is_prime[maxn]; //判定素数
int a[maxn][maxn];

int getPrime(int n) //返回n以内素数的个数
{
    int cnt = 0;
    for (int i = 0; i <= n; i++)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime[cnt++] = i;
            for (int j = 2 * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return cnt;
}

void get_a()
{
    memset(a, 1, sizeof(a));
    a[1][1] = 1;
    for (int i = 1; i < 505; i++)
    {
        for (int j = 1; j < 505; j++)
        {
            a[i][j] = !a[i][j];
            for (int k = 0; k < 505; k++)
            {
                if (is_prime[k] == 1)
                {
                    if (i + k <= 500)
                        a[i + k][j] &= a[i][j];
                    if (j + k <= 500)
                        a[i][j + k] &= a[i][j];
                    if (i + k <= 500 && j + k <= 500)
                        a[i + k][j + k] &= a[i][j];
                }
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    int n, m;
    getPrime(505);
    get_a();
    while (T--)
    {
        scanf("%d%d", &n, &m);
        if (a[n][m] == 0)
            printf("Shiro\n");
        else
            printf("Sora\n");
    }
    return 0;
}