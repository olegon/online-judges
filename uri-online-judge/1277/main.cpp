/*
Pouca Frequência
https://www.urionlinejudge.com.br/judge/pt/problems/view/1277
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Aluno {
    string nome;
    int presencas, ausencias, atestados;
    double frequencia;
};

int main(void) {
    ios::sync_with_stdio(false);

    int T;

    cin >> T;

    while (T-- > 0) {
        int N;
        vector<Aluno*> alunos;

        cin >> N >> ws;

        for (int i = 0; i < N; i++) {
            Aluno *aluno = new Aluno();

            cin >> aluno->nome;
            aluno->presencas = aluno->ausencias = aluno->atestados = 0;

            alunos.push_back(aluno);
        }

        bool needsSpace = false;
        for (int i = 0; i < N; i++) {
            string diario;

            cin >> diario;

            for (char dia : diario) {
                if (dia == 'P') alunos[i]->presencas++;
                else if (dia == 'A') alunos[i]->ausencias++;
                else if (dia == 'M') alunos[i]->atestados++;
            }

            alunos[i]->frequencia = 1.0 * alunos[i]->presencas / (alunos[i]->presencas + alunos[i]->ausencias);

            if (alunos[i]->frequencia < 0.75) {
                if (needsSpace) cout << ' ';
                 
                 cout << alunos[i]->nome;

                 needsSpace = true;
            }
        }

        cout << '\n';
    }

    return EXIT_SUCCESS;
}
