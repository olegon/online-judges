#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    string line;

    while (getline(cin, line)) {
        string word;
        stringstream line_stream(line);

        int count = 0;
        char a_character = '\0';
        char b_character = '\0';

        while (line_stream >> word) {
            auto first_character = toupper(word.front());

            if (a_character != first_character && b_character == first_character) {
                count++;
            }

            a_character = b_character;
            b_character = first_character;
        }

        cout << count << endl;
    }

    return 0;
}
