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

    int N;

    while (cin >> N, N != 0) {
      for (int i = 1; i <= N; i++) {
        node *lista = criar_lista(N);

        while (lista->next != lista) {
          node *toDelete = lista;

          lista = lista->next;
          lista->prev = toDelete->prev;
          toDelete->prev->next = lista;

          delete toDelete;

          for (int j = 0; j < i; j++) {
            lista = lista->next;
          }
        }

        int lastOne = lista->value;
        delete lista;

        if (lastOne == 13) {
          cout << (i + 1) << endl;
          break;
        }
      }
    }

    return 0;
}

node* criar_lista(int n) {
  node *list, *last;

  list = last = new node();

  last->value = 1;
  last->next = NULL;

  for (int i = 2; i <= n; i++) {
    last->next = new node();
    last->next->value = i;
    last->next->prev = last;

    last = last->next;
  }

  last->next = list;
  list->prev = last;

  return list;
}
