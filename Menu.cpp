#include "Utils.h"
#include "Menu.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif
using namespace std;

vector<string> getBigTitle() {
    return {
"██╗      █████╗     ██╗███████╗ ██████╗ ██╗      █████╗                     ",
"██║     ██╔══██╗    ██║██╔════╝██╔═══██╗██║     ██╔══██╗                    ",
"██║     ███████║    ██║███████╗██║   ██║██║     ███████║                    ",
"██║     ██╔══██║    ██║╚════██║██║   ██║██║     ██╔══██║                    ",
"███████╗██║  ██║    ██║███████║╚██████╔╝███████╗██║  ██║                    ",
"╚══════╝╚═╝  ╚═╝    ╚═╝╚══════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝                    ",
"                                                                            ",
"██████╗ ███████╗██╗     ██╗      █████╗     ███████╗███████╗██████╗ ███████╗",
"██╔══██╗██╔════╝██║     ██║     ██╔══██╗    ██╔════╝██╔════╝██╔══██╗██╔════╝",
"██║  ██║█████╗  ██║     ██║     ███████║    █████╗  █████╗  ██║  ██║█████╗  ",
"██║  ██║██╔══╝  ██║     ██║     ██╔══██║    ██╔══╝  ██╔══╝  ██║  ██║██╔══╝  ",
"██████╔╝███████╗███████╗███████╗██║  ██║    ██║     ███████╗██████╔╝███████╗",
"╚═════╝ ╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝    ╚═╝     ╚══════╝╚═════╝ ╚══════╝"
    };
}

vector<vector<string>> getMenuOptions() {
    return {{"GIOCA"}, {"CREDITI"}, {"IMPOSTAZIONI"}, {"ESCI"}};
}

bool confirmExitMenu() {
    vector<string> options = {"Sì", "No"};
    int choice = 1;
    int key;

    while (true) {
        clearScreen();
        auto term = getTerminalSize();
        int rows = term.first;
        for (int i = 0; i < rows / 4; i++) cout << endl;
        cout << "  \033[35mSei sicuro di voler uscire?\033[0m\n\n";

        for (int i = 0; i < (int)options.size(); i++) {
            cout << "    " << (i == choice ? "\033[1;35m" : "\033[97m")
                 << options[i] << "\033[0m\n\n";
        }

        key = getch_compat();

        
        if (key == 27) {
            char k1 = getch_compat();
            if (k1 == '[') {
                char k2 = getch_compat();
                if (k2 == 'A' && choice > 0) choice--;
                else if (k2 == 'B' && choice < (int)options.size() - 1) choice++;
            }
        }
        
#if defined(_WIN32) || defined(_WIN64)
        else if (key == 0 || key == 224) {
            key = getch_compat();
            if (key == 72 && choice > 0) choice--;             
            else if (key == 80 && choice < (int)options.size() - 1) choice++; 
        }
#endif
        else if (key == 10 || key == 13) {
            if (choice == 0) {
                clearScreen();
                cout << "\n\n\n    \033[1;35mArrivederci, ritorna da noi amore\033[0m\n\n\n";
                sleepMs(500);
                return true;
            }
            return false;
        }
    }
}

int showMenu() {
#if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
#endif

    vector<vector<string>> options = getMenuOptions();
    int choice = 0;
    int key;

    auto termSize = getTerminalSize();
    int rows = termSize.first;
    auto title = getBigTitle();

    while (true) {
        clearScreen();
        for (int i = 0; i < rows / 4; i++) cout << endl;
        for (auto &line : title) cout << "\033[35m  " << line << "\033[0m\n";
        cout << endl;

        for (int i = 0; i < (int)options.size(); i++) {
            cout << "    " << (i == choice ? "\033[1;35m" : "\033[97m")
                 << options[i][0] << "\033[0m\n\n";
        }

        key = getch_compat();

        if (key == 27) {
            char k1 = getch_compat();
            if (k1 == '[') {
                char k2 = getch_compat();
                if (k2 == 'A' && choice > 0) choice--;
                else if (k2 == 'B' && choice < (int)options.size() - 1) choice++;
            }
        }
        
#if defined(_WIN32) || defined(_WIN64)
        else if (key == 0 || key == 224) {
            key = getch_compat();
            if (key == 72 && choice > 0) choice--;             
            else if (key == 80 && choice < (int)options.size() - 1) choice++; 
        }
#endif
        else if (key == 10 || key == 13) {
            string selected = options[choice][0];
            if (selected == "ESCI") {
                if (confirmExitMenu()) exit(0);
            } else {
                return choice;
            }
        }
    }
}
