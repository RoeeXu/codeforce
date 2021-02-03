/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0001_A.cpp
* Author:   roeexu
* Date:     2021-02-03 17:15:28
* Brief:
****************************************************/
 
#include <iostream>
 
using namespace std;
 
static const auto _ = []() { ios::sync_with_stdio(0); cin.tie(0); return 0; }();
 
int main() {
    int n, m, a;
    long long r;
    while(cin >> n >> m >> a)
    {
        r = 1;
        r *= n / a + (n % a == 0 ? 0 : 1);
        r *= m / a + (m % a == 0 ? 0 : 1);
        cout << r << endl;
    }
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

