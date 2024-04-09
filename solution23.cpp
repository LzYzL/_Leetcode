#include "solution23.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* Solution::mergeKLists(vector<ListNode*>& lists) 
{
    int min,t;
    bool fla=1;
    ListNode *ln=new ListNode,*head;
    head=ln;
    while (fla) {
        fla=0;
        min=2147483647;
        for (int i=0;i<(int)lists.size();++i) {
            if (lists[i]) fla=1;
            else continue;
            if (lists[i]->val<min) {
                min=lists[i]->val;
                t=i;
            }
        }
        if (!fla) break;

        ListNode *tt=new ListNode(min);
        head->next=tt;
        head=tt;

        lists[t]=lists[t]->next;
    }

    return ln->next;
}
