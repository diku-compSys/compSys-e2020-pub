// Calculated five times the sum of a `0` terminated list of `long`s using pointer arithmetic

long plus(long *a) {
  long sum = 0;
  long tmp = *a;
  while (tmp != 0) {
    sum += 5*tmp;
    a++;
    tmp = *a;
  }
  return sum;
}
