/*
Roteadores
https://www.urionlinejudge.com.br/judge/pt/problems/view/1774
*/

#include <bits/stdc++.h>

using namespace std;

struct CONNECTION {
    int FROM;
    int TO;
    int COST;
};

bool isConnected(const vector<int> &connectedArray, int a, int b) {
    return connectedArray[a] == connectedArray[b];
}

// a bit naive, but its enough
void connect(vector<int> &connectedArray, int a, int b) {
    int va = connectedArray[a];

    for (size_t i = 0; i < connectedArray.size(); i++) {
        if (connectedArray[i] == va) {
            connectedArray[i] = connectedArray[b];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);

    int R, C;

    cin >> R >> C;

    vector<CONNECTION> connections(C);

    for (int i = 0; i < C; i++) {
        int V, W, P;

        cin >> V >> W >> P;

        connections[i] = { V - 1, W - 1, P };
    }

    // sort connections by cost
    sort(connections.begin(), connections.end(), [] (const CONNECTION &a, const CONNECTION &b) -> bool {
        return a.COST < b.COST;
    });

    // init connected Array
    vector<int> connectedArray(R);
    for (size_t i = 0; i < connectedArray.size(); i++) {
        connectedArray[i] = i;
    }

    // calcule total cost
    int totalCost = 0;

    for (const auto &connection : connections) {
        if (!isConnected(connectedArray, connection.FROM, connection.TO)) {
            totalCost += connection.COST;
            connect(connectedArray, connection.FROM, connection.TO);
        }
    }

    // output total cost
    cout << totalCost << endl;

    return EXIT_SUCCESS;
}
