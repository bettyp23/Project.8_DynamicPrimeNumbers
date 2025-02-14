# makefile for sieve assignment
# Betty Phipps
# Date: 02/14/2024
# make -> ./sieve

# Name of executable
sieve: main.o sieve.o
	g++ $(CXXFLAGS) main.o sieve.o -o sieve

# Compile main.cpp into main.o
main.o: main.cpp sieve.h
	g++ $(CXXFLAGS) -c main.cpp

# Compile sieve.cpp into sieve.o
sieve.o: sieve.cpp sieve.h
	g++ $(CXXFLAGS) -c sieve.cpp

# Clean up object files and the executable
clean:
	rm -rf *.o sieve

CXXFLAGS = -std=c++11
