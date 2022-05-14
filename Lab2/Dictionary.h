#ifndef DICTIONARY_H
#define DICTIONARY_H

// In this lab you will implement a dictionary of strings (each string is null terminated, of max length 32 including the null)

// The hash code map should use a polynomial accumulation scheme as mentioned in the lecture video

// The compression map should use the Fibonacci hashing scheme as mentioned in the lecture video

// IMPORTANT: DO NOT compute the polynomial value at one go, it will overflow the integer limit. You need to compute 'k' in various stages, starting from the inner-most bracket (see slides), and in each step take mod 1. Note that mathematically [A*(alpha + beta * x)] mod 1 is the same as { [A*alpha] mod 1 + [A*beta*x] mod 1 } mod 1.

// You can use a fixed size of the array of a power of 2 (no need to grow)

// To resolve hash collisions, use the simple linear probing scheme (use the next unused slot in array), with NULL and TOMBSTONE markers as described in the lecture slides

// We will use the dictionary to count the frequency of words in a given text: you must define suitable fields in struct Entry for this purpose

// FILES
// Dictionary.cpp : implement the Dictionary class methods here
// main.cpp : write code here to read STDIN one word after another: cin>>str should do it (you can assume each word is at most 31 characters)
// During demo to TA: main.cpp should print hash value of each string and also relevant steps in findFreeIndex, also finally print frequency of each input word
// Extra/optional: write code to generate random strings, and show how well your hash+compression map is working

// You can change this array size if you want
#define ARRAY_SIZE (1<<6)


struct Entry{
    public:

    char* key;
    int freq;
    int state;
    Entry(char *k){
        key=k;
        freq=0;
        state=0;
    }
    Entry(){
      key=NULL;
      freq=0;
      state=0;
    }
};

class Dictionary {
 private:
  int N; // size of array A
   // Array of dictionary entries

  // Return the hash value (between 0 and N-1) of the given string; assume string is null terminated and of max length 32
  int hashValue(char *key);
  

  // Find the position where given key can be inserted (after resolving hash collision if any); return value between 0 and N-1 if free location present; return -1 if no free location
  int findFreeIndex(char *key);

public:
  struct Entry *A;
  Dictionary(); // Default constructor
 

  // Return the entry corresponding to given key, or NULL if the given key does not exist in the dictionary
  struct Entry *get(char *key);

  // Put the given entry in the appropriate location (using hashing) in the dictionary; return true if success, false if failure (array is full)
  bool put(struct Entry e);

  // Remove the given key; return true if success, false if failure (given key not present)
  bool remove(char *key);
};

#endif
