#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool valido(queue<int> &train);

int main(void) {
    int N;

    while (cin >> N, N != 0) {
        while (true) {
            queue<int> train;

            for (int i = 0; i < N; i++) {
                int V;

                cin >> V;

                if (V == 0) break;
                else train.push(V);
            }

            if (train.size() == 0) break;
            else if (valido(train)) cout << "Yes\n";
            else cout << "No\n";
        }

        cout << '\n';
    }

    return 0;
}

bool valido(queue<int> &train) {
    int N = train.size();
    stack<int> platform;

    for (int i = 1; i <= N; i++) {
        if (train.size() > 0 && train.front() == i) {
            train.pop();
        }
        else if (platform.size() > 0 && platform.top() == i) {
            platform.pop();
        }
        else {
            platform.push(i);
        }

        // Sempre tentar limpar a estação
        while (train.size() > 0 && platform.size() > 0 && train.front() == platform.top()) {
            train.pop();
            platform.pop();
        }
    }

    return train.size() == 0 && platform.size() == 0;
}
