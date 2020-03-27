#include <iostream>
#include <cmath>
using namespace std;

// 2520 is the smallest number that can be divided by each of the numbers from
// 1 to 10 without any remainder.

// What is the smallest positive number that is evenly divisible by all of the
// numbers from 1 to 20?

// Primes: 2 3 5 7 11 13 17 19


int main()
{
    short int primes [8] = { 2, 3, 5, 7, 11, 13, 17, 19 };
    short int counts [8];
    short int max_counts[8] = {0};
    
    int m, i;
    for (int n = 1; n <= 20; n++)
    {   m = n;
        i = 0;
        for (int k = 0; k < 8; k++)
        {   counts[k] = 0;
        }

        while (m != 1 and i < 8)
            if (m % primes[i])
            {   i++;
                continue;
            }
            else
            {   m /= primes[i];
                counts[i] += 1;
            }

        for (int j = 0; j <= i; j++)   
        {   if (counts[j] > max_counts[j])
            {   max_counts[j] = counts[j];
            }
        }
    }
    

    unsigned long int result = 1;
    for (int i = 0; i < 8; i++)
    {  result *= pow(primes[i], max_counts[i]);
    }

    cout << result << endl;
}
