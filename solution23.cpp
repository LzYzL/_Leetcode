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
    int min;
    bool fla=1;
    ListNode *ln,*t;
    nod *p;
    while (fla) {
        fla=0;
        min=2147483647;
        for (int i=0;i<(int)lists.size();++i) {
            if (lists[i]) fla=1;
            if (lists[i]->val<min) {
                min=lists[i]->val;
                t=lists[i];
            }
        }
        if (!fla) break;
        add(&p,min);
        t=t->next;
    }

    return makeln(&p,&ln);
}

void Solution::add(nod *p,int x) 
{
    nod *t=new nod;
    t->x=x;
    t->nex=p;
    p->pre=t;
    return;
}

ListNode* makeln(nod *p,ListNode *ln) 
{
    nod* pp;
    for (pp=p;pp;pp=pp->nex) {
        add(ln,pp->x);
    }
    return ln;
}
