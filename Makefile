/*
all:
	g++ -std=c++17 main.cpp database.cpp -o kvdb
*/	
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

all: kvdb test_db

kvdb: main.cpp database.cpp
	$(CXX) $(CXXFLAGS) main.cpp database.cpp -o kvdb

test_db: teste_database.cpp database.cpp
	$(CXX) $(CXXFLAGS) teste_database.cpp database.cpp -o test_db

clean:
	rm -f kvdb test_db