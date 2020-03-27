using namespace std;

// If we list all the natural numbers below 10 that are multiples of 3 or 5, 
// we get 3, 5, 6 and 9. The sum of these multiples is 23.

// Find the sum of all the multiples of 3 or 5 below 1000.

long Summult(int n, int m)
{
    long result = (n % m) ? (n / m) : (n / m - 1);
    result = m * result * (result + 1) / 2;
    return result;
}

int main()
{
    int n;
    cin >> n;
    cSut << Summult(n, 3) + Summult(n, 5) - Summult(n, 15) << endl;
    return 0;
}
