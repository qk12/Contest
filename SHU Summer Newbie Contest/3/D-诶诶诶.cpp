#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
    string s;
    string x = "father";
    getline(cin, s);
    for (int i = 0; i < s.length(); ++i)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
    int j = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == x[j])
            ++j;
        if (j == 6)
            break;
    }
    if (j == 6)
        printf("Ei\n");
    else
        printf("Sad CSL\n");
    return 0;
}