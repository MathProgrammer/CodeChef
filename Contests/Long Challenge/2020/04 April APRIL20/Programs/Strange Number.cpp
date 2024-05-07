#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int divisors, prime_divisors;
    scanf("%d %d", &divisors, &prime_divisors);
    
    int no_of_factors = 0;
    for(int i = 2; i*1LL*i <= divisors; i++)
    {
        if(divisors%i == 0)
        {
            while(divisors%i == 0)
            {
                no_of_factors++;
                divisors /= i;
            }
        }
    }
    
    if(divisors > 1)
    {
        no_of_factors++;
    }
    
    printf(no_of_factors >= prime_divisors ? "1\n" : "0\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
