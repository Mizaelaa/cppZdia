# Banco de Dados Chave/Valor em C++

Este projeto implementa um banco de dados simples chave/valor em memória,
desenvolvido em C++

## 📌 Funcionalidades

O banco de dados suporta os seguintes comandos:

- `set <chave> <valor>`  
  Armazena ou atualiza o valor associado à chave.

- `get <chave>`  
  Retorna o valor associado à chave.

- `has <chave>`  
  Retorna `1` se a chave existir ou `0` caso contrário.

- `del <chave>`  
  Remove a chave e seu valor do banco.

## 🖥️ Interface

O sistema utiliza uma interface de linha de comando (REPL),
lendo comandos via `stdin` e exibindo respostas via `stdout`.

Exemplo de uso:

```txt
> set user Alice
1
> get user
Alice
> has user
1
> del user
1
> has user
0
```

## 🧩 API Pública

O banco expõe as seguintes funções em C++:

```cpp
void db_set(const char* key, const char* value);
void db_del(const char* key);
bool db_has(const char* key);
bool db_get(const char* key, char* value_out, size_t max_len);
```

## 🛠️ Compilação

### Windows (MinGW)

#### Aplicação principal

```bash
g++ -std=c++17 main.cpp database.cpp -o kvdb
.\kvdb
```

### Linux / macOS
```bash
g++ -std=c++17 main.cpp database.cpp -o kvdb
./kvdb
```

#### Testes unitários

```bash
g++ -std=c++17 test_database.cpp database.cpp -o test_db
.\test_db
```

## ✅ Testes
O projeto possui testes unitários básicos utilizando assert,
cobrindo os principais comportamentos do banco de dados:

- Inserção
- Atualização
- Consulta
- Remoção


#### Desenvolvido por Miza como desafio técnico em C++
[Mizaela](https://github.com/Mizaelaa)  
