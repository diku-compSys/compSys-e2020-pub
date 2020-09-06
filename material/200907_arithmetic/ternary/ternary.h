#include <stdlib.h>

typedef struct ternary {
  unsigned long val;
} ternary;

/**
 * Converts a two-complement unsigned long to a BCD number
 **/
ternary toTernary(unsigned long i);

/**
 * Converts a 
 **/
unsigned long fromTernary(ternary b);


/**
 * Adds two values of bcd representation a and b, and returns the result.
 **/
ternary addTernary(ternary a, ternary b);
