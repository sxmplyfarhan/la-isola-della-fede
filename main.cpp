#include "Menu.h"
#include "Settings.h"
#include "Utils.h"
#include <iostream>
using namespace std;

int main() {
    while (true) {
        int selected = showMenu();
        clearScreen();

        switch (selected) {
            case 0: {
                Settings s;
                string playerName = s.get("player_name", "Player");
                string difficulty = s.get("difficulty", "Normal");
                cout << "Starting game for " << playerName
                     << " at " << difficulty << " difficulty...\n";
                getch_compat();
                break;
            }
            case 1:
                cout << "Credits coming soon!\n";
                getch_compat();
                break;
            case 2: {
                Settings s;
                s.showMenu();
                break;
            }
        }
    }
}
