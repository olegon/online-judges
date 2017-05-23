/*
Movimentos do Cavalo
https://www.urionlinejudge.com.br/judge/pt/problems/view/1100
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <climits>
#include <utility>
#include <queue>

using namespace std;

int howManyMoves(const string &c1, const string &c2);
pair<int, int> getPosition(const string &c);
void knightMove(const pair<int, int> &c, int dx, int dy, vector< vector<int> > &mat, queue< pair<int, int> > &toVisit);

int main(void) {
    ios::sync_with_stdio(false);

    string c1, c2;

    while (cin >> c1 >> c2) {
        cout << "To get from " << c1 << " to " << c2 << " takes " << howManyMoves(c1, c2) << " knight moves.\n";
    }

    return EXIT_SUCCESS;
}

int howManyMoves(const string &c1, const string &c2) {
    vector< vector<int> > mat(8, vector<int>(8, INT_MAX));
    queue< pair<int, int> > toVisit;
    pair<int, int> o = getPosition(c1);
    pair<int, int> d = getPosition(c2);

    // cout << o.first << ", " << o.second << endl;
    // cout << d.first << ", " << d.second << endl;

    toVisit.push(o);

    mat[o.first][o.second] = 0;

    while (!toVisit.empty()) {
        pair<int, int> c = toVisit.front();
        toVisit.pop();

        // cout << c.first << ", " << c.second << " -> " << mat[c.first][c.second] << endl;

        knightMove(c, +1, +2, mat, toVisit);
        knightMove(c, +2, +1, mat, toVisit);
        knightMove(c, +2, -1, mat, toVisit);
        knightMove(c, +1, -2, mat, toVisit);
        knightMove(c, -1, +2, mat, toVisit);
        knightMove(c, -2, +1, mat, toVisit);
        knightMove(c, -2, -1, mat, toVisit);
        knightMove(c, -1, -2, mat, toVisit);

        if (mat[d.first][d.second] != INT_MAX) break;
    }    

    return mat[d.first][d.second];
}

pair<int, int> getPosition(const string &c) {
    return make_pair(c[0] - 'a', c[1] - '1');
}

void knightMove(const pair<int, int> &c, int dx, int dy, vector< vector<int> > &mat, queue< pair<int, int> > &toVisit) {
    int nx = c.first + dx,
        ny = c.second + dy;
        
    if (nx > -1 && nx < 8 && ny > -1 && ny < 8 && mat[nx][ny] == INT_MAX) {
        mat[nx][ny] = mat[c.first][c.second] + 1;
        toVisit.push(make_pair(nx, ny));
    }
}