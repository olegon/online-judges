/*
Crise de Energia
https://www.urionlinejudge.com.br/judge/pt/problems/view/1031
*/

#include <iostream>
#include <list>

template <typename T>
class node {
public:
  T value;
  node<T> *next;
  node<T> *prev;
  node(T value);
};

node<int>* create_circular_list(int n);

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N, N != 0) {
      int step, last;

      for (step = 0, last = -1; last != 13; step++) {
        node<int> *nd = create_circular_list(N);

        while (nd->next != nd) {
          // cout << nd->value << endl;

          nd->next->prev = nd->prev;
          nd->prev->next = nd->next;

          node<int> *to_delete = nd;
          nd = nd->next;

          delete to_delete;

          for (int h = 0; h < step; h++) {
            nd = nd->next;
          }
        }

        last = nd->value;

        delete nd;
      }

      cout << step << endl;
    }

    return 0;
}

template <typename T>
node<T>::node(T value) {
  this->value = value;
}

node<int>* create_circular_list(int n) {
  node<int> *list, *last;

  list = last = new node<int>(1);

  for (int i = 2; i <= n; i++) {
    last->next = new node<int>(i);
    last->next->prev = last;

    last = last->next;
  }

  last->next = list;
  list->prev = last;

  return list;
}
