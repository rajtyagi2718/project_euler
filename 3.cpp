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


vector<int> get_primes(long int & n)
{
    vector<int> primes;
    if (n < 2) return primes;
    primes.push_back(2);
    if (n == 2) return primes;

    int istop = sqrt(n);
    istop = (istop % 2) ? istop/2 - 1 : istop/2;

    bitset<1000000> sieve; 
    sieve.set();
   
    int i, j, p;
    int jstop = (sqrt(2*(istop+1)+1)-3) / 2;
    for (i = 0; i <= jstop; ++i)
    {   if (!(sieve.test(i))) continue;

        p = 2*i + 3;
        primes.push_back(p);

        j = 2*i*i + 3*i + 3;
        if (j > istop) {cout << "***WARNING: jstop fail. prime: " << p << endl;}
        for (j; j <= istop; j += p)
        {   sieve.reset(j);
            j += p;
        }
    }

    for (i; i <= istop; ++i)
    {   if (sieve.test(i))
        {   p = 2*i + 3;
            primes.push_back(p);
        }
    }

    return primes;
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

