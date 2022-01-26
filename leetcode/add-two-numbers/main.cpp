/*
2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers
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
    // O(n)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
    
    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        if (l1 != NULL && l2 != NULL) {
            int value = l1->val + l2->val + carry;
            return new ListNode(value % 10, add(l1->next, l2->next, value / 10));
        }
        else if (l1 != NULL) {
            int value = l1->val + carry;
            return new ListNode(value % 10, add(l1->next, NULL, value / 10));
        }
        else if (l2 != NULL) {
            int value = l2->val + carry;
            return new ListNode(value % 10, add(NULL, l2->next, value / 10));
        }
        else if (carry > 0) {
            return new ListNode(carry, NULL);
        }
        
        return NULL;
    }
};

ListNode* read(int size) {
    int value;

    if (size == 1) {
        cin >> value;

        return new ListNode(value, NULL);
    }
    else {
        ListNode *tail = read(size - 1);
        
        cin >> value;

        return new ListNode(value, tail);
    }
}

int main(void) {
    ios::sync_with_stdio(false);

    int size;

    cin >> size;
    ListNode* l1 = read(size);

    cin >> size;
    ListNode* l2 = read(size);

    Solution s;
    ListNode* r = s.addTwoNumbers(l1, l2);

    while (r != NULL) {
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;

    return EXIT_SUCCESS;
}

