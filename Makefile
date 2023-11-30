bin/all: testTableEntry.cpp testHashTable.cpp TableEntry.h HashTable.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp
	g++ -o bin/testHashTable testHashTable.cpp

clean:
	rm -r bin
