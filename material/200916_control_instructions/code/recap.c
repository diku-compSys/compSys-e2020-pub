
long sumOfTwoFirst (long *x) {
  long rval = (*x) * 7;
  x++;
  rval += (*x)*5;
  return rval;
}
