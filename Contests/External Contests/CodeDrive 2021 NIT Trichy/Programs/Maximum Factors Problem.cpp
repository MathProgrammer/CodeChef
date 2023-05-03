#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAX_N = 1e5 + 5; 
vector <int> primes; 
void sieve()
{
    vector <int> is_prime(MAX_N, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < MAX_N; i++)
    {
        if(is_prime[i])
        {
            primes.push_back(i);
        }
        
        for(int j = 0; j < primes.size() && i*primes[j] < MAX_N; j++)
        {
            is_prime[i*primes[j]] = false;
            
            if(i%primes[j] == 0)
            {
                break;
            }
        }
    }
}

void factorize(int n, map <int, int> &exponent)
{
    for(int i = 0; i < primes.size() && primes[i]*primes[i] <= n; i++)
    {
        while(n%primes[i] == 0)
        {
            exponent[primes[i]]++;
            n /= primes[i];
        }
    }
    
    if(n > 1)
    {
        exponent[n] = 1;
    }
}

void solve()
{
    int n; 
    cin >> n; 
    map <int, int> exponent;
    factorize(n, exponent);
    
    int prime_with_largest_exponent = 0;
    for(auto it = exponent.begin(); it != exponent.end(); it++)
    {
        if(it->second > exponent[prime_with_largest_exponent])
        {
            prime_with_largest_exponent = it->first;
        }
    }
    
    cout << prime_with_largest_exponent << "\n";
}

int main() 
{
	sieve();
	
	int no_of_test_cases; 
	cin >> no_of_test_cases;
	
	while(no_of_test_cases--)
	    solve();
	    
	return 0;
}
