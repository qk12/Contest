#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

const double eps = 1e-8;
#define zero(x) ((fabs(x) < eps ? 1 : 0))
#define sgn(x) (fabs(x) < eps ? 0 : ((x) < 0 ? -1 : 1))
struct point
{
    double x, y;
    point(double a = 0, double b = 0) { x = a, y = b; }
    point operator-(const point &b) const { return point(x - b.x, y - b.y); }
    point operator+(const point &b) const { return point(x + b.x, y + b.y); }
    bool operator==(point &b) { return zero(x - b.x) && zero(y - b.y); }
    double operator*(const point &b) const { return x * b.x + y * b.y; }
    double operator^(const point &b) const { return x * b.y - y * b.x; }
};
struct line
{
    point s, e;
    line() {}
    line(point ss, point ee) { s = ss, e = ee; }
};
bool segxseg(line l1, line l2)
{
    return max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) &&
           max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x) &&
           max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) &&
           max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y) &&
           sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0 &&
           sgn((l1.s - l2.e) ^ (l2.s - l2.e)) * sgn((l1.e - l2.e) ^ (l2.s - l2.e)) <= 0;
}
pair<int, point> spoint(line l1, line l2)
{
    point res = l1.s;
    if (sgn((l1.s - l1.e) ^ (l2.s - l2.e)) == 0)
        return {sgn((l1.s - l2.e) ^ (l2.s - l2.e)) != 0, res};
    double t = ((l1.s - l2.s) ^ (l2.s - l2.e)) / ((l1.s - l1.e) ^ (l2.s - l2.e));
    res.x += (l1.e.x - l1.s.x) * t;
    res.y += (l1.e.y - l1.s.y) * t;
    return {2, res};
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        line l1(point(x1, y1), point(x2, y2));
        line l2(point(x3, y3), point(x4, y4));
        double ans = 0.0;
        if (!segxseg(l1, l2))
        {
            //cout << 1 << endl;
            ans = 0.0;
        }
        else
        {
            pair<int, int> P1{x1, y1}, P2{x2, y2}, P3{x3, y3}, P4{x4, y4};
            if (P2.second > P1.second)
                P1.first = P2.first, P1.second = P2.second;
            if (P4.second > P3.second)
                P3.first = P4.first, P3.second = P4.second;
            if (P3.second < P1.second)
                P1.first = P3.first, P1.second = P3.second;
            pair<int, point> res = spoint(l1, l2);
            line line3(point(P1.first, P1.second), point(0, P1.second));
            if (P1.first == x1 || P1.first == x2)
            {
                pair<int, point> res2 = spoint(line3, l2);
                double dis = sqrt((P1.first - res2.second.x) * (P1.first - res2.second.x));
                ans = dis * ((double)P1.second - (double)res.second.y) * 1.0 / 2.0;
            }
            else
            {
                pair<int, point> res2 = spoint(line3, l1);
                double dis = sqrt((P1.first - res2.second.x) * (P1.first - res2.second.x));
                ans = dis * ((double)P1.second - (double)res.second.y) * 1.0 / 2.0;
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}