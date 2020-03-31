/*
Recuperação da Árvore
https://www.urionlinejudge.com.br/judge/pt/problems/view/1191
*/

#include <bits/stdc++.h>

using namespace std;

struct TNODE {
    char LETTER;
    TNODE* LEFT;
    TNODE* RIGHT;
};

TNODE* build_tree(string prefix, string infix, int &preIndex, int inBegin, int inEnd) {
    if (inBegin > inEnd) return NULL;

    TNODE* node = new TNODE();
    node->LETTER = prefix[preIndex++];
    node->LEFT = NULL;
    node->RIGHT = NULL;

    if (inBegin == inEnd) return node;

    int inIndex = infix.find(node->LETTER);

    node->LEFT = build_tree(prefix, infix, preIndex, inBegin, inIndex - 1);
    node->RIGHT = build_tree(prefix, infix, preIndex, inIndex + 1, inEnd);

    return node;
}

void print_pos_and_delete(TNODE* node) {
    if (node == NULL) return;

    print_pos_and_delete(node->LEFT);
    print_pos_and_delete(node->RIGHT);

    cout << node->LETTER;
    delete node;
}


int main(void) {
    ios::sync_with_stdio(false);

    string prefix, infix;

    while (cin >> prefix >> infix) {
        int preIndex = 0;
        TNODE* root = build_tree(prefix, infix, preIndex, 0, infix.size() - 1);
        print_pos_and_delete(root);
        cout << endl;
    }

    return EXIT_SUCCESS;
}
