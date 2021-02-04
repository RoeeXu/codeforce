/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0002_A.cpp
* Author:   roeexu
* Date:     2021-02-04 21:37:07
* Brief:
****************************************************/
 
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
 
using namespace std;
 
static const auto _ = []() { ios::sync_with_stdio(0); cin.tie(0); return 0; }();
 
int main() {
    int n, score;
    string name;
    unordered_map<string, int> cnt;
    vector<pair<string, int>> save;
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> name >> score;
            if(cnt.count(name)) cnt[name] += score;
            else cnt[name] = score;
            save.push_back({name, score});
        }
        int max_score = cnt.begin()->second;
        for(auto& it : cnt) if(it.second > max_score) max_score = it.second;
        vector<string> persons;
        for(auto& it : cnt) if(it.second == max_score) persons.push_back(it.first);
        string res;
        if(persons.size() == 1) res = persons[0];
        else
        {
            cnt.clear();
            for(auto& person : persons) cnt[person] = 0;
            for(auto& ps : save)
            {
                if(cnt.count(ps.first))
                {
                    cnt[ps.first] += ps.second;
                    if(cnt[ps.first] >= max_score)
                    {
                        res = ps.first;
                        break;
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

