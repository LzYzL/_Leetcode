#pragma once
#include <cstring>
#include<vector>


using namespace std;

class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists);
    private:
        struct nod {
            int x;
            nod *nex,*pre;
        };
        struct ListNode {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
        };

        void Solution::add(nod& p,int x);

        ListNode* makeln(nod& p,ListNode& ln);
};