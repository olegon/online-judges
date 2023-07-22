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
        ListNode *node;
        int count = 0;

        node = head;
        while (node != NULL) {
            count++;
            node = node->next;
        }

        int indexToBeRemoved = count - n;

        return walkAndRemove(head, indexToBeRemoved);
    }

    ListNode* walkAndRemove(ListNode* head, int index) {
        if (index == 0) return head->next;
        else {
            head->next = walkAndRemove(head->next, index - 1);
            return head;
        };
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
