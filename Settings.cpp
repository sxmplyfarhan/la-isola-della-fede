#include "Utils.h"
#include "Settings.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif
using namespace std;

Settings::Settings(const string &file) : filename(file) { load(); }

void Settings::load() {
    settings.clear();
    ifstream in(filename);
    if (!in.is_open()) {
        settings["player_name"] = "Giocatore";
        settings["difficulty"] = "Normal";
        savedState = settings;
        return;
    }
    string line;
    while (getline(in, line)) {
        size_t pos = line.find('=');
        if (pos != string::npos)
            settings[line.substr(0, pos)] = line.substr(pos + 1);
    }
    savedState = settings;
}

void Settings::save() {
    ofstream out(filename);
    for (auto &p : settings)
        out << p.first << "=" << p.second << "\n";
    savedState = settings;
}

bool Settings::hasUnsavedChanges() { return settings != savedState; }

void Settings::set(const string &key, const string &value) { settings[key] = value; }

string Settings::get(const string &key, const string &defaultVal) {
    return settings.count(key) ? settings[key] : defaultVal;
}

bool Settings::confirmExit() {
    vector<string> options = {"SI", "NO"};
    int choice = 1;
    int key;

    while (true) {
        clearScreen();
        auto term = getTerminalSize();
        int rows = term.first;
        int topPadding = rows / 3;
        for (int i = 0; i < topPadding; i++) cout << endl;
        cout << "  \033[35mSei sicuro che vuoi uscire senza salvare?\033[0m\n\n";

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
            return (options[choice] == "SI");
        }
    }
}

void Settings::showMenu() {
#if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
#endif

    vector<string> options = {"NOME GIOCATORE", "DIFFICOLTÀ", "SALVA", "INDIETRO"};
    int choice = 0;
    int key;

    vector<string> title = {
"██╗███╗   ███╗██████╗  ██████╗ ███████╗████████╗ █████╗ ███████╗██╗ ██████╗ ███╗   ██╗██╗",
"██║████╗ ████║██╔══██╗██╔═══██╗██╔════╝╚══██╔══╝██╔══██╗╚══███╔╝██║██╔═══██╗████╗  ██║██║",
"██║██╔████╔██║██████╔╝██║   ██║███████╗   ██║   ███████║  ███╔╝ ██║██║   ██║██╔██╗ ██║██║",
"██║██║╚██╔╝██║██╔═══╝ ██║   ██║╚════██║   ██║   ██╔══██║ ███╔╝  ██║██║   ██║██║╚██╗██║██║",
"██║██║ ╚═╝ ██║██║     ╚██████╔╝███████║   ██║   ██║  ██║███████╗██║╚██████╔╝██║ ╚████║██║",
"╚═╝╚═╝     ╚═╝╚═╝      ╚═════╝ ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝"
    };

    while (true) {
        clearScreen();
        auto term = getTerminalSize();
        int rows = term.first;
        int topPadding = rows / 4;
        for (int i = 0; i < topPadding; i++) cout << endl;

        for (auto &line : title) cout << "\033[35m  " << line << "\033[0m" << endl;
        cout << endl << endl;

        for (int i = 0; i < (int)options.size(); i++) {
            string line;
            if (options[i] == "NOME GIOCATORE")
                line = options[i] + ": " + get("player_name", "Giocatore");
            else if (options[i] == "DIFFICOLTÀ") {
                string cur = get("difficulty", "Normal");
                if (cur == "Easy") cur = "Facile";
                else if (cur == "Normal") cur = "Normale";
                else if (cur == "Hard") cur = "Difficile";
                line = options[i] + ": " + cur;
            } else
                line = options[i];

            cout << "    ";
            if (i == choice) cout << "\033[1;35m"; else cout << "\033[97m";
            cout << line << "\033[0m\n\n";
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
            if (options[choice] == "INDIETRO") {
                if (hasUnsavedChanges()) {
                    bool confirm = confirmExit();
                    if (confirm) return;
                } else return;
            } else if (options[choice] == "SALVA") {
                save();
            } else if (options[choice] == "NOME GIOCATORE") {
                cout << "\033[0mInserisci Nome Giocatore: ";
                string name;
                getline(cin >> ws, name);
                if (!name.empty()) set("player_name", name);
            } else if (options[choice] == "DIFFICOLTÀ") {
                vector<pair<string, string>> levels = {
                    {"Easy", "Facile"}, {"Normal", "Normale"}, {"Hard", "Difficile"}};
                string current = get("difficulty", "Normal");
                int idx = 1;
                for (int i = 0; i < (int)levels.size(); i++)
                    if (levels[i].first == current) idx = i;
                idx = (idx + 1) % levels.size();
                set("difficulty", levels[idx].first);
            }
        }
    }
}
