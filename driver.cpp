#include<cstdio>
#include<cstring>
#include<algorithm>
#include<assert.h>
#include "solution23.h"

using namespace std;

void test();

int main()
{
    test();
    return 0;
}

void test()
{
    Solution sol;
    vector<ListNode*> lists;
    ListNode* ans;

    vector<vector<int>> data = {{1, 4, 5}, {1, 3, 4}, {2, 6}};

    for (const auto& vec : data) {
        ListNode* head = new ListNode();
        ListNode* cur = head;
        for (int val : vec) {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        lists.push_back(head->next);
        delete head;
    }

    ans=sol.mergeKLists(lists);
    std::vector<int> expected = {1, 1, 2, 3, 4, 4, 5, 6};
    for (int val:expected) {
        assert(ans->val==val);
        ans=ans->next;
    }

    // ListNode* t=ans;
    // for (ans=ans->next;ans;ans=ans->next) {
    //     delete(t);
    //     t=ans;
    // }
    // delete(t);
    return;
}