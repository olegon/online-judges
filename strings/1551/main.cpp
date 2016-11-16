#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum TIPO_FRASE {
    COMPLETA,
    QUASE_COMPLETA,
    MAL_ELABORADA
};

TIPO_FRASE analisarTipoDaFrase(const string &frase);

int main (void) {
    int N;

    cin >> N;
    cin.ignore(1); //skip \n

    while (N-- > 0) {
        string frase;
        getline(cin, frase);

        TIPO_FRASE resultado = analisarTipoDaFrase(frase);

        if (resultado == COMPLETA) {
            cout << "frase completa\n";
        }
        else if (resultado == QUASE_COMPLETA) {
            cout << "frase quase completa\n";
        }
        else {
            cout << "frase mal elaborada\n";
        }
    }

    return 0;
}

TIPO_FRASE analisarTipoDaFrase(const string &frase) {
    const int ALPHABET_SIZE = 'z' - 'a' + 1;
    vector<bool> letras(ALPHABET_SIZE, false);
    int count = 0;

    for (string::const_iterator it = frase.begin(); it != frase.end(); ++it) {
        if (isalpha(*it) && letras[*it - 'a'] == false) {
            count++;
            letras[*it - 'a'] = true;
        }
    }

    if (count == ALPHABET_SIZE) {
        return COMPLETA;
    }
    else if (count >= ALPHABET_SIZE / 2) {
        return QUASE_COMPLETA;
    }
    else {
        return MAL_ELABORADA;
    }
}
