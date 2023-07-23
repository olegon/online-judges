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
        int size = getSize(head);

        ListNode *firstSegment = head;
        ListNode *midElement = getNthElement(head, size / 2);
        ListNode *secondSegment = midElement->next;
        midElement->next = NULL;

        firstSegment = firstSegment->next;
        secondSegment = invert(secondSegment);

        ListNode *current = head;

        while (true) {
            if (secondSegment == NULL) break;
            
            current->next = secondSegment;
            secondSegment = secondSegment->next;
            current = current->next;

            if (firstSegment == NULL) break;
            
            current->next = firstSegment;
            firstSegment = firstSegment->next;
            current = current->next;
        }

        print(head);
    }

    void print(ListNode *node) {
        if (node == NULL) cout << "NULL" << endl;
        else {
            cout << node->val << " -> ";
            print(node->next);
        }
    }

    int getSize(ListNode *node) {
        if (node == NULL) return 0;
        else return 1 + getSize(node->next);
    }
    
    ListNode* getNthElement(ListNode *node, int index) {
        if (index == 0) return node;
        else return getNthElement(node->next, index - 1);
    }

    ListNode* invert(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != NULL) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
