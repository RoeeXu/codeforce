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
    while(x % num == 0)
    {
        x /= num;
        cnt++;
    }
    return cnt;
}
 
int main() {
    int n;
    int matrix[1001][1001], dp[1001][1001];
    vector<vector<string>> path(1001, vector<string>(1001, ""));
    int two, five;
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> matrix[i][j];
        two = num_cnt(matrix[0][0], 2);
        five = num_cnt(matrix[0][0], 5);
        dp[0][0] = two * 100 + five;
        for(int j = 1; j < n; j++)
        {
            two = num_cnt(matrix[0][j], 2);
            five = num_cnt(matrix[0][j], 5);
            dp[0][j] = dp[0][j - 1] + two * 100 + five;
            path[0][j] = path[0][j - 1] + "R";
        }
        for(int i = 1; i < n; i++)
        {
            two = num_cnt(matrix[i][0], 2);
            five = num_cnt(matrix[i][0], 5);
            dp[i][0] = dp[i - 1][0] + two * 100 + five;
            path[i][0] = path[i - 1][0] + "D";
        }
        for(int i = 1; i < n; i++)
            for(int j = 1; j < n; j++)
            {
                two = num_cnt(matrix[i][j], 2);
                five = num_cnt(matrix[i][j], 5);
                int D_two = two + dp[i - 1][j] / 100, D_five = five + dp[i - 1][j] % 100;
                int R_two = two + dp[i][j - 1] / 100, R_five = five + dp[i][j - 1] % 100;
                int D_min = min(D_two, D_five), R_min = min(R_two, R_five);
                int D_max = max(D_two, D_five), R_max = max(R_two, R_five);
                int flag;
                if(D_min == R_min && D_max > R_max) flag = 1;
                else if(D_min == R_min && D_max <= R_max) flag = 0;
                else if(D_min < R_min) flag = 0;
                else flag = 1;
                if(flag == 0)
                {
                    path[i][j] = path[i - 1][j] + "D";
                    dp[i][j] = dp[i - 1][j] + two * 100 + five;
                }
                else
                {
                    path[i][j] = path[i][j - 1] + "R";
                    dp[i][j] = dp[i][j - 1] + two * 100 + five;
                }
            }
        cout << min(dp[n - 1][n - 1] / 100, dp[n - 1][n - 1] % 100) << endl;
        cout << path[n - 1][n - 1] <<endl;
    }
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

