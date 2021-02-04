/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0001_C.cpp
* Author:   roeexu
* Date:     2021-02-04 13:57:39
* Brief:
****************************************************/
 
#include <iostream>
#include <cmath>
#include <iomanip>

#define EPS 1e-5
#define PI 3.1415926
 
using namespace std;
 
static const auto _ = []() { ios::sync_with_stdio(0); cin.tie(0); return 0; }();

int solve(double theta1, double theta2, double theta3)
{
    double a, b, c;
    for(int N = 3; N <= 100; N++)
    {
        a = abs(sin(N * (theta1 - theta2) / 2));
        b = abs(sin(N * (theta2 - theta3) / 2));
        c = abs(sin(N * (theta3 - theta1) / 2));
        if(a < EPS && b < EPS && c < EPS) return N;
    }
    return 0;
}

double shadow(double r, int k)
{
    return 0.5 * r * r * sin(PI * 2 / k) * k;
}

int main() {
    cout.setf(ios::fixed);
    double x1, y1, x2, y2, x3, y3;
    double a, b, c, g, e, f;
    double X, Y, R, N;
    double theta1, theta2, theta3;
    while(cin >> x1 >> y1)
    {
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        e = 2 * (x2 - x1);
        f = 2 * (y2 - y1);
        g = x2*x2 - x1*x1 + y2*y2 - y1*y1;
        a = 2 * (x3 - x2);
        b = 2 * (y3 - y2);
        c = x3*x3 - x2*x2 + y3*y3 - y2*y2;
        X = (g*b - c*f) / (e*b - a*f);
        Y = (a*g - c*e) / (a*f - b*e);
        R = sqrt((X-x1)*(X-x1)+(Y-y1)*(Y-y1));
        theta1 = atan2(y1 - Y, x1 - X);
        theta2 = atan2(y2 - Y, x2 - X);
        theta3 = atan2(y3 - Y, x3 - X);
        N = solve(theta1, theta2, theta3);
        cout << setprecision(6) << shadow(R, N) << endl;
    }
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

