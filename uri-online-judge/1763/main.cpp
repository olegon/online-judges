/*
Tradutor do Papai Noel
https://www.urionlinejudge.com.br/judge/pt/problems/view/1763
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);

    unordered_map<string, string> entries = {
        { "brasil",         "Feliz Natal!" },
        { "alemanha",       "Frohliche Weihnachten!" },
        { "austria",        "Frohe Weihnacht!" },
        { "coreia",         "Chuk Sung Tan!" },
        { "espanha",        "Feliz Navidad!" },
        { "grecia",         "Kala Christougena!" },
        { "estados-unidos", "Merry Christmas!" },
        { "inglaterra",     "Merry Christmas!" },
        { "australia",      "Merry Christmas!" },
        { "portugal",       "Feliz Natal!" },
        { "suecia",         "God Jul!" },
        { "turquia",        "Mutlu Noeller" },
        { "argentina",      "Feliz Navidad!" },
        { "chile",          "Feliz Navidad!" },
        { "mexico",         "Feliz Navidad!" },
        { "antardida",      "Merry Christmas!" },
        { "canada",         "Merry Christmas!" },
        { "irlanda",        "Nollaig Shona Dhuit!" },
        { "belgica",        "Zalig Kerstfeest!" },
        { "italia",         "Buon Natale!" },
        { "libia",          "Buon Natale!" },
        { "siria",          "Milad Mubarak!" },
        { "marrocos",       "Milad Mubarak!" },
        { "japao",          "Merii Kurisumasu!" }
    };

    string line;

    while (getline(cin, line)) {
        auto entry = entries.find(line);

        if (entry == entries.end()) {
            cout << "--- NOT FOUND ---" << endl;
        }
        else {
            cout << entry->second << endl;
        }
    }

    return EXIT_SUCCESS;
}
