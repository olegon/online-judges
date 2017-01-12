/*
Indentador
https://www.urionlinejudge.com.br/judge/pt/problems/view/2314
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void print_ident(int lvl);

int main(void) {
    ios::sync_with_stdio(false);

    string line;
    while (getline(cin, line)) {
      if (line[0] == '#') {
         cout << line << '\n';
         continue;
      }

      int ident_level = 0;
      bool new_line = false;

      for (const char *str = line.c_str(); *str != '\0'; str++) {
        if (new_line) {

          if (*str == '}') {
            // nothing to do
          }
          else {
            cout << '\n';
            print_ident(ident_level);
          }

          new_line = false;
        }

        if (*str == '{') {
          cout << '\n';
          print_ident(ident_level);
          cout << '{';
          cout << '\n';
          print_ident(++ident_level);
        }
        else if (*str == '}') {
          cout << '\n';
          print_ident(--ident_level);
          cout << '}';

          new_line = true;
        }
        else if (*str == ';') {
          cout << *str;
          new_line = true;
        }
        else if (strncmp("for(", str, 4) == 0) {
          while (*str != ')') {
            cout << *str;
            str++;
          }
          cout << ')';
        }
        else {
          cout << *str;
        }
      }

      cout << '\n';
    }

    return 0;
}

void print_ident(int lvl) {
  while (lvl-- > 0) {
    cout << "....";
  }
}
