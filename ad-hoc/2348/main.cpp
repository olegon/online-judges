#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;
    vector<int> v;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int V;

        cin >> V;

        v.push_back(V);
    }

    sort(v.begin(), v.end());

    double sin_a = sin(2.0 * M_PI / N);
    double area = 0.0;

    area = v[0] * v[1];

    for (int i = 2; i < N; i++) {
        area += v[i - 2] * v[i];
    }

    area += v[N - 2] * v[N - 1];

    area *= sin_a / 2;

    cout << fixed << setprecision(3) << area << endl;

    return 0;
}
