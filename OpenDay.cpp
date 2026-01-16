#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <limits>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif
#include <time.h>
using namespace std;
// Variabili
string mob;
string mobs1[3] = {"Scimmia", "Cane", "Rana"};
string mobs2[3] = {"Pipistrello", "Farfalla", "Ragno"};
string mobs3[3] = {"Centauro", "Mietitore", "Fenice"};
string inventariospace[30];
string playerName ="Giocatore";
string difficulty = "Normale";
string infront = "w"; 
string sinistra = "a";
string destra ="d";
string indietro = "s";
string pieta = "r";
string scappare = "l";
string attaccare = "q";
double vita = 5.0;
double vitaMax = 5.0;
int nemiciUccisi = 0;
int nemiciIncontrati = 0;
int contoNemiciUccisi = 0;
int esperienza = 1;
bool hasTotem = false;
bool hasShield = false;
bool hasGoblinKey = false; 
bool hasVampireKey = false; 
bool hasDragonKey = false;
// Funzioni per tutto il codice
void clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}
void Input(){
    cout << "\033[35m";
    cout << "\n>> ";
    cout << "\033[0m";
}
void Invio() {
    cout << "\033[90m";
    cout << "\nPremi invio per continuare...";
    cout << "\033[0m";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.clear(); 
    cin.get();   
}
void linea(){
    cout << "\033[35m";
    cout << "\n────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n";
    cout << "\033[0m";
}
//funzioni ascii per il gioco
void displayAsciiArt(const string& filename) {
    ifstream file(filename);
    char c;
    while (file.get(c)) {
        cout << c;
    }
}
void displayBoss() {
    displayAsciiArt("ASCII/boss.txt");
}
void displayCane() {
    displayAsciiArt("ASCII/cane.txt");
}
void displayCentauro() {
    displayAsciiArt("ASCII/centauro.txt");
}
void displayDragon() {
    displayAsciiArt("ASCII/dragoboss.txt");
}
void displayFarfalla() {
    displayAsciiArt("ASCII/farfalla.txt");
}
void displayFenice() {
    displayAsciiArt("ASCII/fenice.txt");
}
void displayRana() {
    displayAsciiArt("ASCII/rana.txt");
}
void displayGoblinKing() {
    displayAsciiArt("ASCII/goblinking.txt");
}
void displayReaper() {
    displayAsciiArt("ASCII/grimreaper.txt");
}
void displayIsola() {
    displayAsciiArt("ASCII/isola.txt");
}
void displayBat() {
    displayAsciiArt("ASCII/pipistrelli.txt");
}
void displayRagni() {
    displayAsciiArt("ASCII/ragni.txt");
}
void displayScimmie() {
    displayAsciiArt("ASCII/scimmie.txt");
}
void displayVampireBoss() {
    displayAsciiArt("ASCII/vampiroboss.txt");
}
void displaySkull() {
    displayAsciiArt("ASCII/skull.txt");
}
void displayCamera() {
    displayAsciiArt("ASCII/camera.txt");
}
void displayChest() {
    displayAsciiArt("ASCII/chest.txt");
}
void displayTotem(){
    displayAsciiArt("ASCII/totem.txt");
}
void displayBedroom() {
    displayAsciiArt("ASCII/bedroom.txt");
}
void displaySea() {
    displayAsciiArt("ASCII/sea.txt");
}
void displayTrail() {
    displayAsciiArt("ASCII/trail.txt");
}
void displayForest() {
    displayAsciiArt("ASCII/forest.txt");
}
void displayBestfriend() {
    displayAsciiArt("ASCII/bestfriend.txt");
}
void displayCurse() {
    displayAsciiArt("ASCII/curse.txt");
}
void displayMain() {
    displayAsciiArt("ASCII/maincharacter.txt");
}
void displayKeys() {
    displayAsciiArt("ASCII/keys.txt");
}
void displayScuro() {
    displayAsciiArt("ASCII/scuro.txt");
}
void displayPorta() {
    displayAsciiArt("ASCII/porta.txt");
}
void displayMob(const string& mob) {
    if (mob == "Boss") {
        displayBoss();
    } else if (mob == "Cane") {
        displayCane();
    } else if (mob == "Centauro") {
        displayCentauro();
    } else if (mob == "Dragon") {
        displayDragon();
    } else if (mob == "Farfalla") {
        displayFarfalla();
    } else if (mob == "Fenice") {
        displayFenice();
    } else if (mob == "Rana") {
        displayRana();
    } else if (mob == "GoblinKing") {
        displayGoblinKing();
    } else if (mob == "Mietitore") {
        displayReaper();
    } else if (mob == "Isola") {
        displayIsola();
    } else if (mob == "Pipistrello") {
        displayBat();
    } else if (mob == "Ragno") {
        displayRagni();
    } else if (mob == "Scimmia") {
        displayScimmie();
    } else if (mob == "VampireBoss") {
        displayVampireBoss();
    } 
}
// Funzione per tutti i titoli
void printTitle() {
    cout << "\033[35m";
    cout << "┌──────────────────────────────────────────────────────────────────────────────────────────┐\n";
    cout << "│                                                                                          │\n";
    cout << "│  █████        ██    █████                  ████                                          │\n";
    cout << "│ ░░███        ███   ░░███                  ░░███                                          │\n";
    cout << "│  ░███       ░░░     ░███   █████   ██████  ░███   ██████                                 │\n";
    cout << "│  ░███               ░███  ███░░   ███░░███ ░███  ░░░░░███                                │\n";
    cout << "│  ░███               ░███ ░░█████ ░███ ░███ ░███   ███████                                │\n";
    cout << "│  ░███      █        ░███  ░░░░███░███ ░███ ░███  ███░░███                                │\n";
    cout << "│  ███████████        █████ ██████ ░░██████  █████░░████████                               │\n";
    cout << "│ ░░░░░░░░░░░        ░░░░░ ░░░░░░   ░░░░░░  ░░░░░  ░░░░░░░░                                │\n";
    cout << "│                                                                                          │\n";
    cout << "│      █████          ████  ████                  ██████               █████               │\n";
    cout << "│     ░░███          ░░███ ░░███                 ███░░███             ░░███                │\n";
    cout << "│   ███████   ██████  ░███  ░███   ██████       ░███ ░░░   ██████   ███████   ██████       │\n";
    cout << "│  ███░░███  ███░░███ ░███  ░███  ░░░░░███     ███████    ███░░███ ███░░███  ███░░███      │\n";
    cout << "│ ░███ ░███ ░███████  ░███  ░███   ███████    ░░░███░    ░███████ ░███ ░███ ░███████       │\n";
    cout << "│ ░███ ░███ ░███░░░   ░███  ░███  ███░░███      ░███     ░███░░░  ░███ ░███ ░███░░░        │\n";
    cout << "│ ░░████████░░██████  █████ █████░░████████     █████    ░░██████ ░░████████░░██████       │\n";
    cout << "│  ░░░░░░░░  ░░░░░░  ░░░░░ ░░░░░  ░░░░░░░░     ░░░░░      ░░░░░░   ░░░░░░░░  ░░░░░░        │\n";
    cout << "│                                                                                          │\n";
    cout << "└──────────────────────────────────────────────────────────────────────────────────────────┘\n";
    cout << "\033[0m\n";
}
void printSettingsTitle() {
    cout << "\033[35m";
    cout << "┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n";
    cout << "│ █████                                             █████                          ███                       ███ │\n";
    cout << "│░░███                                             ░░███                          ░░░                       ░░░  │\n";
    cout << "│ ░███  █████████████   ████████   ██████   █████  ███████    ██████    █████████ ████   ██████  ████████   ████ │\n";
    cout << "│ ░███ ░░███░░███░░███ ░░███░░███ ███░░███ ███░░  ░░░███░    ░░░░░███  ░█░░░░███ ░░███  ███░░███░░███░░███ ░░███ │\n";
    cout << "│ ░███  ░███ ░███ ░███  ░███ ░███░███ ░███░░█████   ░███      ███████  ░   ███░   ░███ ░███ ░███ ░███ ░███  ░███ │\n";
    cout << "│ ░███  ░███ ░███ ░███  ░███ ░███░███ ░███ ░░░░███  ░███ ███ ███░░███    ███░   █ ░███ ░███ ░███ ░███ ░███  ░███ │\n";
    cout << "│ █████ █████░███ █████ ░███████ ░░██████  ██████   ░░█████ ░░████████  █████████ █████░░██████  ████ █████ █████│\n";
    cout << "│░░░░░ ░░░░░ ░░░ ░░░░░  ░███░░░   ░░░░░░  ░░░░░░     ░░░░░   ░░░░░░░░  ░░░░░░░░░ ░░░░░  ░░░░░░  ░░░░ ░░░░░ ░░░░░ │\n";
    cout << "│                       ░███                                                                                     │\n";
    cout << "│                       █████                                                                                    │\n";
    cout << "│                      ░░░░░                                                                                     │\n";
    cout << "└────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n";
    cout << "\033[0m\n";
}
void printCreditsTitle() {
    cout << "\033[35m";
    cout << "┌────────────────────────────────────────────────────────────┐\n";
    cout << "│                                 █████  ███   █████     ███ │\n";
    cout << "│                                ░░███  ░░░   ░░███     ░░░  │\n";
    cout << "│  ██████  ████████   ██████   ███████  ████  ███████   ████ │\n";
    cout << "│ ███░░███░░███░░███ ███░░███ ███░░███ ░░███ ░░░███░   ░░███ │\n";
    cout << "│░███ ░░░  ░███ ░░░ ░███████ ░███ ░███  ░███   ░███     ░███ │\n";
    cout << "│░███  ███ ░███     ░███░░░  ░███ ░███  ░███   ░███ ███ ░███ │\n";
    cout << "│░░██████  █████    ░░██████ ░░████████ █████  ░░█████  █████│\n";
    cout << "│ ░░░░░░  ░░░░░      ░░░░░░   ░░░░░░░░ ░░░░░    ░░░░░  ░░░░░ │\n";
    cout << "└────────────────────────────────────────────────────────────┘\n";
    cout << "\033[0m\n";
}
void printIntroductionTitle(){
    cout << "\033[35m";
    cout << "┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n";
    cout << "│  ███              █████                           █████                        ███                              │\n";
    cout << "│ ░░░              ░░███                           ░░███                        ░░░                               │\n";
    cout << "│ ████  ████████   ███████   ████████   ██████   ███████  █████ ████  █████████ ████   ██████  ████████    ██████ │\n";
    cout << "│░░███ ░░███░░███ ░░░███░   ░░███░░███ ███░░███ ███░░███ ░░███ ░███  ░█░░░░███ ░░███  ███░░███░░███░░███  ███░░███│\n";
    cout << "│ ░███  ░███ ░███   ░███     ░███ ░░░ ░███ ░███░███ ░███  ░███ ░███  ░   ███░   ░███ ░███ ░███ ░███ ░███ ░███████ │\n";
    cout << "│ ░███  ░███ ░███   ░███ ███ ░███     ░███ ░███░███ ░███  ░███ ░███    ███░   █ ░███ ░███ ░███ ░███ ░███ ░███░░░  │\n";
    cout << "│ █████ ████ █████  ░░█████  █████    ░░██████ ░░████████ ░░████████  █████████ █████░░██████  ████ █████░░██████ │\n";
    cout << "│░░░░░ ░░░░ ░░░░░    ░░░░░  ░░░░░      ░░░░░░   ░░░░░░░░   ░░░░░░░░  ░░░░░░░░░ ░░░░░  ░░░░░░  ░░░░ ░░░░░  ░░░░░░  │\n";
    cout << "└─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n";
    cout << "\033[0m\n";
}
//funzioni esperienza e vita
void livelloEsperienza() {
    if (difficulty == "Normale" ) {
            if (nemiciUccisi >= 3) {
                esperienza++;
                vita = vita + 2.5;
                vitaMax += 2.5;
                cout << "Congratulazioni, Sei arrivato al livello. " << esperienza << "\n Adesso hai Vita: " << vita ;
                nemiciUccisi = 0;
            }
    } else if (difficulty == "Facile") {
                if (nemiciUccisi >= 2) {
                    esperienza++;
                    vita = vita + 3.5;
                    vitaMax += 3.5;
                cout << "Congratulazioni, hai ottenuto più esperienza. \nEsperienza: " << esperienza << "\nVita: " << vita ;
                nemiciUccisi = 0;
            }
    } else if (difficulty == "Difficile") {
                if (nemiciUccisi >= 5) {
                    esperienza++;
                    vita = vita + 1.5;
                    vitaMax += 1.5;
                cout << "Congratulazioni, hai ottenuto più esperienza. \nEsperienza: " << esperienza << "\nVita: " << vita ;
                nemiciUccisi = 0;
            }
    }
}
void menuVita() {
    char vitaStr[20];
    snprintf(vitaStr, sizeof(vitaStr), "%.1f", vita); // 1 decimal place

    string content = string("Vita = ") + vitaStr;
    int padding = 2;
    int width = content.length() + padding * 2;

    // Top
    cout << "\033[31m┌";
    for (int i = 0; i < width; ++i) cout << "─";
    cout << "┐\033[0m\n";

    // Middle
    cout << "\033[31m│\033[0m";
    cout << string(padding, ' ') << content << string(padding, ' ');
    cout << "\033[31m│\033[0m\n";

    // Bottom
    cout << "\033[31m└";
    for (int i = 0; i < width; ++i) cout << "─";
    cout << "┘\033[0m\n";
}
void menuVitaPiuScudo() {
    char vitaStr[20];
    snprintf(vitaStr, sizeof(vitaStr), "%.1f", vita);
    string vitaContent = string("Vita = ") + vitaStr;
    string shieldContent = "Scudo = True";

    int vitaWidth = vitaContent.length() + 2;    // 1 space padding each side
    int shieldWidth = shieldContent.length() + 2;

    // Top row
    cout << "\033[31m┌";
    for (int i = 0; i < vitaWidth; ++i) cout << "─";
    cout << "┐\033[0m";
    cout << "\033[90m ┌";
    for (int i = 0; i < shieldWidth; ++i) cout << "─";
    cout << "┐\033[0m\n";

    // Middle row
    cout << "\033[31m│\033[0m " << vitaContent << " " << "\033[31m│\033[0m";
    cout << "\033[90m │ \033[0m" << shieldContent << "\033[90m │\033[0m\n";

    // Bottom row
    cout << "\033[31m└";
    for (int i = 0; i < vitaWidth; ++i) cout << "─";
    cout << "┘\033[0m";
    cout << "\033[90m └";
    for (int i = 0; i < shieldWidth; ++i) cout << "─";
    cout << "┘\033[0m\n";
}
void menuVitaPiuTotem() {
    char vitaStr[20];
    snprintf(vitaStr, sizeof(vitaStr), "%.1f", vita);
    string vitaContent = string("Vita = ") + vitaStr;
    string totemContent = "Totem = True";

    int vitaWidth = vitaContent.length() + 2;
    int totemWidth = totemContent.length() + 2;

    // Top row
    cout << "\033[31m┌";
    for (int i = 0; i < vitaWidth; ++i) cout << "─";
    cout << "┐\033[0m";
    cout << "\033[33m ┌";
    for (int i = 0; i < totemWidth; ++i) cout << "─";
    cout << "┐\033[0m\n";

    // Middle row
    cout << "\033[31m│\033[0m " << vitaContent << " " << "\033[31m│\033[0m";
    cout << "\033[33m │ \033[0m" << totemContent << " \033[33m│\033[0m\n";

    // Bottom row
    cout << "\033[31m└";
    for (int i = 0; i < vitaWidth; ++i) cout << "─";
    cout << "┘\033[0m";
    cout << "\033[33m └";
    for (int i = 0; i < totemWidth; ++i) cout << "─";
    cout << "┘\033[0m\n";
}
void menuVitaConTutto() {
    char vitaStr[20];
    snprintf(vitaStr, sizeof(vitaStr), "%.1f", vita);
    string vitaContent = string("Vita = ") + vitaStr;
    string totemContent = "Totem = True";
    string shieldContent = "Scudo = True";

    int vitaWidth = vitaContent.length() + 2;
    int totemWidth = totemContent.length() + 2;
    int shieldWidth = shieldContent.length() + 2;

    // Top row
    cout << "\033[31m┌";
    for (int i = 0; i < vitaWidth; ++i) cout << "─";
    cout << "┐\033[0m";
    cout << "\033[33m ┌";
    for (int i = 0; i < totemWidth; ++i) cout << "─";
    cout << "┐\033[0m";
    cout << "\033[90m ┌";
    for (int i = 0; i < shieldWidth; ++i) cout << "─";
    cout << "┐\033[0m\n";

    // Middle row
    cout << "\033[31m│\033[0m " << vitaContent << " " << "\033[31m│\033[0m";
    cout << "\033[33m │ \033[0m" << totemContent << "\033[33m │\033[0m";
    cout << "\033[90m │ \033[0m" << shieldContent << "\033[90m │\033[0m\n";

    // Bottom row
    cout << "\033[31m└";
    for (int i = 0; i < vitaWidth; ++i) cout << "─";
    cout << "┘\033[0m";
    cout << "\033[33m └";
    for (int i = 0; i < totemWidth; ++i) cout << "─";
    cout << "┘\033[0m";
    cout << "\033[90m └";
    for (int i = 0; i < shieldWidth; ++i) cout << "─";
    cout << "┘\033[0m\n";
}
void menuGoblinKey(){
    cout << "\033[32m";
    cout << "┌───────────────────────┐";
    cout << "\033[0m\n";
    cout << "\033[32m";
    cout << "| ";
    cout << "\033[0m";
    cout << "Chiave Goblin = True";
    cout << "\033[32m";
    cout << "  | ";
    cout << "\033[0m\n"; 
    cout << "\033[32m";
    cout << "└───────────────────────┘";
    cout << "\033[0m\n";
}
void menuTutteChiavi(){
    cout << "\033[32m";
    cout << "┌───────────────────────┐";
    cout << "\033[0m";
    cout << "\033[35m";
    cout << " ┌───────────────────────┐";
    cout << "\033[0m";
    cout << "\033[91m";
    cout << " ┌───────────────────────┐";
    cout << "\033[0m";
    cout << "\033[32m\n";
    cout << "| ";
    cout << "\033[0m";
    cout << "Chiave Goblin = True";
    cout << "\033[32m";
    cout << "  |";
    cout << "\033[0m"; 
    cout << "\033[35m";
    cout << " | ";
    cout << "\033[0m"; 
    cout << "Chiave Vampiro = True";
    cout << "\033[35m";
    cout << " | ";
    cout << "\033[0m"; 
    cout << "\033[91m";
    cout << "| ";
    cout << "\033[0m"; 
    cout << "Chiave Dragone = True";
    cout << "\033[91m";
    cout << " | ";
    cout << "\033[0m\n"; 
    cout << "\033[32m";
    cout << "└───────────────────────┘";
    cout << "\033[0m";
    cout << "\033[35m";
    cout << " └───────────────────────┘";
    cout << "\033[0m";
    cout << "\033[91m";
    cout << " └───────────────────────┘";
    cout << "\033[0m\n";
}
void menuVampiroPiuGoblin(){
    cout << "\033[32m";
    cout << "┌───────────────────────┐";
    cout << "\033[0m";
    cout << "\033[35m";
    cout << " ┌───────────────────────┐";
    cout << "\033[0m";
    cout << "\033[32m\n";
    cout << "| ";
    cout << "\033[0m";
    cout << "Chiave Goblin = True";
    cout << "\033[32m";
    cout << "  |";
    cout << "\033[0m"; 
    cout << "\033[35m";
    cout << " | ";
    cout << "\033[0m"; 
    cout << "Chiave Vampiro = True";
    cout << "\033[35m";
    cout << " | ";
    cout << "\033[0m"; 
    cout << "\033[32m\n";
    cout << "└───────────────────────┘";
    cout << "\033[0m";
    cout << "\033[35m";
    cout << " └───────────────────────┘";
    cout << "\033[0m\n";
}
void scegliMenu(){
    if (hasTotem == true && hasShield == true) {
        menuVitaConTutto();
    } else if (hasTotem == true) {
        menuVitaPiuTotem();
    } else if (hasShield == true) {
        menuVitaPiuScudo();
    } else {
        menuVita();
    }
    if (hasGoblinKey == true && hasVampireKey == true && hasDragonKey == true) {
        menuTutteChiavi();
    } else if (hasGoblinKey == true && hasVampireKey == true) {
        menuVampiroPiuGoblin();
    } else if (hasGoblinKey == true) {
        menuGoblinKey();
    }
}
void applyDamage(double damage, bool isBoss = false) {
    if (!isBoss && hasShield) {   // shield works only if it's not a boss
        int chance = rand() % 2; 
        if (chance == 0) {
            cout << "\nIl tuo scudo blocca completamente il danno!" << endl;
            hasShield = false; 
            Invio();
            return; 
        } else {
            cout << "\nLo scudo non riesce a bloccare il danno..." << endl;
            hasShield = false; 
        }
    }

    vita -= damage;

    if (vita <= 0.01 && hasTotem) {
        clearScreen();
        scegliMenu();
        displayTotem();
        linea();
        cout << "\nIl tuo totem si illumina! Ti salva dalla morte..." << endl;
        vita = vitaMax; 
        hasTotem = false;
        return;
    }

    if (vita <= 0.01) {
        clearScreen();
        displaySkull();
        cout << "\nGame Over! Hai perso tutta la tua vita..." << endl;
        Invio();
        exit(0);
    }
}
//funzioni per quando vai avanti. RANDOM
void niente(){
    cout << "Non hai trovato niente";
    Invio();
}
void apriChest() {
    clearScreen();
    scegliMenu();
    displayChest();
    linea();
    cout << "Hai trovato un forziere misterioso..." << endl;
    Invio();

    int chance = rand() % 100; 

    if (chance < 20) {
        cout << "Il forziere è vuoto... che delusione." << endl;
        Invio();
    } else {
        int itemType = rand() % 6; 
        switch (itemType) {
            case 0: { 
                cout << "Hai trovato una pozione di cura!" << endl;
                double heal = 3.0;
                vita += heal;
                cout << "Ti senti meglio. + " << heal << " vita. (Totale: " << vita << ")" << endl;
                Invio();
                break;
            }
            case 1: { 
                cout << "Hai bevuto una pozione strana... era avvelenata! (-2.0 Della tua vita originale!)" << endl;
                applyDamage(2.0);
                Invio();
                break;
            }
            case 2: { 
                cout << "Hai trovato una pozione nera... la tocchi e senti il gelo della morte!" << endl;
                if (hasTotem) {
                    cout << "Il tuo totem si illumina e ti salva dalla morte certa!" << endl;
                    hasTotem = false;
                } else {
                    Invio();
                    applyDamage(1000000000.0);
                }
                Invio();
                break;
            }
            case 3: { 
                if (hasTotem) {
                    cout << "Hai trovato un altro totem... ma ne hai già uno attivo. Lo lasci dove sta." << endl;
                } else {
                    cout << "Hai trovato un totem della seconda vita!" << endl;
                    hasTotem = true;
                    cout << "Ora sarai salvato una volta se muori." << endl;
                }
                Invio();
                break;
            }
            case 4: { 
                cout << "Hai trovato della frutta fresca!" << endl;
                double heal = 1.5;
                vita += heal;
                cout << "Ti cura leggermente. + " << heal << " vita. (Totale: " << vita << ")" << endl;
                Invio();
                break;
            }
            case 5: { 
                if (hasShield) {
                    cout << "Hai trovato uno scudo... ma ne hai già uno. Lo lasci per non appesantirti." << endl;
                } else {
                    cout << "Hai trovato uno scudo magico!" << endl;
                    hasShield = true;
                    cout << "50% di probabilità di bloccare il prossimo danno." << endl;
                }
                Invio();
                break;
            }
        }
    }
    linea();
}
//funzioni combattimento con difficolta "Facile/Normale/Difficile"
void combattimentoFacile(int livello, int &nemiciUccisi, string mobs[3]){
    clearScreen();
    string scelta;
    string mob = mobs[rand() % 3];
    if (livello == 2 && mob == "Farfalla") {
        scegliMenu();
        displayMob(mob);
        linea();
    cout << "Sei stato fortunato, la farfalla ti cura!" << endl;
    Invio();
    vita += 4;
    return; 
}
    else{
        scegliMenu();
        displayMob(mob);
        linea();
        nemiciIncontrati++;
        cout << "Hai incontrato : " << mob << "!" << endl;
        cout << "Vuoi attaccare (premi '" << attaccare << "'), essere misericordioso (premi '" << pieta << "') o scappare (premi '" << scappare << "')? ";
        Input();
        cin >> scelta;
        if (scelta == attaccare) {
            cout << "Hai attaccato : " << mob << " e lo hai sconfitto!" << endl;
            nemiciUccisi++;
            contoNemiciUccisi++;
            cout << "Hai perso della vita...";
            applyDamage(1.0);
            livelloEsperienza();
        } else if (scelta == pieta) {
            cout << "Sei stato misericordioso con : " << mob << " e lo hai lasciato andare.Tuttavia prendi del danno :(" << endl;
            applyDamage(1.0);
        } else if (scelta == scappare) {
        cout << "Sei scappato da : " << mob << " per curarti." << endl;
        } else {
            cout << "Scelta non valida. " << mob << " ti ha attaccato mentre eri indeciso!" << endl;
            applyDamage(3.0);
        }
    }
    Invio();
}
void combattimentoDifficile(int livello, int &nemiciUccisi, string mobs[3]){
    clearScreen();
    string scelta;
    string mob = mobs[rand() % 3];
    if (livello == 2 && mob == "Farfalla") {
        scegliMenu();
        displayMob(mob);
        linea();
    cout << "Sei stato fortunato, la farfalla ti cura!" << endl;
    Invio();
    vita += 0.5;
    return; // finisce il combattimento
}
    else{
        scegliMenu();
        displayMob(mob);
        linea();
        nemiciIncontrati++;
        cout << "Hai incontrato : " << mob << "!" << endl;
        cout << "Vuoi attaccare (premi '" << attaccare << "'), essere misericordioso (premi '" << pieta << "') o scappare (premi '" << scappare << "')? ";
        Input();
        cin >> scelta;
        if (scelta == attaccare) {
            cout << "Hai attaccato : " << mob << " e lo hai sconfitto!" << endl;
            nemiciUccisi++;
            contoNemiciUccisi++;
            cout << "Hai perso della vita...";
            applyDamage(3.0);
            livelloEsperienza();
        } else if (scelta == pieta) {
            cout << "Sei stato misericordioso con : " << mob << " e lo hai lasciato andare.Tuttavia prendi del danno :(" << endl;
            applyDamage(4.0);
        } else if (scelta == scappare) {
        cout << "Sei scappato da : " << mob << " per curarti." << endl;
        } else {
            cout << "Scelta non valida. " << mob << " ti ha attaccato mentre eri indeciso!" << endl;
            applyDamage(9.0);
        }
    }
    Invio();
}
void combattimentoNormale(int livello, int &nemiciUccisi, string mobs[3]){
    clearScreen();
    string scelta;
    string mob = mobs[rand() % 3];
    if (livello == 2 && mob == "Farfalla") {
        scegliMenu();
        displayMob(mob);
        linea();
    cout << "Sei stato fortunato, la farfalla ti cura!" << endl;
    vita += 3;
    Invio();
    return; // finisce il combattimento
}
    else{
        scegliMenu();
        displayMob(mob);
        linea();
        nemiciIncontrati++;
        cout << "Hai incontrato : " << mob << "!" << endl;
        cout << "Vuoi attaccare (premi '" << attaccare << "'), essere misericordioso (premi '" << pieta << "') o scappare (premi '" << scappare << "')? ";
        Input();
        cin >> scelta;
        if (scelta == attaccare) {
            cout << "Hai attaccato : " << mob << " e lo hai sconfitto!" << endl;
            nemiciUccisi++;
            contoNemiciUccisi++;
            cout << "Hai perso della vita...";
            applyDamage(1.5);
            livelloEsperienza();
        } else if (scelta == pieta) {
            cout << "Sei stato misericordioso con : " << mob << " e lo hai lasciato andare.Tuttavia prendi del danno :(" << endl;
            applyDamage(2.0);
        } else if (scelta == scappare) {
        cout << "Sei scappato da : " << mob << " per curarti." << endl;
        } else {
            cout << "Scelta non valida. " << mob << " ti ha attaccato mentre eri indeciso!" << endl;
            applyDamage(6.0);
        }
    }
    Invio();
}
void combattimento(int livello, int &nemiciUccisi, string mobs[3]) {
    if (difficulty == "Facile"){
        combattimentoFacile(livello, nemiciUccisi, mobs);
    }
    else if (difficulty == "Normale"){
        combattimentoNormale(livello, nemiciUccisi, mobs);
    }
    else if (difficulty == "Difficile"){
        combattimentoDifficile(livello, nemiciUccisi, mobs);
    }
}
// Combattimento Tutti i boss 
void combattimentoGoblinKing() {
    double toglivita = vita/3.0;
    char scelta;

    clearScreen();
    scegliMenu();
    displayGoblinKing();
    linea();
    cout << "1. Chi ha preso il primo premio Nobel per l’informatica?" << endl;
    cout << "A. Alan Turing" << endl;
    cout << "B. Bill Gates" << endl;
    cout << "C. Non c’è un premio nobel per l’informatica" << endl;
    cout << "D. John von Neumann" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'C' || scelta == 'c') {
        cout << "Hai risposto correttamente..\nChe fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/3 della tua vita.." << endl;
        applyDamage(toglivita, true);
    }

    Invio();

    clearScreen();
    scegliMenu();
    displayGoblinKing();
    linea();
    cout << "2. Quanti linguaggi di programmazione esistono?" << endl;
    cout << "A. Esistono più di 100 linguaggi di programmazione" << endl;
    cout << "B. Esistono più di 700 linguaggi di programmazione" << endl;
    cout << "C. Ci sono circa 10 di linguaggi di programmazione" << endl;
    cout << "D. Esiste un solo linguaggio di programmazione ed è universale" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'B' || scelta == 'b') {
        cout << "Hai risposto correttamente..\nChe fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/3 della tua vita.." << endl;
        applyDamage(toglivita, true);
    }

    Invio();

    clearScreen();
    scegliMenu();
    displayGoblinKing();
    linea();
    cout << "3. Quand’è che si iniziò a parlare di virus per la prima volta?" << endl;
    cout << "A. Prima della creazione dei computer" << endl;
    cout << "B. Dopo il primo virus chiamato “Creeper”(1971)" << endl;
    cout << "C. Si resero conto dell’esistenza dei virus dopo un decennio dalla creazione del primo computer (1941)" << endl;
    cout << "D. Dopo due settimane dalla creazione del computer si resero conto della possiblità di creare dei virus" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'B' || scelta == 'b') {
        cout << "Hai risposto correttamente..\nChe fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/3 della tua vita.." << endl;
        applyDamage(toglivita, true);
    }

    Invio();


    // Final screen after all questions
    clearScreen();
    scegliMenu();
    linea();
    cout << "Hai completato il livello 1, ti stai avvicinando al cuore dell'isola.." << endl;
    cout << "Hai ricevuto la chiave del goblin.." << endl;
    hasGoblinKey = true;

}
void combattimentoVampiro() {
    double toglivita = vita / 3.0;
    char scelta;

       clearScreen();
    scegliMenu();
    displayVampireBoss();
    linea();
    cout << "1. Chi fu la prima persona a programmare?" << endl;
    cout << "A. Bill Gates" << endl;
    cout << "B. Ada Byron" << endl;
    cout << "C. Alan Mathison Turing" << endl;
    cout << "D. Steve Jobs" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'B' || scelta == 'b') {
        cout << "Hai risposto correttamente..\nChe fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/3 della tua vita.." << endl;
        applyDamage(toglivita, true);
    }

    Invio();

        clearScreen();
    scegliMenu();
    displayVampireBoss();
    linea();
    cout << "2. Cosa si comprò con la prima transazione effettuata con i Bitcoin?" << endl;
    cout << "A. Un'isola nel sud America" << endl;
    cout << "B. Il creatore/i Sakashi Nakamoto comprò un paio di occhiali per testarne il funzionamento" << endl;
    cout << "C. Due pizze" << endl;
    cout << "D. Una macchina" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'C' || scelta == 'c') {
        cout << "Hai risposto correttamente..\nChe fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/3 della tua vita.." << endl;
        applyDamage(toglivita, true);
    }

    Invio();
        clearScreen();
    scegliMenu();
    displayVampireBoss();
    linea();
    cout << "3. Come si chiama il cervello del computer?" << endl;
    cout << "A. CPU" << endl;
    cout << "B. RAM" << endl;
    cout << "C. HDD / SSD" << endl;
    cout << "D. Scheda Madre" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'A' || scelta == 'a') {
        cout << "Hai risposto correttamente..\nChe fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/3 della tua vita.." << endl;
        applyDamage(toglivita, true);
    }

    Invio();

    clearScreen();
    scegliMenu();
    linea();
    cout << "Hai completato il livello 2! La tua avventura continua..." << endl;
    cout << "Hai ricevuto la chiave del vampiro.." << endl;
    hasVampireKey = true;
}
void combattimentoDrago(){
    double toglivita = vita / 3.0;
    char scelta;

        clearScreen();
    scegliMenu();
    displayDragon();
    linea();
    cout << "1. Qual è stato il primo “bug” informatico documentato?" << endl;
    cout << "A. Un errore di compilazione" << endl;
    cout << "B. Un virus" << endl;
    cout << "C. Una falena incastrata in un computer" << endl;
    cout << "D. Un corto circuito" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'C' || scelta == 'c') {
        cout << "Hai risposto correttamente..\nChe fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/3 della tua vita.." << endl;
        applyDamage(toglivita, true);
    }

    Invio();
        clearScreen();
    scegliMenu();
    displayDragon();
    linea();
    cout << "2. Cosa significa l’acronimo “Wi-Fi”?" << endl;
    cout << "A. Wireless Fidelity" << endl;
    cout << "B. Wide Fiber" << endl;
    cout << "C. Non significa nulla di tecnico preciso" << endl;
    cout << "D. Wireless File" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'C' || scelta == 'c') {
        cout << "Hai risposto correttamente..\nChe fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/3 della tua vita.." << endl;
        applyDamage(toglivita, true);
    }

    Invio();
        clearScreen();
    scegliMenu();
    displayDragon();
    linea();
    cout << "3. Perché il simbolo “@” si chiama “chiocciola” in italiano?" << endl;
    cout << "A. Perché rappresenta una spirale" << endl;
    cout << "B. Perché è stato inventato in Italia" << endl;
    cout << "C. Perché ricorda una lumaca" << endl;
    cout << "D. Perché indica lentezza" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'C' || scelta == 'c') {
        cout << "Hai risposto correttamente..\nChe fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/3 della tua vita.." << endl;
        applyDamage(toglivita, true);
    }

    Invio();


   

    clearScreen();
    scegliMenu();
    linea();
    cout << "Hai completato il livello 3! Il boss ti sta aspettando..." << endl;
    cout << "Hai ricevuto la chiave del drago.." << endl;
    hasDragonKey = true;
}
// Carica e salva impostazioni
void loadSettings() {
    ifstream in("impostazioni.txt"); //legge
    if (in) {
        string line;
        while (getline(in, line)) {
            size_t pos = line.find(" = ");
            if (pos != string::npos) { 
                string key = line.substr(0, pos);
                string value = line.substr(pos + 3); // Dopo " = "
                if (key == "playerName") playerName = value;
                else if (key == "difficulty") difficulty = value;
                else if (key == "infront") infront = value;
                else if (key == "sinistra") sinistra = value;
                else if (key == "destra") destra = value;
                else if (key == "indietro") indietro = value;
                else if (key == "pieta") pieta = value;
                else if (key == "scappare") scappare = value;
                else if (key == "attaccare") attaccare = value;
            }
        }
        in.close();
    }
}
void saveSettings() {
    ofstream out("impostazioni.txt"); //scrive
    out << "playerName = " << playerName << "\n";
    out << "difficulty = " << difficulty << "\n";
    out << "infront = " << infront << "\n";
    out << "sinistra = " << sinistra << "\n";
    out << "destra = " << destra << "\n";
    out << "indietro = " << indietro << "\n";
    out << "pieta = " << pieta << "\n";
    out << "scappare = " << scappare << "\n";
    out << "attaccare = " << attaccare << "\n";
    out.close();
}
//funzioni per menu inizialle
void showCredits() 
{
    clearScreen();
    printCreditsTitle();
    cout << "\033[35m";
    cout << "Benvenuto\n";
    cout << "\033[0m";
    cout << "\nQuesti sono i crediti.\n";

    cout << "\033[35m";
    cout << "\nVideogioco creato da:\n";
    cout << "\033[0m";
    cout << "\n- Elena Paduraru";
    cout << "\n- Luka Kolami";
    cout << "\n- Muhammad Farhan Nasir";
    cout << "\n- Maryam Bibi\n";

    cout << "\033[35m";
    cout << "\nSiti:";
    cout << "\033[0m\n ";
    cout << "\nImmagini Ascii: ";
    cout << "\033[34m";
    cout << "https://www.asciiart.eu/";
    cout << "\033[0m";
    cout << "\nScritte Ascii: ";
    cout << "\033[34m";
    cout << "https://patorjk.com/software/taag/\n";
    cout << "\033[0m";
    Invio();
}
void showSettings() {
    while(true) {

        clearScreen();
        printSettingsTitle();
        cout << "\n1. Nome giocatore: " << playerName << endl;
        cout << "2. Difficolta: " <<  difficulty << endl;
        cout << "3. Avanti: " <<  infront << endl;
        cout << "4. Sinistra: " <<  sinistra << endl;
        cout << "5. Destra: " <<  destra << endl;
        cout << "6. Indietro: " <<  indietro << endl;
        cout << "7. Pietá: " <<  pieta << endl;
        cout << "8. Scappare: " <<  scappare << endl;
        cout << "9. Attaccare: " <<  attaccare << endl;
        cout << "10. Salva " << endl;
        cout << "11. Esci" << endl;
        Input();

        int choice;
        cin >> choice;
        if(choice == 1) {
            cout << "Inserisci nome: ";
            cin.ignore();
            getline(cin, playerName);   
        } else if (choice == 2) {
            if (difficulty == "Facile") {
                difficulty = "Normale"; 
                cout << "Difficolta' impostata su: " << difficulty << endl;
                Invio();
            } else if (difficulty == "Normale") {
                difficulty = "Difficile";
                cout << "Difficolta' impostata su: " << difficulty << endl;
                Invio();
            } else {
                difficulty = "Facile";
                cout << "Difficolta' impostata su: " << difficulty << endl;
                Invio();
            }
        } else if (choice == 3) {
            cout << "Inserisci tasto da assegnare a 'Avanti': ";
            cin.ignore();
            getline(cin, infront);
        } else if (choice == 4) {
            cout << "Inserisci tasto da assegnare a 'Sinistra': ";
            cin.ignore();
            getline(cin, sinistra);
        }else if (choice == 5) {
            cout << "Inserisci tasto da assegnare a 'Destra': ";
            cin.ignore();
            getline(cin, destra);
        }else if (choice == 6) {
            cout << "Inserisci tasto da assegnare a 'Indiestro': ";
            cin.ignore();
            getline(cin, indietro);
        }else if (choice == 7) {
            cout << "Inserisci tasto da assegnare a 'Pietà': ";
            cin.ignore();
            getline(cin, pieta);
        }else if (choice == 8) {
            cout << "Inserisci tasto da assegnare a 'Scappare': ";
            cin.ignore();
            getline(cin, scappare);
        }else if (choice == 9) {
            cout << "Inserisci tasto da assegnare a 'Attaccare': ";
            cin.ignore();
            getline(cin, attaccare);
        } else if (choice == 10) {
            saveSettings();
            cout << "Impostazioni Salvate!\n";
            Invio();
        } else if (choice == 11) {
            break;
        }

    }  
}
// Gioco
void introduzioneGioco(){
    while (true) {
    clearScreen();
    printIntroductionTitle();
    cout << "\033[97;1m";
    cout << "Puoi muoverti facilmente nel mondo usanto i tasti: \n";
    cout << "\033[0m";
    cout << "\nCon il pulsante " << "\033[35m" << infront << "\033[0m" << " puoi andare avanti.\n";
    cout << "Con il pulsante " << "\033[35m" << sinistra << "\033[0m" << " puoi andare a sinistra.\n";
    cout << "Con il pulsante " << "\033[35m" << destra << "\033[0m" << " puoi andare a destra.\n";
    cout << "Con il pulsante " << "\033[35m" << indietro << "\033[0m" <<" puoi andare indietro.\n";
    Invio();
    
    clearScreen();
    printIntroductionTitle();
    cout << "\033[97;1m";
    cout << "Nel gioco ci sono fare cose che puoi fare: \n";
    cout << "\033[97;0m";
    cout << "\nCon il pulsante " << "\033[35m" << pieta << "\033[0m" << " puoi lacsiare un nemico vivere.\n";
    cout << "Con il pulsante " << "\033[35m" << scappare << "\033[0m" << " puoi scappare da una battaglia per curarti.\n";
    cout << "Con il pulsante " << "\033[35m" << attaccare << "\033[0m" <<" puoi attaccare un nemico.\n";
    Invio();

    clearScreen();
    printIntroductionTitle();
    cout << "\033[97;1m";
    cout << "Informazioni sul gioco\n";
    cout << "\033[97;0m";
    cout << "\nInizi con 5 cuori e puoi arrivare fino a 20.\n";
    cout << "I nemici fanno piu danno quando hai piu cuori.\n";
    cout << "L'inventario non ha limiti di spazio.\n";
    cout << "Ci sono 4 livelli: 3 con mostri e boss, e l'ultimo con il boss finale.\n";
    cout << "I boss possono dropare amuleti e danno sempre una chiave.\n";
    cout << "Puoi portare armi e pozioni di cura.\n";
    cout << "Le tue scelte influenzano il gioco.\n";
    cout << "\033[97;1m";
    cout << "\nDopo che premi INVIO. Iniziera il gioco reale...";
    cout << "\033[97;0m";
    Invio();


    clearScreen();
    displayIsola();
    linea();
    cout << "\nCiao, so che sei un po' stordito, sono successe un paio di cose che ti hanno portato su quest'isola. Ora ti racconto tutto.\n";
    Invio();

    clearScreen();
    displayBedroom();
    linea();
    cout << "\nTutto era iniziato nella tua camera mentre stavi guardando l'ultimo episodio di Twisted Metal/The Witcher (oppure mentre stavi leggendo 'Niente di nuovo sul fronte occidentale')";
    cout << ",intorno a te c'era un silenzio tombale.\n";
    cout << "All’improvviso un tonfo proveniente dalla finestra attirò la tua attenzione e provasti a capire da dove provenisse.\n";
    cout << "Pochi secondi dopo la finestra si frantumò e quattro figure irruppero in camera tua, nel tentaivo di scappare facesti un rumore e una delle figure ti stordì.\n";
    Invio();

    clearScreen();
    displayIsola();
    linea();
    cout << "\nQuando ti svegliasti eri sull'isola legato con i quattro ladri che stavano discutendo, in qualche modo riuscisti a slegarti e ti allontanasti da loro.\n";
    cout << "Per questo ti trovi qui.\n";
    Invio();
    break;
    }
    }
void livelloUno() {
    int contaAvanti = 0; // start from 0 so player actually moves forward
    const int NORMALE = 0;
    const int FORESTA = 1;
    const int MARE = 2;
    
    int stato = NORMALE;
    int ultimoEvento = -1;

    string choice;

    do {
        clearScreen();
        scegliMenu();
        displayIsola();
        linea();

        Input();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (stato == NORMALE) {  // stato di partenza
            
            if (choice == destra || choice == sinistra) {
                clearScreen();
                scegliMenu();
                displayForest();
                linea();
                cout << "Stai guardando la foresta fitta e oscura.\n";
                stato = FORESTA;
                Invio();
            }
            else if (choice == infront) {
                clearScreen();
                scegliMenu();
                displayTrail();
                linea();
                contaAvanti++;

                if (contaAvanti == 1) {
                    cout << "Ti stai incamminando lungo il sentiero.\n";
                    niente();
                } else if (contaAvanti == 2) {
                    apriChest();
                } else if (contaAvanti == 3) {
                    cout << "Un nemico selvatico appare davanti a te!\n";
                    Invio();
                    string mobs[3] = {"Cane", "Rana", "Scimmia"};
                    combattimento(1, nemiciUccisi, mobs);
                }
                else if (contaAvanti == 4) {
                    cout << "Hai raggiunto la tana del Goblin King!\n";
                    Invio();
                    combattimentoGoblinKing();
                    break; // stop the level loop here
                }
            }
            else if (choice == indietro) {
                if (contaAvanti > 4) {
                    contaAvanti--;
                    cout << "Torni indietro lungo il sentiero.\n";
                } else {
                    cout << "Sei già all'inizio dell'isola, non puoi tornare più indietro.\n";
                }
                Invio();
            }
        }

        else if (stato == MARE) {  // sinistra
            if (choice == infront) {
                clearScreen();
                scegliMenu();
                displaySea();
                linea();
                cout << "L'acqua è troppo profonda, è pericoloso andare avanti.\n";
                Invio();
            }
            else if (choice == destra || choice == sinistra) {
                clearScreen();
                scegliMenu();
                displayTrail();
                linea();
                cout << "Sei andato fuori strada, devi tornare indietro.\n";
                Invio();
            }
            else if (choice == indietro) {
                cout << "Torni sui tuoi passi.\n";
                stato = NORMALE;
                Invio();
            }
        }

        else if (stato == FORESTA) {  // destra
            if (choice == infront) {
                clearScreen();
                scegliMenu();
                displayForest();
                linea();
                cout << "La foresta è fitta e pericolosa, non sai cosa può nascondersi.\n";
                Invio();
            }
            else if (choice == destra || choice == sinistra) {
                clearScreen();
                scegliMenu();
                displayTrail();
                linea();
                cout << "Sei andato fuori strada, devi tornare indietro.\n";
                Invio();
            }
            else if (choice == indietro) {
                cout << "Torni sui tuoi passi.\n";
                stato = NORMALE;
                Invio();
            }
        }


    } while (contaAvanti <= 4);
}
void livelloDue() 
{
    int contaAvanti = 0;
    const int NORMALE = 0;
    const int FORESTA = 1;
    
    int stato = NORMALE;
    int ultimoEvento = -1;

    string choice;

    do {
        
        clearScreen();
        scegliMenu();
        displayIsola();
        linea();

        Input();
        cin >> choice;

        if (stato == NORMALE) {  // stato di partenza

            
            if (choice == destra || choice == sinistra) {
                clearScreen();
                scegliMenu();
                displayForest();
                linea();
                cout << "\nStai guardando la foresta fitta e oscura." << endl;
                stato = FORESTA;
                Invio();
            }
            else if (choice == infront) {
                clearScreen();
                scegliMenu();
                displayTrail();
                linea();
                contaAvanti++;

                if (contaAvanti == 1) {
                    cout << "Ti stai incamminando lungo il sentiero." << endl;
                    niente();
                }else if (contaAvanti == 2) {
                    apriChest();
                } else if (contaAvanti == 3) {
                            cout << "Un nemico selvatico appare davanti a te!" << endl;
                            Invio();
                            string mobs[3] = {"Pipistrello", "Farfalla", "Ragno"};
                            combattimento(2, nemiciUccisi, mobs);
                }
                else if (contaAvanti == 4) {
                    cout << "Sei arrivato alla fortezza del tuo nemico!!\nIl Re Vampiro!!" << endl;
                    Invio();
                    combattimentoVampiro(); 
                }
                else if (choice == indietro) 
                {
                    cout << "Torni indietro." << endl;
                    contaAvanti--;
                }
            }
        }


        else if (stato == FORESTA) // stato quando sta guardando la foresta ovvero destra o sinistra
        {  
            clearScreen();
            scegliMenu();
            displayForest();
            linea();
            cout << "Attenzione stai andando nella forsesta!!" << endl;
            cout << "Torna indietro!!" << endl;
            stato = NORMALE;
            Invio();

        }

        stato = NORMALE;


    } while (contaAvanti <= 4);

}
void livelloTre() 
{
    int contaAvanti = 0;
    const int NORMALE = 0;
    const int FORESTA = 1;
    
    int stato = NORMALE;
    int ultimoEvento = -1;

    string choice;

    clearScreen();
    scegliMenu();
    displayIsola();
    linea();
    cout << "Congraturazioni! Sei arrivato al 3 livello!";
    cout << "Stai attento e sempre in guardia.";
    Invio();

    do {
        
        clearScreen();
        scegliMenu();
        displayIsola();
        linea();

        Input();
        cin >> choice;

        if (stato == NORMALE) {  // stato di partenza

        
            if (choice == destra || choice == sinistra) {
                clearScreen();
                scegliMenu();
                displayForest();
                linea();
                cout << "\nStai guardando la foresta fitta e oscura." << endl;
                stato = FORESTA;
                Invio();
            }
            else if (choice == infront) {
                clearScreen();
                scegliMenu();
                displayTrail();
                linea();
                contaAvanti++;

                if (contaAvanti == 1) {
                    cout << "Ti stai incamminando lungo il sentiero.\n";
                    niente();
                } else if (contaAvanti == 2) {
                    apriChest();
                } else if (contaAvanti == 3) {
                        cout << "Un nemico selvatico appare davanti a te!" << endl;
                        Invio();

                        string mobs[3] = {"Centauro", "Mietitore", "Fenice"};
                        combattimento(3, nemiciUccisi, mobs);
                }
                else if (contaAvanti == 4) {
                    cout << "Sei arrivato alla fortezza del tuo nemico!!\nIl DRAGONE!!" << endl;
                    Invio();
                    combattimentoDrago();
                    break; // stop the level loop here
                }


                else if (choice == indietro) 
                {
                    cout << "Torni indietro." << endl;
                    Invio();
                    contaAvanti--;
                }
            }
        }


        else if (stato == FORESTA) // stato quando sta guardando la foresta ovvero destra
        {  
            clearScreen();
            scegliMenu();
            displayForest();linea();
            cout << "Attenzione stai andando nella forsesta!!" << endl;
            cout << "Torna indietro!!" << endl;
            stato = NORMALE;
            Invio();
        }


    } while (contaAvanti <= 15);

}
void boss() {
    double toglivita = vita/3.0;
    char scelta;

    clearScreen();
    scegliMenu();
    displayBoss();
    linea();
    cout << "\nSei arrivato alla vetta.. non sai cosa ti aspetta..\n";
    Invio();
    clearScreen();
    scegliMenu();
    displayBoss();
    linea();
    cout << "\nil-il tuo corpo si paralizza.. alla vista del boss finale.. e' il tuo migliore amico..\n";
    Invio();

    clearScreen();
    scegliMenu();
    displayCurse();
    linea();
    cout << "\033[41m";
    cout << "\nl'aura del tuo migliore amico.. ha distrutto il tuo totem e scudo..\n";
    cout << "\033[0m";
    cout << "Una grande battaglia ti aspetta..";
    hasShield = false;
    hasTotem = false;
    Invio();

    clearScreen();
    scegliMenu();
    displayBestfriend();
    linea();
    cout << "Stai combattendo il tuo migliore amico...\n";
    cout << "1. Qual è la funzione principale del 'kernel' in un sistema operativo?" << endl;
    cout << "A. Gestire l'allocazione delle risorse hardware e sincronizzare i flussi di dati attraverso la pipeline di I/O in tempo reale." << endl;
    cout << "B. Coordinare la comunicazione tra il software applicativo e l'hardware, gestendo le richieste di memoria e le interruzioni hardware." << endl;
    cout << "C. Esportare il controllo del processo di boot, monitorando la sicurezza delle risorse e intervenendo in caso di malfunzionamenti." << endl;
    cout << "D. Ottimizzare il processo di esecuzione dei thread a livello di ciclo di CPU, riducendo al minimo le latenze nella gestione delle risorse." << endl;
    Input();
    cin >> scelta;

    if (scelta == 'p') {
        cout << "Hai risposto correttamente..\nChe fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita);
    }

    Invio();
        
    clearScreen();
    scegliMenu();
    displayBestfriend();
    linea();
    cout << "Stai combattendo il tuo migliore amico...\n";
    cout << "2. Cos'è un 'deadlock' in un sistema operativo?" << endl;
    cout << "A. Un fenomeno che si verifica quando due o più processi entrano in uno stato di attesa infinita per risorse che non possono essere mai rilasciate." << endl;
    cout << "B. Una condizione in cui un processo fallisce nell'allocazione di risorse, ma continua ad eseguire senza errori visibili, influenzando altre risorse di sistema." << endl;
    cout << "C. Un loop di attesa che impedisce a un processo di completare l'esecuzione a causa di un conflitto tra il controllo delle risorse in memoria e la gestione degli accessi." << endl;
    cout << "D. Un conflitto tra il sistema di gestione dei file e la schedulazione dei processi, che porta a un blocco temporaneo di tutte le operazioni di I/O." << endl;
    Input();
    cin >> scelta;

    if (scelta == 'p') {
        cout << "Hai risposto correttamente..\nChe fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita);
    }

    Invio();

        clearScreen();
    scegliMenu();
    displayBestfriend();
    linea();
    cout << "Stai combattendo il tuo migliore amico...\n";
    cout << "3. Che cosa intende un sistema operativo con 'virtualizzazione della memoria'?" << endl;
    cout << "A. Una tecnica che consente di mappare porzioni della memoria fisica su uno spazio di indirizzamento logico, permettendo l'uso di più processi simultaneamente." << endl;
    cout << "B. Un processo che isola i dati di un processo dalla memoria fisica, creando una vista virtuale che simula la presenza di più dispositivi di memorizzazione." << endl;
    cout << "C. Una funzionalità che consente a un sistema operativo di gestire grandi blocchi di dati, spostando automaticamente informazioni tra la RAM e lo spazio di memoria secondario." << endl;
    cout << "D. Un meccanismo che separa i processi utilizzando un 'paginamento' dinamico delle risorse, per ottimizzare l’accesso alla memoria virtuale durante le operazioni intensive." << endl;
    Input();
    cin >> scelta;

    if (scelta == 'p') {
        cout << "Hai risposto correttamente..\nChe fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        vita = vita - toglivita;
    }

    Invio();


    clearScreen();
    scegliMenu();
    displayMain();
    linea(); 
    cout << "\nIl tuo corpo e' debole.. sai che stai morendo.. il tuo migliore amico sta ridendo.. ma qualcosa ti sta tenendo in vita..\n";
    cout << "La tua vita ti scorre davanti agli occhi.. i tuoi genitori.. la tua ragazza.. il tuo gatto.. i tuoi amici.. ti stanno aspettando\n";  
    cout << "Ma qualcosa si smuove.. il tuo corpo si rifiuta di morire.. sei pieno di adrenalina..\n";              
    Invio();
    clearScreen();
    scegliMenu();
    cout << "\033[32m";
    displayKeys();
    cout << "\033[0m\n";
    cout << "\033[35m";
    displayKeys();
    cout << "\033[0m\n";
    cout << "\033[91m";
    displayKeys();
    cout << "\033[0m\n";
    linea();
    cout << "Il tuo corpo.. si sta rigenerando con il potere delle chiavi.. ";
    cout << "Sei pronto... a combattare di nuovo.. ";
    vita = 100.0;
    hasDragonKey = false;
    hasGoblinKey = false;
    hasVampireKey = false;
    Invio();

    clearScreen();
    cout << "\033[33m";
    scegliMenu();
    cout << "\033[0m";
    displayBestfriend();
    linea();
    cout << "Hai avuto.. una battaglia lunga... e stancante.. ma alla fine con l'aiuto delle chiavi.. se riuscito a vincere..\n";
    cout << "Dopo la morte del tuo migliore amico.. tutto e' diventato oscuro..";

    Invio();
    clearScreen();
    cout << "\033[33m";
    scegliMenu();
    cout << "\033[0m";
    displayScuro();
    linea();
    cout << "Non sai cosa e' successo..";
    Invio();

    clearScreen();
    scegliMenu();
    displayPorta();
    linea();
    cout << "A un certo punto.. la tua vista viene coperta da una luce accecante..\n";
    cout << "Hai perso.. tutto.. ma c'e' una porta..\n";
    Invio();
        
    clearScreen();
    scegliMenu();
    displayPorta();
    linea();
    cout << "Pero' prima di entrare... ti chiedi... Perche'? Perche' il mio migliore amico mi ha tradito cosi'.. \n";
    cout << "La porta.. risponde.. Io lo so. \n";
    cout << playerName << ": Chi sei te? \n";
    cout << "porta: Io sono la porta, l'oggetto che ti sta parlando...";
    Invio();

    clearScreen();
    scegliMenu();
    displayPorta();
    linea();
    cout << endl << playerName << ": Te sai.. perche' il mio migliore amico mi ha tradito?..\n";
    cout << "porta: Si, la gelosia.\n";
    Invio();
    
    clearScreen();
    scegliMenu();
    displayPorta();
    linea();
    cout << playerName << ": la gelosia?..\n";
    cout << "porta: Si, il tuo migliore amico, era geloso dellla tua vita.\nLui voleva quello che te avevi, Chi non vuola una vita come la tua?\nTe vieni da una famiglia ricca, con genitori intelligenti e buoni\nUna ragazza bella, voti buoni, amici affidabili\nIl tuo migliore amico voleva la TUA vita, quindi per averla.. ha rovinato la tua... ";
    Invio();

    clearScreen();
    scegliMenu();
    displayPorta();
    linea();
    cout << playerName << ": .. E' io cosa faccio adesso..?\n";
    cout << "porta: Apri la porta.. trova la tua fine in base a quello che hai fatto...\n";
    cout << playerName << ": Cosa?\n";
    cout << "...la porta non risponde";
    Invio();

    clearScreen();
    scegliMenu();
    displayPorta();
    linea();
    cout << "Hai aperto la porta..";
    Invio();
    
    double percentualeUccisioni = 0.0;
    if (nemiciIncontrati > 0) {
    percentualeUccisioni = (double)contoNemiciUccisi / nemiciIncontrati * 100.0;
    }

    clearScreen();
    displayBedroom();

    cout << "\nIl tuo destino viene rivelato...\n";

    if (percentualeUccisioni <= 20.0) {
    cout << "\033[35mFinale Buono:\033[0m\n";
    cout << "Hai ucciso pochi nemici.. ti risvegli, e realizzi che era solo un sogno.\n";
    cout << "Ma le memorie di quella isola ti inseguiranno fino alla morte..";
    Invio();
    } else if (percentualeUccisioni >= 80.0) {
    cout << "\033[31mFinale Cattivo:\033[0m\n";
    cout << "Hai ucciso troppi nemici.. ti risvegli a 90 anni, condannato dai tuoi peccati.\n";
    cout << "Tutti le persone che amavi.. sono andate.. hai perso tutto. Che peccato..";
    Invio();
    } else {
    cout << "\033[33mFinale Neutro:\033[0m\n";
        cout << "Le tue scelte sono state miste.. ti risvegli da un coma dopo alcuni mesi.\n";
        cout << "La tua vita ritorna come prima..";
        Invio();
    }
}
//Main
int main() {
    loadSettings();
    #if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
    #endif
    srand(time(NULL));
    while (true) {
        clearScreen();
        printTitle();
        cout << "\n1. Gioca " << endl;
        cout << "2. Crediti " << endl;
        cout << "3. impostazioni" << endl;
        cout << "4. Esci" << endl; 
        Input();

        int choice;
        cin >> choice;
        if (choice == 1) {
            introduzioneGioco();
            livelloUno();
            livelloDue();
            livelloTre();
            boss();
        } else if (choice == 2) {
            showCredits();
        } else if (choice == 3) {
            showSettings();
        } else if (choice == 4) {
            clearScreen();
            cout << "Arrivederci, ritorna da noi amore <3" << endl;
            break;
        } else {
            cout << "Scelta non valida."; 
            Invio();
            cin.ignore();
            cin.get();
        }

    }
}
