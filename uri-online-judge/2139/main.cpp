/*
Natal de Pedrinho
https://www.urionlinejudge.com.br/judge/pt/problems/view/2139
*/

#include <iostream>

using namespace std;

int diasProNatal(int mes, int dia);
const int diasPorMes[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(void) {
  ios::sync_with_stdio(false);

  int M, D;

  while (cin >> M >> D) {
    int dias = diasProNatal(M, D);

    if (dias == 0) {
      cout << "E natal!\n";
    }
    else if (dias == 1) {
      cout << "E vespera de natal!\n";
    }
    else if (dias < 0) {
      cout << "Ja passou!\n";
    }
    else {
      cout << "Faltam " << dias << " dias para o natal!\n";
    }
  }


  return 0;
}

int diasProNatal(int mes, int dia) {
  if (mes == 12 && dia == 25) return 0;
  else if (mes == 12 && dia > 25) return 25 - dia;
  else if (dia < 25) return (25 - dia) + diasProNatal(mes, 25);
  else if (dia > 25) return (diasPorMes[mes] - dia + 1) + diasProNatal(mes + 1, 1);
  else return diasPorMes[mes] + diasProNatal(mes + 1, dia);
}
