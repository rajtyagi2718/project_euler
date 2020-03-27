#include <iostream>
#include <string>

using namespace std;

// A palindromic number reads the same both ways. The largest palindrome made 
// from the product of two 2-digit numbers is 9009 = 91 × 99.
 
// Find the largest palindrome made from the product of two 3-digit numbers.

bool is_palindrome(int nm)
{
    string s = to_string(nm);
    int len = s.length();

    for (int i = 0; i < len / 2; i++)
    {   if (s[i] != s[len-i-1]) return false;
    }
    
    return true;
}

int main()
{
    int result = 0, nm;
    for (int n = 999; n > 99; n--)
    {   if (!(n % 10)) continue;
        for (int m = 999; m >= n; m--)
        {   if (!(m % 10)) continue;
            nm = n * m;
            if (nm <= result) break;
            if (is_palindrome(nm)) 
            {   result = nm;
                break; 
            }
        }
    }
    cout << result << endl;
    return 0;
}
