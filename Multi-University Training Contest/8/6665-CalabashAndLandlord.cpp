/*
题意：求两个和坐标轴平行的矩形把平面分成了几部分。
离散化两个矩形的坐标后一定可以用一个 5×5 的区域表示它们之间的相对关系。
一个矩形用 1 填充，一个用 2 填充，重叠部分用 3
DFS 求连通块数量即可
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int ans = 1;
        int x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
        printf("%d\n", ans);
    }
    return 0;
}