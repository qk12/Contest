#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll A, B;
        scanf("%lld%lld", &A, &B);
        if (A & B)
            printf("%lld\n", A & B);
        else
            printf("1\n"); //C是正整数
    }
    return 0;
}