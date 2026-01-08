#ifndef DATABASE_H
#define DATABASE_H

#include <cstddef> // size_t

void db_set(const char* key, const char* value);
void db_del(const char* key);
bool db_has(const char* key);
bool db_get(const char* key, char* value_out, size_t max_len);

#endif

