#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UF {
private:
    char *V;
    int N;
public:
    UF(int N);
    void connect(char a, char b);
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

        UF uf(V);

        for (int j = 0; j < E; j++) {
            char a, b;

            cin >> a;
            cin.ignore();

            cin >> b;
            cin.ignore();

            uf.connect(a, b);
        }

        cout << "Case #" << i << ":\n";
        uf.show();
        cout << '\n';
    }

    return 0;
}

UF::UF(int N) {
    this->N = N;
    this->V = new char[this->N];

    for (int i = 0; i < N; i++) {
        this->V[i] = 'a' + i;
    }
}

void UF::connect(char a, char b) {
    char a_value = this->V[a - 'a'];
    char b_value = this->V[b - 'a'];

    if (a_value == b_value) return;

    for (int i = 0; i < this->N; i++) {
        if (this->V[i] == b_value) this->V[i] = a_value;
    }
}

void UF::show(void) {
    vector<char> components[this->N];

    for (int i = 0; i < this->N; i++) {
        components[this->V[i] - 'a'].push_back(char(i + 'a'));
    }

    for (int i = 0; i < this->N; i++) {
        sort(components[i].begin(), components[i].end());
    }

    sort(components, components + this->N, [](const vector<char> &a, const vector<char> &b) -> bool {
        if (a.size() > 0 && b.size() > 0) return a[0] < b[0];
        else if (a.size() > 0 && b.size() == 0) return true;
        else if (a.size() == 0 && b.size() > 0) return false;
        else return false;
    } );

    int connectedComponents = 0;
    for (int i = 0; i < this->N; i++) {
        if (components[i].size() > 0) {
            connectedComponents++;
            for (int j = 0; j < components[i].size(); j++) {
                cout << components[i][j] << ',';
            }
            cout << '\n';
        }
    }

    cout << connectedComponents << " connected components\n";
}
