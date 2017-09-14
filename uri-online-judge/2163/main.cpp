/*
O Despertar da Força
https://www.urionlinejudge.com.br/judge/pt/problems/view/2163
*/

#include <iostream>
#include <utility>

using namespace std;

typedef pair<int, int> ii;

ii procurar(const int **terreno, int N, int M);
bool procurar_arredores(const int **terreno, int i, int j);

int main(void) {
    ios::sync_with_stdio(false);

    int N, M;

    cin >> N >> M;

    int **terreno = new int*[N];
    for (int i = 0; i < N; i++) terreno[i] = new int[M];

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> terreno[i][j];
      }
    }

    ii local = procurar((const int**)terreno, N, M);

    cout << local.first << ' ' << local.second << endl;

    return 0;
}

ii procurar(const int **terreno, int N, int M) {
  for (int i = 1; i < N - 1; i++) {
    for (int j = 1; j < M - 1; j++) {
      if (terreno[i][j] == 42 && procurar_arredores(terreno, i, j)) return make_pair(i + 1, j + 1);
    }
  }

  return make_pair(0, 0);
}

bool procurar_arredores(const int **terreno, int i, int j) {
  for (int m = i - 1; m < i + 2; m++) {
    for (int n = j - 1; n < j + 2; n++) {
      if (m == i && n == j) continue;

      if (terreno[m][n] != 7) return false;
    }
  }

  return true;
}
