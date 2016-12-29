/*
Eu Posso Adivinhar a Estrutura de Dados!
https://www.urionlinejudge.com.br/judge/pt/problems/view/1340
*/

#include <iostream>
#include <vector>
#include <utility>

#include <stack>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

bool is_stack(const vector<ii> &operations);
bool is_queue(const vector<ii> &operations);
bool is_priority_queue(const vector<ii> &operations);

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N) {
        vector<ii> operations;

        for (int i = 0; i < N; i++) {
            int operation,
                operand;

            cin >> operation >> operand;

            operations.push_back(make_pair(operation, operand));
        }


        int matches = 0;

        // cout << operations.size() << '\n';
        bool _is_stack = is_stack(operations);
        bool _is_queue = is_queue(operations);
        bool _is_priority_queue = is_priority_queue(operations);
        // cout << operations.size() << '\n';

        if (_is_stack) matches++;
        if (_is_queue) matches++;
        if (_is_priority_queue) matches++;

        if (matches == 1) {
            if (is_stack(operations)) cout << "stack\n";
            else if (is_queue(operations)) cout << "queue\n";
            else if (is_priority_queue(operations)) cout << "priority queue\n";
        }
        else if (matches > 1) {
            cout << "not sure\n";
        }
        else {
            cout << "impossible\n";
        }
    }

    return 0;
}

bool is_stack(const vector<ii> &operations) {
    stack<int> st;

    for (auto it = operations.begin(); it != operations.end(); ++it) {
        auto item = *it;

        if (item.first == 1) {
            st.push(item.second);
        }
        else {
            if (st.top() != item.second) return false;
            st.pop();
        }
    }

    return true;
}

bool is_queue(const vector<ii> &operations) {
    queue<int> qu;

    for (auto it = operations.begin(); it != operations.end(); ++it) {
        auto item = *it;

        if (item.first == 1) {
            qu.push(item.second);
        }
        else {
            if (qu.front() != item.second) return false;
            qu.pop();
        }
    }

    return true;
}

bool is_priority_queue(const vector<ii> &operations) {
    priority_queue<int> pq;

    for (auto it = operations.begin(); it != operations.end(); ++it) {
        auto item = *it;

        if (item.first == 1) {
            pq.push(item.second);
        }
        else {
            if (pq.top() != item.second) return false;
            pq.pop();
        }
    }

    return true;
}
