#include "database.h"

#include <unordered_map>
#include <string>
#include <cstring>

static std::unordered_map<std::string, std::string> db;

void db_set(const char* key, const char* value) {
    db[std::string(key)] = std::string(value);
}

void db_del(const char* key) {
    db.erase(std::string(key));
}

bool db_has(const char* key) {
    return db.find(std::string(key)) != db.end();
}

bool db_get(const char* key, char* value_out, size_t max_len) {
    auto it = db.find(std::string(key));
    if (it == db.end()) {
        return false;
    }

    std::strncpy(value_out, it->second.c_str(), max_len - 1);
    value_out[max_len - 1] = '\0';

    return true;
}

