#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int debug = 0;

void decode(int n, char a[])
{
    for (int i = 0; i < 3; ++i)
    {
        a[i] = n % 3;
        n /= 3;
    }
}
int encode(char a[])
{
    return a[0] + a[1] * 3 + a[2] * 9;
}
char encoded2skill(int n)
{
    char a[4];
    decode(n, a);
    for (int i = 0; i < 3; i++)
    {
        if (a[i] == 0)
            a[i] = 'Q';
        else if (a[i] == 1)
            a[i] = 'W';
        else
            a[i] = 'E';
    }
    a[3] = '\0'; //注意这句不能少！
    sort(a, a + 3);
    char res;
    if (strcmp(a, "QQQ") == 0)
        res = 'Y';
    else if (strcmp(a, "QQW") == 0)
        res = 'V';
    else if (strcmp(a, "EQQ") == 0)
        res = 'G';
    else if (strcmp(a, "WWW") == 0)
        res = 'C';
    else if (strcmp(a, "QWW") == 0)
        res = 'X';
    else if (strcmp(a, "EWW") == 0)
        res = 'Z';
    else if (strcmp(a, "EEE") == 0)
        res = 'T';
    else if (strcmp(a, "EEQ") == 0)
        res = 'F';
    else if (strcmp(a, "EEW") == 0)
        res = 'D';
    else
        res = 'B';
    if (debug)
    {
        printf("the special skill of %s(%d) = %c\n", a, n, res);
    }
    return res;
}
int dist[50][50];
char e2s[50];

void initiate()
{
    for (int from_ = 0; from_ < 27; from_++)
    {
        for (int to_ = 0; to_ < 27; to_++)
        {
            char from[4], to[4];
            decode(from_, from);
            decode(to_, to);
            for (int same_len = 3; same_len >= 0; same_len--)
            {
                bool flag = 1;
                for (int i = 0; i < same_len; i++)
                {
                    if (from[2 - same_len + i + 1] != to[i])
                        flag = false;
                }
                if (flag)
                {
                    dist[from_][to_] = 3 - same_len;
                    break;
                }
            }
        }
        e2s[from_] = encoded2skill(from_);
    }
}

int dp[maxn][27];
char s[maxn];

int main()
{
    scanf("%s", s);
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < 27; ++j)
            dp[i][j] = INF;
    initiate();
    int n = strlen(s);
    if (debug)
        printf("n=%d\n", n);

    int ans = INF;
    for (int start = 0; start < 27; ++start)
    {
        char got = e2s[start];
        if (got == s[0])
        {
            dp[0][start] = 3;
            if (debug)
            {
                printf("starts with %d\n", start);
            }
        }
    }
    for (int i = 0; i < n - 1; ++i)
    {
        for (int prev_input = 0; prev_input < 27; ++prev_input)
        {
            if (dp[i][prev_input] == INF)
                continue;
            for (int next_input = 0; next_input < 27; ++next_input)
            {
                if (e2s[next_input] != s[i + 1])
                    continue;
                dp[i + 1][next_input] = min(dp[i + 1][next_input], dp[i][prev_input] + dist[prev_input][next_input]);
                if (i == n - 2)
                {
                    ans = min(ans, dp[n - 1][next_input]);
                }
            }
        }
    }
    if (n == 1)
        printf("4\n");
    else
        printf("%d\n", ans + n);
    return 0;
}