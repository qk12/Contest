#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
struct Hand
{
    char name[12];
    int cards[15];
    vector<int> count[6];
    int sum = 0;
    int getRank() const
    {
        if (count[1].size() == 5)
        {
            if (cards[10] == 1 && cards[11] == 1 && cards[12] == 1 && cards[13] == 1 && cards[1] == 1)
                return 0;
            if (count[1][0] + 4 == count[1][4])
                return 1;
        }
        if (count[4].size() == 1)
            return 2;
        if (count[3].size() == 1)
        {
            if (count[2].size() == 1)
                return 3;
            else
                return 4;
        }
        if (count[2].size() == 2)
            return 5;
        if (count[2].size() == 1)
            return 6;
        return 7;
    }
} hands[maxn];
bool cmp(const Hand &a, const Hand &b)
{
    int ra = a.getRank(), rb = b.getRank();
    if (ra != rb)
        return ra < rb;
    switch (ra)
    {
    case 0: //Straight
        break;
    case 1: //Straight
    {
        if (a.count[1][0] != b.count[1][0])
            return a.count[1][0] > b.count[1][0];
        break;
    }
    case 2: //Four of a kind
    {
        if (a.count[4][0] != b.count[4][0])
            return a.count[4][0] > b.count[4][0];
        if (a.count[1][0] != b.count[1][0])
            return a.count[1][0] > b.count[1][0];
        break;
    }
    case 3: //Full House
    {
        if (a.count[3][0] != b.count[3][0])
            return a.count[3][0] > b.count[3][0];
        if (a.count[2][0] != b.count[2][0])
            return a.count[2][0] > b.count[2][0];
        break;
    }
    case 4: //Three of a Kind
    {
        if (a.count[3][0] != b.count[3][0])
            return a.count[3][0] > b.count[3][0];
        int sa = a.count[1][0] + a.count[1][1];
        int sb = b.count[1][0] + b.count[1][1];
        if (sa != sb)
            return sa > sb;
        break;
    }
    case 5: //Two Pairs
    {
        if (a.count[2][1] != b.count[2][1])
            return a.count[2][1] > b.count[2][1];
        if (a.count[2][0] != b.count[2][0])
            return a.count[2][0] > b.count[2][0];
        if (a.count[1][0] != b.count[1][0])
            return a.count[1][0] > b.count[1][0];
        break;
    }
    case 6: //Pair
    {
        if (a.count[2][0] != b.count[2][0])
            return a.count[2][0] > b.count[2][0];
        int sa = a.count[1][0] + a.count[1][1] + a.count[1][2];
        int sb = b.count[1][0] + b.count[1][1] + b.count[1][2];
        if (sa != sb)
            return sa > sb;
        break;
    }
    case 7: //High Card
    {
        if (a.sum != b.sum)
            return a.sum > b.sum;
        break;
    }
    }
    return strcmp(a.name, b.name) < 0;
}
int read()
{
    char c;
    while (isspace(c = std::getchar()))
        ;
    if (c == 'A')
        return 1;
    if (c == 'J')
        return 11;
    if (c == 'Q')
        return 12;
    if (c == 'K')
        return 13;
    if (c == '1')
    {
        getchar();
        return 10;
    }
    return c - '0';
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", hands[i].name);
            for (int j = 0; j < 5; ++j)
                ++hands[i].cards[read()];
            for (int j = 1; j <= 13; ++j)
            {
                hands[i].sum += j * hands[i].cards[j];
                if (hands[i].cards[j] && hands[i].cards[j] != 5)
                    hands[i].count[hands[i].cards[j]].push_back(j);
            }
        }
        sort(hands, hands + n, cmp);
        for (int i = 0; i < n; ++i)
            printf("%s\n", hands[i].name);
    }
    return 0;
}