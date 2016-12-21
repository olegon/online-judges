#include <iostream>
#include <vector>

using namespace std;

class QuickFind {
private:
    int *V;
    int N;
    int connectedComponents;
public:
    QuickFind(int N);
    ~QuickFind();
    void connect(int a, int b);
    void show(void);
};


int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int V, E;

        cin >> V >> E;
        cin.ignore();

        QuickFind uf(V);

        for (int j = 0; j < E; j++) {
            char a, b;

            cin >> a;
            cin.ignore();

            cin >> b;
            cin.ignore();

            uf.connect(a - 'a', b - 'a');
        }

        cout << "Case #" << i << ":\n";
        uf.show();
        cout << '\n';
    }

    return 0;
}

QuickFind::QuickFind(int N) {
    this->N = N;
    this->connectedComponents = N;
    this->V = new int[this->N];

    for (int i = 0; i < N; i++) {
        this->V[i] = i;
    }
}

QuickFind::~QuickFind() {
    delete[] this->V;
}

void QuickFind::connect(int a, int b) {
    int a_value = this->V[a];
    int b_value = this->V[b];

    if (a_value == b_value) return;

    if (b_value < a_value) {
        int aux_value = a_value;
        a_value = b_value;
        b_value = aux_value;
    }

    this->connectedComponents--;

    for (int i = 0; i < this->N; i++) {
        if (this->V[i] == b_value) this->V[i] = a_value;
    }
}

void QuickFind::show(void) {
    vector<int> components[this->N];

    for (int i = 0; i < this->N; i++) {
        components[this->V[i]].push_back(i);
    }

    for (int i = 0; i < this->N; i++) {
        if (components[i].size() > 0) {
            for (size_t j = 0; j < components[i].size(); j++) {
                cout << char(components[i][j] + 'a') << ',';
            }
            cout << '\n';
        }
    }

    cout << this->connectedComponents << " connected components\n";
}
