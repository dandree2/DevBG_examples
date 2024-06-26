#include <iostream>
#include <chrono>
#include <optional>
#include <string_view>
#include <thread>

using namespace std;
using namespace std::literals::chrono_literals;

struct Settings {
    Settings(string_view fileName) {
        cout << "Loading settings: " << fileName << endl;
    }
    ~Settings() {
        cout << "Removing settings" << endl;
    }

    void setSetting(string_view setting,
                    string_view value) {
        cout << "Set setting: " << setting 
             << " to: " << value << endl;
    }
};

struct Config {
    optional<Settings> settings{};
    Config() {
        cout << "Config created..." << endl;
    }

    void changeSetting(string_view setting, 
                       string_view value) {
        if (!settings)
            settings.emplace("default_settings");
        settings->setSetting(setting, value);
    }
};

int main() {
    Config cfg;
    cout << "Application startup..." << endl;
    this_thread::sleep_for(5s);
    cfg.changeSetting("Drive mode", "Sport");
    this_thread::sleep_for(2s);
    cfg.changeSetting("Gear label", "PRNDL");

    return 0;
}
