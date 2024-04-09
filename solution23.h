#pragma once
#include <cstring>
#include<vector>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
    // private:
        struct nod {
            int x;
            nod *nex,*pre;
        } *p;

        ListNode* mergeKLists(vector<ListNode*>& lists);

        void add(int x);

        ListNode* makeln(nod* p,ListNode* ln);
};