#include <cassert>
#include <cstring>
#include <iostream>

#include "database.h"

int main() {
    char buffer[1024];

    // Teste: set + has
    db_set("user", "Alice");
    assert(db_has("user") == true);

    // Teste: get
    bool ok = db_get("user", buffer, sizeof(buffer));
    assert(ok == true);
    assert(std::strcmp(buffer, "Alice") == 0);

    // Teste: overwrite
    db_set("user", "Bob");
    ok = db_get("user", buffer, sizeof(buffer));
    assert(ok == true);
    assert(std::strcmp(buffer, "Bob") == 0);

    // Teste: del
    db_del("user");
    assert(db_has("user") == false);

    // Teste: get inexistente
    ok = db_get("user", buffer, sizeof(buffer));
    assert(ok == false);

    std::cout << "Todos os testes passaram com sucesso.\n";
    return 0;
}
