#include <iostream>
using namespace std;

// The sum of the squares of the first ten natural numbers is,
// 1^2+2^2+...+10^2=385
//
// The square of the sum of the first ten natural numbers is,
// (1+2+...+10)^2=55^2=3025
// 
// Hence the difference between the sum of the squares of the first ten natural // numbers and the square of the sum is 
// 3025−385=2640.
// 
// Find the difference between the sum of the squares of the 
// first one hundred natural numbers and the square of the sum.

int sumsquare (int n)
{
  int res;
  for (int i = 1; i <= n; ++i)
  { res += i*i;
  }
  return res;
}

int squaresum (int n)
{
  int sum = n*(n+1)/2;
  return sum*sum;
}

int main ()
{
  int n = 100;
  cout << "square of sums minus sum of squares from 1 to " << n << ": "
       << squaresum(n) - sumsquare(n) << endl;
  return 0;
}
