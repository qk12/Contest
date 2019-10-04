#include <bits/stdc++.h>
using namespace std;

char mat[5][5];
char op[5];
void solve1(int x, int y) //éĄş
{
    char temp = mat[x][y];
    mat[x][y] = mat[x + 1][y];
    mat[x + 1][y] = mat[x + 1][y + 1];
    mat[x + 1][y + 1] = mat[x][y + 1];
    mat[x][y + 1] = temp;
}
void solve2(int x, int y) //é
{
    char temp = mat[x][y];
    mat[x][y] = mat[x][y + 1];
    mat[x][y + 1] = mat[x + 1][y + 1];
    mat[x + 1][y + 1] = mat[x + 1][y];
    mat[x + 1][y] = temp;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= 3; ++i)
            for (int j = 1; j <= 3; ++j)
                cin >> mat[i][j];
        while (n--)
        {
            cin >> op;
            int x, y;
            if (op[0] == '1')
                x = 1, y = 1;
            else if (op[0] == '2')
                x = 1, y = 2;
            else if (op[0] == '3')
                x = 2, y = 1;
            else
                x = 2, y = 2;
            if (op[1] == 'C')
                solve1(x, y);
            else
                solve2(x, y);
        }
        for (int i = 1; i <= 3; ++i)
        {
            for (int j = 1; j <= 3; ++j)
                cout << mat[i][j];
            cout << endl;
        }
    }
    return 0;
}