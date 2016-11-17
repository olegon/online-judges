#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(void) {
    int A, B;

    while (cin >> A >> B) {
        int count = 0;

        for (int i = A; i <= B; i++) {
            int n = i;
            vector<int> v;
            set<int> s;

            do {
                v.push_back(n % 10);
                s.insert(n % 10);

                n /= 10;
            } while (n > 0 && v.size() == s.size());

            if (v.size() == s.size()) count++;
        }

        cout << count << '\n';
    }

    return 0;
}
