/*
Espiral Quadrada
https://www.urionlinejudge.com.br/judge/pt/problems/view/1868
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void imprimir(vector< vector<bool> > &mat);

int main(void) {
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N, N != 0) {
        int i = N / 2,
            j = N / 2;
            
        vector< vector<bool> > mat(N, vector<bool>(N, false));

        mat[i][j] = true;
        imprimir(mat);

        for (int step = 1; step < N; step += 2) {
            // cout << "i: " << i << "\nj: " << j << endl;            
            
            // right;
            mat[i][j] = false;
            mat[i][++j] = true;
            // cout << "i: " << i << "\nj: " << j << endl;
            imprimir(mat);
            
            // up
            for (int u = 0; u < step; u++) {
                mat[i][j] = false;
                mat[--i][j] = true;
                
                // cout << "i: " << i << "\nj: " << j << endl;
                imprimir(mat);
            }

            // left
            for (int l = 0; l <= step; l++) {
                mat[i][j] = false;
                mat[i][--j] = true;
                
                // cout << "i: " << i << "\nj: " << j << endl;
                imprimir(mat);
            }

            // down
            for (int d = 0; d <= step; d++) {
                mat[i][j] = false;
                mat[++i][j] = true;
                
                // cout << "i: " << i << "\nj: " << j << endl;
                imprimir(mat);
            }

            // right
            for (int r = 0; r <= step; r++) {
                mat[i][j] = false;
                mat[i][++j] = true;
                
                // cout << "i: " << i << "\nj: " << j << endl;
                imprimir(mat);
            }
        }
    }

    return EXIT_SUCCESS;
}

void imprimir(vector< vector<bool> > &mat) {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            cout << (mat[i][j] ? 'X' : 'O');
        }
        cout << '\n';
    }
    cout << "@\n";
}