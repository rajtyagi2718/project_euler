#include <iostream>
#include <bitset>
#include <cmath>
#include <vector>

using namespace std;

// What is the smallest positive number that is evenly divisible by all of the
// numbers from 1 to n for an integer n?

// 2; [3 5 7 9 ... sqrt(n)] sieve
// primes = [2] + sieve
// p**m || n
// result = product(pi**mi)

// sieve i 0 1 2 3  4  5  6
//       p 3 5 7 9 11 13 17
//       i = (p-1)/2 - 1
//       p = 2*(i+1) + 1

int numbits(long int n)
{
    int bits = 0;
    for (bits = 0; n != 0; ++bits) n >>= 1;
    return bits;
}

vector<int> get_primes(long int & n)
{
    vector<int> result;
    if (n < 2) return result;
    result.push_back(2);
    if (n == 2) return result;

    int stop = sqrt(n);
    stop = (stop % 2) ? stop/2 - 1 : stop/2;

    bitset<1000000> sieve; 
    sieve.set();
   
    unsigned long long int j;
    int k;
    for (int i = 0; i <= stop; ++i)
    {   if (!(sieve.test(i))) continue;

        j = 4*i*i + 6*i + 9;
        k = 2*i + 3;
        result.push_back(k);

        while (j <= stop)
        {   sieve.reset(j);
            j += k;
        }
    }

    return result;
}

int largest_factor(vector<int> & primes, long int & n)
{
    int result = 2;
    vector<int>::iterator it = primes.begin();
    while (n != 1 and it != primes.end())
    {   if (!(n % *it))
        {   result = *it;
            n /= *it;
        }
        else { ++it; }
    }
    return result;
}    

int main()
{
    long int n = 600851475143;
    cout << "number: " << n << endl;
    vector<int> primes;
    primes = get_primes(n);

    cout << "primes: ";
    for (int i = 0; i < primes.size(); ++i)
    {   cout << primes.at(i) << "...";
        i += 999;
    }
    cout << endl;

    cout << "largest prime factor: "
         << largest_factor(primes, n) << endl;
}

