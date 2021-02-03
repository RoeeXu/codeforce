/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0001_B.cpp
* Author:   roeexu
* Date:     2021-02-03 21:40:46
* Brief:
****************************************************/
 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
 
using namespace std;
 
static const auto _ = []() { ios::sync_with_stdio(0); cin.tie(0); return 0; }();

vector<string> split(string s)
{
    string tmp = "";
    vector<string> str;
    int flag = 1;
    for(auto c : s)
    {
        if(c >= 'A' && c <= 'Z')
        {
            if(flag == 1) tmp += c;
            else
            {
                str.push_back(tmp);
                tmp = c;
                flag = 1;
            }
        }
        else
        {
            if(flag == 1)
            {
                str.push_back(tmp);
                tmp = c;
                flag = 0;
            }
            else tmp += c;
        }
    }
    str.push_back(tmp);
    return str;
}

string f(string eng, string num)
{
    int r = 0;
    for(auto c : eng)
    {
        r *= 26;
        r += c - 'A' + 1;
    }
    return "R" + num + "C" + to_string(r);
}

string g(string R, string C)
{
    string eng = "";
    int num = stoi(C);
    while(num > 0)
    {
        num -= 1;
        eng += num % 26 + 'A';
        num /= 26;
    }
    reverse(eng.begin(), eng.end());
    return eng + R;
}
 
int main() {
    int n;
    string s;
    vector<string> str;
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> s;
            str = split(s);
            if(str.size() == 2) cout << f(str[0], str[1]) << endl;
            else cout << g(str[1], str[3]) << endl;
        }
    }
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

