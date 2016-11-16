#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int find(const char *a, const char *b);

int main (void) {
    string A, B;

    while (getline(cin, A) && getline(cin, B)) {
        cout << find(A.c_str(), B.c_str()) << endl;
    }

    return 0;
}

int find(const char *a, const char *b) {
    int a_len = strlen(a);
    int b_len = strlen(b);

    if (a_len > b_len) return find(b, a);

    int max_found = 0;

    for (int ai = 0; ai < a_len; ai++) {
        for (int bi = 0; bi < b_len; bi++) {
            if (a[ai] == b[bi]) {
                int sz = 0;
                while (a[ai + sz] != '\0' && b[bi + sz] != '\0' && a[ai + sz] == b[bi + sz]) {
                    max_found = max(max_found, sz + 1);
                    sz++;
                }
            }
        }
    }

    return max_found;
}
