#include <iostream>

using namespace std;

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} *NODE;

void add(NODE *root, int value);
void print_pre(NODE root);
void print_in(NODE root);
void print_post(NODE root);
void clear(NODE root);

int main(void) {
    ios::sync_with_stdio(false);

    int C;

    cin >> C;

    for (int c = 1; c <= C; c++) {
        int N;
        NODE root = NULL;

        cin >> N;

        for (int i = 0; i < N; i++) {
            int V;

            cin >> V;

            add(&root, V);
        }

        cout << "Case " << c << ":\n";

        cout << "Pre.:";
        print_pre(root);
        cout << '\n';

        cout << "In..:";
        print_in(root);
        cout << '\n';

        cout << "Post:";
        print_post(root);
        cout << '\n';

        cout << '\n';

        clear(root);
    }

    return 0;
}

void add(NODE *root, int value) {
    if (*root == NULL) {
        *root = new node();

        (*root)->value = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else {
        if (value < (*root)->value) add(&(*root)->left, value);
        else add(&(*root)->right, value);
    }
}

void print_pre(NODE root) {
    if (root == NULL) return;
    else {
        cout << ' ' << root->value;
        print_pre(root->left);
        print_pre(root->right);
    }
}

void print_in(NODE root) {
    if (root == NULL) return;
    else {
        print_in(root->left);
        cout << ' ' << root->value;
        print_in(root->right);
    }
}

void print_post(NODE root) {
    if (root == NULL) return;
    else {
        print_post(root->left);
        print_post(root->right);
        cout << ' ' << root->value;
    }
}

void clear(NODE root) {
    if (root == NULL) return;

    clear(root->left);
    clear(root->right);
    delete root;
}
