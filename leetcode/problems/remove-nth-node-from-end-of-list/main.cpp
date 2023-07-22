/*
19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // lastElement
        int count = 0;
        ListNode *node;

        node = head;
        while (node != NULL) {
            count++;
            node = node->next;
        }

        int indexOfNodeToBeRemoved = count - n;

        node = head;

        if (indexOfNodeToBeRemoved == 0) return node->next;

        while (indexOfNodeToBeRemoved-- > 1) node = node->next;

        node->next = node->next->next;
        
        return head;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
