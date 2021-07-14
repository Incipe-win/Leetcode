#include <iostream>

double mypow(double x, int n) {
  double ans = 1;
  while (n) {
    if (n & 1) {
      ans *= x;
    }
    x *= x;
    n >>= 1;
  }
  return ans;
}