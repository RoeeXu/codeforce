/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0002_B.cpp
* Author:   roeexu
* Date:     2021-02-04 22:20:10
* Brief:
****************************************************/
 
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
static const auto _ = []() { ios::sync_with_stdio(0); cin.tie(0); return 0; }();

int num_cnt(int x, int num)
{
    int cnt = 0;
    while(x > 0 && x % num == 0)
    {
        x /= num;
        cnt++;
    }
    return cnt;
}

int solve(int n, int matrix[1001][1001], int c, vector<string>& path)
{
    int cnt;
    int dp[1001];
    dp[0] = num_cnt(matrix[0][0], c);
    path[0] = "";
    for(int j = 1; j < n; j++)
    {
        dp[j] = dp[j - 1] + num_cnt(matrix[0][j], c);
        path[j] = path[j - 1] + "R";
    }
    for(int i = 1; i < n; i++)
    {
        dp[0] += num_cnt(matrix[i][0], c);
        path[0] += "D";
        for(int j = 1; j < n; j++)
        {
            cnt = num_cnt(matrix[i][j], c);
            if(dp[j] < dp[j - 1])
            {
                path[j] += "D";
                dp[j] += cnt;
            }
            else
            {
                path[j] = path[j - 1] + "R";
                dp[j] = dp[j - 1] + cnt;
            }
        }
    }
    return dp[n - 1];
}

void putout(int n, string p)
{
    cout << n << endl;
    cout << p << endl;
}
 
int main() {
    int n;
    int matrix[1001][1001];
    vector<string> path(1001, "");
    int res;
    int flag = 0, zero_x;
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
                if(flag == 0 && matrix[i][j] == 0)
                {
                    flag = 1;
                    zero_x = i;
                }
            }
        if(flag == 1)
        {
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(matrix[i][j] == 0)
                        matrix[i][j] = 10;
            res = solve(n, matrix, 2, path);
            if(res == 0) putout(0, path[n - 1]);
            else
            {
                res = solve(n, matrix, 5, path);
                if(res == 0) putout(0, path[n - 1]);
                else
                {
                    string tmp = "";
                    for(int i = 0; i < zero_x; i++) tmp += "D";
                    for(int i = 0; i < n - 1; i++) tmp += "R";
                    for(int i = 0; i < n - 1 - zero_x; i++) tmp += "D";
                    putout(1, tmp);
                }
            }
        }
        else
        {
            res = solve(n, matrix, 2, path);
            string back = path[n - 1];
            int tmp = solve(n, matrix, 5, path);
            if(res < tmp) putout(res, back);
            else putout(tmp, path[n - 1]);
        }
    }
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

