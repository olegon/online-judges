#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

#define G 9.80665
#define PI 3.14159

double obter_tempo_do_projetil_em_y_0(double h, double vy);

int main(void) {
    ios::sync_with_stdio(false);

    double H;
    while (cin >> H) {
        int P1, P2;
        int N;

        cin >> P1 >> P2;

        cin >> N;

        while (N-- > 0) {
            double A, V;

            cin >> A >> V;

            double angulo = A / 180.0 * PI;

            double VY = sin(angulo) * V;
            double VX = cos(angulo) * V;

            double t = obter_tempo_do_projetil_em_y_0(H, VY);

            double X = VX * t;

            cout << fixed;
            cout << setprecision(5) << X << " -> ";

            if (X >= P1 && X <= P2) cout << "DUCK\n";
            else cout << "NUCK\n";
        }
    }

    return 0;
}

double obter_tempo_do_projetil_em_y_0(double h, double vy) {
    double dt = pow(vy, 2) + 2 * h * G;

    double dt_sqrt = sqrt(dt);

    double t1 = (vy + dt_sqrt) / G;
    double t2 = (vy - dt_sqrt) / G;

    return max(t1, t2);
}
