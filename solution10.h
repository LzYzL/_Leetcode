#pragma once
#include <string>
#include <cstring>

using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p);
    private:
        int n;
        bool fla;
        string st[22];
        bool check(string s);
};