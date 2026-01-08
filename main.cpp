#include <iostream>
#include <sstream>
#include <string>

#include "database.h"

int main() {
    std::string line;

    while (true) {
        std::cout << "> ";

        if (!std::getline(std::cin, line)) {
            break;
        }

        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;

        if (cmd == "set") {
            std::string key;
            std::string value;
            ss >> key >> value;

            if (key.empty() || value.empty()) {
                std::cout << "0\n";
                continue;
            }

            db_set(key.c_str(), value.c_str());
            std::cout << "1\n";
        }
        else if (cmd == "get") {
            std::string key;
            ss >> key;

            char buffer[1024];

            if (db_get(key.c_str(), buffer, sizeof(buffer))) {
                std::cout << buffer << "\n";
            } else {
                std::cout << "NULL\n";
            }
        }
        else if (cmd == "has") {
            std::string key;
            ss >> key;
            std::cout << (db_has(key.c_str()) ? "1\n" : "0\n");
        }
        else if (cmd == "del") {
            std::string key;
            ss >> key;
            db_del(key.c_str());
            std::cout << "1\n";
        }
        else if (cmd == "exit") {
            break;
        }
        else if (!cmd.empty()) {
            std::cout << "Comando invalido\n";
        }
    }

    return 0;
}
