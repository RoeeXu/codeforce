/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0002_C.cpp
* Author:   roeexu
* Date:     2021-02-08 16:37:32
* Brief:
****************************************************/
 
#include <iostream>
#include <utility>
#include <iomanip>
#include <cmath>
 
using namespace std;
 
static const auto _ = []() { ios::sync_with_stdio(0); cin.tie(0); return 0; }();

pair<double, double> line2line(double x1, double y1, double x2, double y2, double x3, double y3)
{
    if(y1 == y2) return line2line(x3, y3, x1, y1, x2, y2);
    if(y1 == y3) return line2line(x2, y2, x1, y1, x3, y3);
    double k1 = (x1 - x2) / (y2 - y1);
    double b1 = (y1 + y2 - k1 * (x1 + x2)) / 2;
    double k2 = (x1 - x3) / (y3 - y1);
    double b2 = (y1 + y3 - k2 * (x1 + x3)) / 2;
    double x = (b2 - b1) / (k1 - k2);
    double y = k1 * x + b1;
    return {x, y};
}

double compute_angle(double a, double b, double x, double y, double r)
{
    double R = sqrt(pow(a - x, 2) + pow(b - y, 2));
    return r / R;
}

pair<double, double> circle2circle(double x1, double y1, double x2, double y2, double x3, double y3, double r1, double r2, double r3)
{
    double cx = (r2 * x1 + r1 * x2) / (r1 + r2);
    double cy = (r2 * y1 + r1 * y2) / (r1 + r2);
    double dx = (r2 * x1 - r1 * x2) / (r2 - r1);
    double dy = (r2 * y1 - r1 * y2) / (r2 - r1);
    double p1 = (cx + dx) / 2;
    double q1 = (cy + dy) / 2;
    double s1 = sqrt(pow(dx - cx, 2) + pow(dy - cy, 2)) / 2;
    cx = (r3 * x1 + r1 * x3) / (r1 + r3);
    cy = (r3 * y1 + r1 * y3) / (r1 + r3);
    dx = (r3 * x1 - r1 * x3) / (r3 - r1);
    dy = (r3 * y1 - r1 * y3) / (r3 - r1);
    double p2 = (cx + dx) / 2;
    double q2 = (cy + dy) / 2;
    double s2 = sqrt(pow(dx - cx, 2) + pow(dy - cy, 2)) / 2;
    double a1, b1, a2, b2, delta;
    if(q1 == q2)
    {
        a1 = (pow(s1, 2) - pow(s2, 2) - pow(p1, 2) + pow(p2, 2)) / 2 / (p2 - p1);
        delta = pow(s1, 2) - pow(a1 - p1, 2);
        if(delta < 0) return {1e9, 1e9};
        b1 = sqrt(delta) + q1;
        a2 = a1;
        b2 = -sqrt(delta) + q1;
    }
    else
    {
        double k = (p1 - p2) / (q2 - q1);
        double b = (pow(s1, 2) - pow(s2, 2) - pow(p1, 2) + pow(p2, 2) - pow(q1, 2) + pow(q2, 2)) / 2 / (q2 - q1);
        double A = k * k + 1;
        double B = -2 * p1 + 2 * k * (b - q1);
        double C = p1 * p1 + pow(b - q1, 2) - s1 * s1;
        delta = B * B - 4 * A * C;
        if(delta < 0) return {1e9, 1e9};
        a1 = (-B + sqrt(delta)) / 2 / A;
        a2 = (-B - sqrt(delta)) / 2 / A;
        b1 = k * a1 + b;
        b2 = k * a2 + b;
    }
    if(compute_angle(a1, b1, x1, y1, r1) > compute_angle(a2, b2, x1, y1, r1)) return {a1, b1};
    else return {a2, b2};
}

pair<double, double> solve(double x1, double y1, double x2, double y2, double x3, double y3, double r1, double r2, double r3)
{
    if(r1 == r2 && r2 == r3) return line2line(x1, y1, x2, y2, x3, y3);
    else if(r1 == r2) return circle2circle(x3, y3, x1, y1, x2, y2, r3, r1, r2);
    else if(r1 == r3) return circle2circle(x2, y2, x1, y1, x3, y3, r2, r1, r3);
    else return circle2circle(x1, y1, x2, y2, x3, y3, r1, r2, r3);
}
 
int main() {
    cout.setf(ios::fixed);
    double x1, y1, x2, y2, x3, y3, r1, r2, r3;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    cin >> x3 >> y3 >> r3;
    if((y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1)) return 0;
    pair<double, double> res;
    res = solve(x1, y1, x2, y2, x3, y3, r1, r2, r3);
    if(res.first == 1e9 && res.second == 1e9) return 0;
    cout << setprecision(5) << res.first << " " << res.second << endl;
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

