#include <iostream>
#include <cmath>

using namespace std;

int sumIterative(int x, int n) {
  int sum = 0;
  int term = 1;
  for (int i = 0; i <= n; i++) {
    sum += term;
    term *= x;
  }
  return sum;
}

int formula(int x, int n) {
  if (x == 1) return n + 1;
  return (pow(x, n + 1) - 1) / (x - 1);
}

int main() {
  int x, n;
  cin >> x >> n;

  int r1 = sumIterative(x, n);
  int r2 = formula(x, n);

  if (r1 == r2) {
    cout << r1 << endl;
  }

  return 0;
}