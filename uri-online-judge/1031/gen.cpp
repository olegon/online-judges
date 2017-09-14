/*
Crise de Energia
https://www.urionlinejudge.com.br/judge/pt/problems/view/1031
*/

#include <iostream>

struct node {
  int value;
  node *next;
  node *prev;
};

node* criar_lista(int n);

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    for (int i = 13; i <= 100; i++) {
      cout << i << '\n';
    }
    cout << 0 << endl;

    return 0;
}
