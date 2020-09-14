long plus(long x, long y) {
    return x+y;
}

long arith (long x, long y, long z) {
  long t1 = x+y;
  long t2 = z+t1;
  long t3 = x+4;
  long t4 = y * 48;
  long t5 = t3 + t4;
  long rval = t2 * t5;
  return rval;
}

long m12(long x) {
    return 12*x;
}

long scale(long x, long y, long z) {
  return x + 8*y + 4;
}
