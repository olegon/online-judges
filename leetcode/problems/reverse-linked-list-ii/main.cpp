/*
92. Reverse Linked List II
https://leetcode.com/problems/reverse-linked-list-ii
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *current = head;
        ListNode *previous = nullptr;

        while (left > 1) {
            previous = current;
            current = current->next;

            left--;
            right--;
        }

        cout << current->val << endl;

        ListNode *currentBeforeInverting = current;
        ListNode *previousBeforeInverting = previous;

        while (right-- > 0) {
            ListNode *next = current->next;

            current->next = previous;
            previous = current;
            current = next;
        }

        currentBeforeInverting->next = current;

        if (previousBeforeInverting == nullptr) {
            head = previous;
        }
        else {
            previousBeforeInverting->next = previous;
        }
        
        return head;
    }
};

class RecursiveSolution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left > 1) {
            head->next = reverseBetween(head->next, left - 1, right - 1);
        }
        else {
            ListNode* curr = head;
            ListNode* prev = nullptr;
            
            while (right-- > 0) {
                ListNode *next = curr->next;

                curr->next = prev;
                prev = curr;
                curr = next;
            }

            head->next = curr;

            return prev;
        }

        return head;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
