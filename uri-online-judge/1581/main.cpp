/*
Conversa Internacional
https://www.urionlinejudge.com.br/judge/pt/problems/view/1581
*/

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    while (N-- > 0) {
        int K;
        string idioma_final;

        cin >> K;
        cin.ignore(1);

        getline(cin, idioma_final);

        for (int i = 1; i < K; i++) {
            string idioma;

            getline(cin, idioma);

            if (idioma != idioma_final) idioma_final = "ingles";
        }

        cout << idioma_final << '\n';
    }

    return 0;
}
