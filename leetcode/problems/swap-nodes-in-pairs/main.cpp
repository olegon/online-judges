/*
24. Swap Nodes in Pairs
https://leetcode.com/problems/swap-nodes-in-pairs/description/
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *curr = head;
        ListNode *next = head->next;
        ListNode *afterNext = head->next->next;

        next->next = head;
        head->next = swapPairs(afterNext);

        return next;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
