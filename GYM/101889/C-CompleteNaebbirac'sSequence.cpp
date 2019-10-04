#include <bits/stdc++.h>
using namespace std;

map<int, int> cnt_cnt;
map<int, int> cnt_number;
int cnt[1005];

int main()
{
    int k, n;
    scanf("%d%d", &k, &n);
    for (int i = 0; i < n; ++i)
    {
        static int x;
        scanf("%d", &x);
        ++cnt[x];
    }
    for (int i = 1; i <= k; ++i)
    {
        cnt_number[cnt[i]] = i;
        ++cnt_cnt[cnt[i]];
    }
    auto min_it = cnt_cnt.begin();
    int min_cnt = min_it->first, min_cnt_cnt = min_it->second, min_num = cnt_number[min_cnt];

    auto max_it = cnt_cnt.rbegin();
    int max_cnt = max_it->first, max_cnt_cnt = max_it->second, max_num = cnt_number[max_cnt];

    if (max_cnt - min_cnt == 2 && min_cnt_cnt == 1 && max_cnt_cnt == 1)
    {
        printf("-%d +%d\n", max_num, min_num);
    }
    else if (max_cnt - min_cnt == 1)
    {
        if (max_cnt_cnt == 1 && min_cnt_cnt == k - 1)
            printf("-%d\n", max_num);
        else if (min_cnt_cnt == 1 && max_cnt_cnt == k - 1)
            printf("+%d\n", min_num);
        else
            printf("*\n");
    }
    else
    {
        printf("*\n");
    }
    return 0;
}