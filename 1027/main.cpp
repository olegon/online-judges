/*
Onda Crítica
https://www.urionlinejudge.com.br/judge/pt/problems/view/1027
*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int go(vector<ii> &points, const ii &considerado, size_t i) {
  if (i == points.size()) {
    return 0;
  }
  else if (considerado.first != points[i].first
    && (considerado.second == -1 && points[i].second == 1 || considerado.second == 1 && points[i].second == -1)) {
    // cout << "Match:\n";
    // cout << considerado.first << ' ' << considerado.second << '\n';
    // cout << points[i].first << ' ' << points[i].second << '\n';
    // cout << "###\n\n";

    int a = go(points, considerado, i + 1) + 1;
    int b = go(points, points[i], i + 1);

    return max(a, b);
  }
  else {
    return max(go(points, considerado, i + 1), go(points, points[i], i + 1));
  }
}

int go(vector<ii> &points) {
  if (points.size() < 2) return 0;
  else return go(points, points[0], 1);
}


int main(void) {
    ios::sync_with_stdio(false);

    int N;

    while (cin >> N) {
      vector<ii> points;

      for (int i = 0; i < N; i++) {
        int X, Y;

        cin >> X >> Y;

        points.push_back(make_pair(X, Y));
      }

      sort(points.begin(), points.end(), [](const ii &a, const ii &b) -> bool {
        if (a.first == b.first) {
          return a.second < b.second;
        }
        else {
          return a.first < b.first;
        }
      });

      for (auto point : points) {
        // cout << point.first << ' ' << point.second << '\n';
      }

      cout << go(points) << endl;
    }

    return 0;
}
