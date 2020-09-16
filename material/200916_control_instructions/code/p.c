long power(long n, long p) {
  long res;
  if (p == 1) {
    res = 1;
  }
  else {
    res = power(n, p-1);
  }
  res = res * n;
  return res;
}
