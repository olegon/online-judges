/*
Reorder List
https://leetcode.com/problems/reorder-list
*/

#include <bits/stdc++.h>

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
    void reorderList(ListNode* head) {
        ListNode *node;
        deque<ListNode*> d;

        node = head;
        while (node != NULL) {
            d.push_back(node);
            node = node->next;
        }

        node = d.front();
        d.pop_front();
        
        while (true) {
            if (d.empty()) break;

            node->next = d.back();
            d.pop_back();
            node = node->next;

            if (d.empty()) break;

            node->next = d.front();
            d.pop_front();
            node = node->next;
        }

        node->next = NULL;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
