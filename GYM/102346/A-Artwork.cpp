#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int L[maxn], R[maxn];
int upper[maxn], lower[maxn];
int fa[maxn];
int X[maxn], Y[maxn], S[maxn];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void unite(int u, int v)
{
    u = find(u), v = find(v);
    if (u != v)
    {
        L[v] = min(L[v], L[u]);
        R[v] = max(R[v], R[u]);
        lower[v] = max(lower[v], lower[u]);
        upper[v] = min(upper[v], upper[u]);
        fa[u] = v;
    }
}
bool same(int i, int j)
{
    int dx = abs(X[i] - X[j]);
    int dy = abs(Y[i] - Y[j]);
    int R = S[i] + S[j];
    return dx * dx + dy * dy <= R * R;
}
int main()
{
    int M, N, K;
    scanf("%d%d%d", &M, &N, &K);
    for (int i = 0; i < K; ++i)
    {
        scanf("%d%d%d", X + i, Y + i, S + i);
        fa[i] = i;
        L[i] = X[i] - S[i];
        R[i] = X[i] + S[i];
        upper[i] = Y[i] - S[i];
        lower[i] = Y[i] + S[i];
        for (int j = 0; j < i; ++j)
        {
            if (same(i, j))
                unite(i, j);
        }
    }
    char ans = 'S';
    for (int i = 0; i < K; ++i)
    {
        int u = find(i);
        if (L[u] <= 0 && upper[u] <= 0)
            ans = 'N';
        if (L[u] <= 0 && R[u] >= M)
            ans = 'N';
        if (upper[u] <= 0 && lower[u] >= N)
            ans = 'N';
        if (R[u] >= M && lower[u] >= N)
            ans = 'N';
    }
    printf("%c\n", ans);
    return 0;
}