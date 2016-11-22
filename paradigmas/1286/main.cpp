#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> ii;

int greedy_knapsack(vector<ii> &v, size_t i, int capacity);
int knapsack(vector<ii> &v, size_t i, int capacity);

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
        int min = knapsack(pedidos, 0, P);

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
