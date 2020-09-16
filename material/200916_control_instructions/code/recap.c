

// x is an array of long
// i is an index into the array

long weightedSumOfTwo (long *x, unsigned i) {
  long rval = (*x) * 7;
  x += i;
  rval += (*x)*5;
  return rval;
}
