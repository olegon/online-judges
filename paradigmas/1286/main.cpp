#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

typedef pair<int, int> ii;

int greedy_knapsack(vector<ii> &v, size_t i, int capacity);
int knapsack(vector<ii> &v, size_t i, int capacity);
int knapsack_memo(vector<ii> &v, size_t i, int capacity, map<ii, int> &memo);
int dp_knapsack(vector<ii> &v, int capacity);

inline int obter_valor(ii &p) {
    return p.first;
}

inline int obter_peso(ii &p) {
    return p.second;
}

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N, N != 0) {
        int P;
        vector<ii> pedidos;

        cin >> P;

        for (int i = 0; i < N; i++) {
            pair<int, int> pq;

            cin >> pq.first;
            cin >> pq.second;

            pedidos.push_back(pq);
        }

        sort(pedidos.begin(), pedidos.end(), [](const ii &a, const ii &b) -> bool {
            return a.first > b.first;
        });

        // int min = greedy_knapsack(pedidos, 0, P);

        int min = dp_knapsack(pedidos, P);
        //
        // map<ii, int> memo;
        // int min = knapsack_memo(pedidos, 0, P, memo);

        cout << min << " min.\n";
    }

    return 0;
}

/* Greedy Solution */
int greedy_knapsack(vector<ii> &v, size_t i, int capacity) {
    if (i < v.size()) {
        if (v[i].second <= capacity) {
            return v[i].first + greedy_knapsack(v, i + 1, capacity - v[i].second);
        }
        else return greedy_knapsack(v, i + 1, capacity);
    }
    else return 0;
}

/* Exp Solution */
int knapsack(vector<ii> &v, size_t i, int capacity) {
    if (i < v.size()) {
        if (v[i].second <= capacity) {
            int take = v[i].first + knapsack(v, i + 1, capacity - v[i].second);
            int noTake = knapsack(v, i + 1, capacity);

            return max(take, noTake);
        }
        else return knapsack(v, i + 1, capacity);
    }
    else return 0;
}

int knapsack_memo(vector<ii> &v, size_t i, int capacity, map<ii, int> &memo) {
    if (i < v.size()) {
        map<ii, int>::iterator it = memo.find(ii(i, capacity));
        if (it != memo.end()) {
            return it->second;
        }

        if (v[i].second <= capacity) {
            int take = v[i].first + knapsack_memo(v, i + 1, capacity - v[i].second, memo);
            int noTake = knapsack_memo(v, i + 1, capacity, memo);

            memo.insert(pair<ii, int>(ii(i, capacity), max(take, noTake)));

            return max(take, noTake);
        }
        else return knapsack_memo(v, i + 1, capacity, memo);
    }
    else return 0;
}

int dp_knapsack(vector<ii> &v, int capacity) {
    int dp[v.size() + 1][capacity + 1];

    // for all items
    for (size_t i = 0; i <= v.size(); i++) {
        // for all capacities
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0; /* Valor = 0 ou Peso <= 0*/
            }
            else if(j - obter_peso(v[i - 1]) >= 0) { /* O item cabe atual cabe na mochila? */
                dp[i][j] = max(dp[i - 1][j], /* melhor solução já encontrada */
                               dp[i - 1][j - obter_peso(v[i - 1])] /* melhor valor, menos o peso atual */ + obter_valor(v[i - 1]) /* mais o valor atual */);
            }
            else { /* Caso não couber, então a melhor solução é a anterior. */
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[v.size()][capacity];
}
