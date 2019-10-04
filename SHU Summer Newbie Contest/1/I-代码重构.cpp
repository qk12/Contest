#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
const int MINX = -32768;
const int MAXX = 32767;
const int SIZE = MAXX - MINX + 1;

using BS = bitset<SIZE>;
BS parseBase(stringstream &ss)
{
    ss.get();
    char op = ss.peek();
    ss.get(), ss.get();
    int x;
    ss >> x;
    BS result;
    if (op == '<')
        for (int i = MINX; i <= x; ++i)
            result[i - MINX] = true;
    else
        for (int i = x; i <= MAXX; ++i)
            result[i - MINX] = true;
    return result;
}
BS parseAnd(stringstream &ss)
{
    BS result = parseBase(ss);
    while (ss.peek() == '&')
    {
        ss.get(), ss.get();
        result &= parseBase(ss);
    }
    return result;
}
BS parseOr(stringstream &ss)
{
    BS result = parseAnd(ss);
    while (ss.peek() == '|')
    {
        ss.get(), ss.get();
        result |= parseAnd(ss);
    }
    return result;
}

int main()
{
    string s, t;
    while (cin >> t)
        s += t;
    stringstream ss(s);
    BS result = parseOr(ss);
    if (result.none())
        puts("false");
    else if (result.all())
        puts("true");
    else
    {
        bool first = true;
        for (int i = MINX; i <= MAXX; ++i)
        {
            if (!result[i - MINX])
                continue;
            int j = i;
            while (j + 1 <= MAXX && result[j + 1 - MINX])
                ++j;
            if (first)
                first = false;
            else
                puts(" ||");
            if (i == MINX)
                printf("x <= %d", j);
            else if (j == MAXX)
                printf("x >= %d", i);
            else
                printf("x >= %d && x <= %d", i, j);
            i = j;
        }
        putchar('\n');
    }
}