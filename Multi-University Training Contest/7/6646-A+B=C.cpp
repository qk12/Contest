#include <bits/stdc++.h>
#define MAXN 1000006
using namespace std;
bool bigger(char *a, char *b)
{
    if (strlen(a) > strlen(b))
        return true;
    else
        return strcmp(a, b) > 0;
}
char temps[MAXN];
void Minus(char *a, char *b)
{
    strcpy(temps, a);
    int lena = strlen(a);
    int i = lena - 1, j = strlen(b) - 1;
    for (; i >= 0 && j >= 0; i--, j--)
    {
        temps[i] -= b[j] - '0';
        if (temps[i] < '0')
        {
            temps[i] += 10;
            temps[i - 1] -= 1;
        }
    }
    i = 0;
    while (temps[i] == '0' && i < lena)
        i++;
    for (j = i; temps[j] != 0; j++)
        temps[j - i] = temps[j];
    temps[j - i] = 0;
}
char a[MAXN], b[MAXN], c[MAXN];
void zfill(char *c, int tlen)
{
    int len = strlen(c);
    for (; len < tlen; len++)
    {
        c[len] = '0';
        c[len + 1] = 0;
    }
}
void output(int x, int y, int z)
{
    int m = min(min(x, y), z);
    printf("%d %d %d\n", x - m, y - m, z - m);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s%s%s", a, b, c);
        int x = 0, y = 0, z = 0;
        int temp = strlen(c) - strlen(a);
        if (temp > 0)
        {
            zfill(a, strlen(c));
            x += temp;
        }
        else
        {
            zfill(c, strlen(a));
            z -= temp;
        }
        if (bigger(c, a))
        {
            Minus(c, a);
            //cout<<"1) align a,c\n\ta="<<a<<"\n\tc="<<c<<"\n\tc-a="<<temps;
            temp = strlen(temps) - strlen(b);
            if (temp > 0)
            {
                zfill(b, strlen(temps));
                y += temp;
            }
            else
            {
                zfill(temps, strlen(b));
                x -= temp;
                z -= temp;
            }
            if (strcmp(temps, b) == 0)
            {
                output(x, y, z);
                continue;
            }
            if (temp < 0)
            {
                x += temp, z += temp;
            }
        }
        zfill(c, strlen(c) + 1);
        ++z;
        if (bigger(c, a))
        {
            Minus(c, a);
            //cout<<"1) align a,c\n\ta="<<a<<"\n\tc="<<c<<"\n\tc-a="<<temps;
            temp = strlen(temps) - strlen(b);
            if (temp > 0)
            {
                zfill(b, strlen(temps));
                y += temp;
            }
            else
            {
                zfill(temps, strlen(b));
                x -= temp;
                z -= temp;
            }
            if (strcmp(temps, b) == 0)
            {
                output(x, y, z);
                continue;
            }
            if (temp < 0)
            {
                x += temp, z += temp;
            }
        }

        temp = strlen(c) - strlen(a);
        if (temp > 0)
        {
            zfill(a, strlen(c));
            x += temp;
        }
        else
        {
            zfill(c, strlen(a));
            z -= temp;
        }
        if (bigger(c, a))
        {
            Minus(c, a);
            //cout<<"1) align a,c\n\ta="<<a<<"\n\tc="<<c<<"\n\tc-a="<<temps;
            temp = strlen(temps) - strlen(b);
            if (temp > 0)
            {
                zfill(b, strlen(temps));
                y += temp;
            }
            else
            {
                zfill(temps, strlen(b));
                x -= temp;
                z -= temp;
            }
            if (strcmp(temps, b) == 0)
            {
                output(x, y, z);
                continue;
            }
            if (temp < 0)
            {
                x += temp, z += temp;
            }
        }
        zfill(c, strlen(c) + 1);
        ++z;
        if (bigger(c, a))
        {
            Minus(c, a);
            //cout<<"1) align a,c\n\ta="<<a<<"\n\tc="<<c<<"\n\tc-a="<<temps;
            temp = strlen(temps) - strlen(b);
            if (temp > 0)
            {
                zfill(b, strlen(temps));
                y += temp;
            }
            else
            {
                zfill(temps, strlen(b));
                x -= temp;
                z -= temp;
            }
            if (strcmp(temps, b) == 0)
            {
                output(x, y, z);
                continue;
            }
            if (temp < 0)
            {
                x += temp, z += temp;
            }
        }

        temp = strlen(c) - strlen(b);
        if (temp > 0)
        {
            zfill(b, strlen(c));
            y += temp;
        }
        else
        {
            zfill(c, strlen(b));
            z -= temp;
        }
        if (bigger(c, b))
        {
            Minus(c, b);
            //cout<<"1) align a,c\n\ta="<<a<<"\n\tc="<<c<<"\n\tc-a="<<temps;
            temp = strlen(temps) - strlen(a);
            if (temp > 0)
            {
                zfill(a, strlen(temps));
                x += temp;
            }
            else
            {
                zfill(temps, strlen(a));
                y -= temp;
                z -= temp;
            }
            if (strcmp(temps, a) == 0)
            {
                output(x, y, z);
                continue;
            }
            if (temp < 0)
            {
                y += temp, z += temp;
            }
        }
        zfill(c, strlen(c) + 1);
        ++z;
        if (bigger(c, b))
        {
            Minus(c, b);
            //cout<<"1) align a,c\n\ta="<<a<<"\n\tc="<<c<<"\n\tc-a="<<temps;
            temp = strlen(temps) - strlen(a);
            if (temp > 0)
            {
                zfill(a, strlen(temps));
                x += temp;
            }
            else
            {
                zfill(temps, strlen(a));
                y -= temp;
                z -= temp;
            }
            if (strcmp(temps, a) == 0)
            {
                output(x, y, z);
                continue;
            }
            if (temp < 0)
            {
                y += temp, z += temp;
            }
        }
        printf("-1\n");
    }
}