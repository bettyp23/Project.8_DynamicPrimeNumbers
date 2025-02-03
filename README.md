# Project.8_SieveofEratosthenes - Prime Number Generator
Implementing a dynamic array and using constructors  as well as destructors to determine the prime numbers up to a maximum range.
## Overview

This project involves implementing a dynamic array and using constructors and destructors to determine prime numbers up to a maximum range. The `Sieve` class generates a list of prime numbers and provides functionality to check if a given number is prime, reset the highest prime number, and print the list of prime numbers. Additionally, the project includes operator overloading for the `<<` operator to print the list of prime numbers.

## Project Functional Requirements

The `Sieve` class will allow the programmer to:
1. Create a list of prime numbers up to a specified maximum value.
2. Check if a given number within the range is a prime number.
3. Print the list of prime numbers.
4. Reset the highest number and generate a new list based on the updated value.
5. Overload the `<<` operator to print the list of primes to standard output.

### Educational Objectives
By completing this assignment, the student will:
- Implement a class from a class definition.
- Implement the `Sieve` class with necessary member functions.
- Correctly separate class definition and implementation using different files.
- Create executable files using makefiles and the Unix `make` utility.
- Test the class using pre-defined tests and platforms.
- Overload the `<<` operator for custom output.

## Files Included
- `sieve.cpp`: Contains the implementation of the `Sieve` class and its member functions.
- `sieve.h`: Contains the class definition for `Sieve`, including function declarations and member variables.
- `makefile`: Used for compiling the program and generating the executable.
- `SieveMain.cpp`: A sample main program to test the `Sieve` class.

## Class Description: `Sieve`
The `Sieve` class manages a list of prime numbers and includes the following methods:
- **Constructors**:
  - `Sieve()`: Default constructor that sets the last prime number to `DEFAULTMAXPRIME`.
  - `Sieve(const int s)`: Constructor that initializes the sieve up to a specified prime number (if valid).
  - `~Sieve()`: Destructor that deletes the prime number array.
- **Member Functions**:
  - `ReSet(const int s)`: Resets the sieve to calculate primes up to a new maximum value.
  - `IsPrime(const int s)`: Checks if a number is prime.
  - `Print(ostream & os)`: Prints all prime numbers up to the current highest number.
  - `GeneratePrimes()`: Generates prime numbers using the Sieve of Eratosthenes algorithm.
- **Operator Overloading**:
  - `operator <<`: Allows printing the list of primes directly using the `<<` operator.

## How to Use

1. Compile the program using the provided `makefile`:
   ```bash
   make
