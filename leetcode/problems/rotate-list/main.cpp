/*
61. Rotate List
https://leetcode.com/problems/rotate-list
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;

        ListNode *current, *prev, *lastNode;

        // calculate list size and store lastNode
        int size = 0; 
        prev = nullptr;
        current = head;
        while (current != nullptr) {
            size++;
            prev = current;
            current = current->next;
        }
        lastNode = prev;


        // transform rotateRight (k) in rotateLeft
        int rotateLeft = size - (k % size);
        cout << "rotateLeft: " << rotateLeft << endl;

        if (rotateLeft == size) return head;


        // rotate left
        prev = lastNode;
        current = head;
        while (rotateLeft-- > 0) {
            prev = current;
            current = current->next;
        }


        // rearrange pointers
        lastNode->next = head;
        prev->next = nullptr;


        return current;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
