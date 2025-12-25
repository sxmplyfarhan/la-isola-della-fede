#pragma once
#include <utility>

int getch_compat();
void clearScreen();
std::pair<int,int> getTerminalSize();
void sleepMs(int ms);
