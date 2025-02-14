//**********************************************************
//* Program Name: Assignment #3 the Sieve of Eratosthenes  *
//* Description: Allow programmer to create a list of      *
//* prime numbers up to a maximum value which may or may   *
//* not be a prime number                                  *
//* Date: 02/09/2025                                       *
//* Author: Betty Phipps                                   *
//**********************************************************

#include "sieve.h"

//********************************************************
//* Program Name: Default constructor                    *
//* Description: Sets the last number for the            *
//* DEFAULTMAXPRIME/ Allocates the array bvect, and      *
//* calls GeneratePrimes.                                *
//* Date: 02/14/2025                                     *
//* Author: Betty Phipps                                 *
//********************************************************
Sieve::Sieve(){
    lastnumber = DEFAULTMAXPRIME;       // Set default max length
    bvect = new bool[lastnumber + 1];   // Allocated space for boolan array with max length
    GeneratePrimes();                   // Generate primes
 }

//********************************************************
//* Program Name: Deconstructor                          *
//* Description: Deletes the bvect array                 *
//* Date:  02/14/2025                                    *
//* Author: Betty Phipps                                 *
//********************************************************
Sieve::~Sieve(){
    delete[] bvect;                     // Free space
}

//********************************************************
//* Program Name: Constructors with Parameters           *
//* Description: Setting last number to prime with a     *
//* value of at least s unless it is below 2             *
//* Date: 02/14/2025                                     *
//* Author: Betty Phipps                                 *
//********************************************************
Sieve::Sieve(const int s){
    s >= 2 ? lastnumber = s : lastnumber = DEFAULTMAXPRIME;    // Checks is user value is at least 2, otherwise: back to default
    bvect = new bool[s + 1];
    GeneratePrimes();
}

// ********************************************************
//* Program Name: ReSet function                          *
//* Description: Deletes the bvect array and then sets    *
//* the lastnumber to s unless it is below 2.  If         *
//* below 2 sets it to DEFAULTMAXPRIME                    *
//* Date: 02/14/2025
//* Author: Betty Phipps
// *********************************************p***********
void Sieve::ReSet(const int s){
    delete[] bvect;
    s >= 2 ? lastnumber = s + 1: lastnumber = DEFAULTMAXPRIME;
    bvect = new bool[lastnumber + 1];
    GeneratePrimes();

    cout<<"Last number is "<<lastnumber<<endl;
}

// ********************************************************
//* Program Name: IsPrime function                        *
//* Description: Returns true if the number pass in       *
//* by s is a prime number, otherwise returns false       *
//* Date: 02/14/2025      
//* Author: Betty Phipps
// ********************************************************
bool Sieve::IsPrime(const int s){
    if (s <= 1){                        // 1 or less is not prime
        return false;
    } else if (s == 2) {                // 2 is a prime
        return true;
    } else if (s % 2 == 0) {                 // Divisable by 2 is not prime
        return false;
    }

    for (int i = 3; i * i <=s; i += 2){                              // from 3 to sqrt, only odd numbers
        if (s % i == 0){
            return false;
        }
    }
    return true;                        // No divisors found, prime
}

// ********************************************************
//* Program Name: Print function                          *
//* Description: Prints out all numbers from 2 to         *
//* the lastnumber that are prime.  Pass in the           *
//* ostream value such as cout .                          *
//* Print all prime numbers up to the lastnumber          *
//* Date: 02/14/2025
//* Author: Betty Phipps
// ********************************************************
void Sieve::Print(ostream & os){
    GeneratePrimes();

    cout<<"Last number in Print is "<<lastnumber<<endl;
    for (int i = 2; i <= lastnumber; i++){       //printing numbers from bvect that are already prime
        if (bvect[i]){
            os<<i<<" Is Prime"<<endl;
        }
    }
 }

// ********************************************************
//* Program Name: GeneratePrimes function                 *
//* Description: Uses the Sieve of Eratosthenes to        *
//* generate a list of prime numbers.                     *
//* Date: 02/14/2025                                      *
//* Author: Betty Phipps                                  *
// ********************************************************
void Sieve::GeneratePrimes(){
    for (int i = 0; i <= lastnumber; i++){      //initalize array : true means prime initially
            bvect[i] = true;
    }

    bvect[0] = bvect[1] = false;                // 0 and 1 are not primes

    for (int i = 2; i <= lastnumber; i++){  //Sieve: marks multiples of each prime
        if (bvect[i]){    //i is prime
            for (int j = i * i; j  <= lastnumber; j += i){
                bvect[j] = false;
            }
        }
    }
}

// ********************************************************
//* Program Name: Operator overload                       *
//* Description: Calls the Print member function.         *
//* Non-class member function.                            *
//* Date: 02/14/2025                                      *
//* Author: Betty Phipps                                  *
// ********************************************************
ostream & operator <<(ostream & os, Sieve & s){
    s.Print(os);            
    return os;
 }