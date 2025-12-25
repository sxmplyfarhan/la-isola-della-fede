#pragma once
#include <string>
#include <map>

class Settings {
public:
    Settings(const std::string &file = "settings.txt");

    void load();
    void save();
    bool hasUnsavedChanges();

    void set(const std::string &key, const std::string &value);
    std::string get(const std::string &key, const std::string &defaultVal = "");

    void showMenu();

private:
    bool confirmExit();

    std::string filename;
    std::map<std::string, std::string> settings;
    std::map<std::string, std::string> savedState;
};
