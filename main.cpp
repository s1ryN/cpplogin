#include <iostream>
#include <string>
using namespace std;

int main() {
    const int USER_COUNT = 6;
    const int FIELD_COUNT = 4;  // 0=jméno, 1=příjmení, 2=login, 3=heslo

    // users[i][0]=firstName, [i][1]=lastName, [i][2]=login, [i][3]=password
    string users[USER_COUNT][FIELD_COUNT] = {
        {"Jan",    "Novák",    "jnovak",    "heslo123"},
        {"Petra",  "Svobodová","psvoboda",  "tajne456"},
        {"Pavel",  "Dvořák",   "pdvorak",   "pass789"},
        {"Lucie",  "Králová",  "lkralova",  "xyz321"},
        {"Martin", "Černý",    "mcerny",    "abc987"},
        {"Eva",    "Benešová",  "ebenesova", "qwerty"}
    };

    int attempts = 3;
    string inputLogin, inputPassword;
    bool authenticated = false;

    // Pokusy na přihlášení
    while (attempts > 0 && !authenticated) {
        cout << "Zadejte login: ";
        cin  >> inputLogin;
        cin  >> inputLogin;
        cout << "Zadejte heslo: ";
        cin  >> inputPassword;

        // Prohledáme všechny uživatele
        for (int i = 0; i < USER_COUNT; ++i) {
            if (users[i][2] == inputLogin && users[i][3] == inputPassword) {
                // pokud login a heslo sedí, přivítáme uživatele
                cout << "Vítej, "
                     << users[i][0] << " "
                     << users[i][1] << "!"
                     << endl;
                authenticated = true;
                break;
            }
        }

        if (!authenticated) {
            --attempts;
            if (attempts > 0) {
                cout << "Neplatné přihlašovací údaje. Zbývá pokusů: "
                     << attempts << "." << endl;
            }
        }
    }

    if (!authenticated) {
        cout << "Byl vyčerpán počet pokusů. Program končí." << endl;
    }

    return 0;
}
