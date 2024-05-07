#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX_N = 1e6; 
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
        
        for(int j = 0; j < primes.size() && i*1LL*primes[j] < MAX_N; j++)
        {
            is_prime[i*primes[j]] = false;
            
            if(i%primes[j] == 0)
            {
                break;
            }
        }
    }
}

void factorise(long long n, map <long long, int> &exponent)
{
    for(int i = 0; i < primes.size() && primes[i]*1LL*primes[i] <= n; i++)
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

long long no_of_factors(map <long long, int> &exponent)
{
    long long answer = 1; 
    for(auto it = exponent.begin(); it != exponent.end(); it++)
    {
        answer *= (it->second + 1);
    }
    
    return answer;
}

long long get_divisor_n_multiple_k(long long n, long long k, map <long long, int> &factors_n, map <long long, int> &common_factors)
{
    if(n < k || n%k != 0)
    {
        return 0;
    }
    
    long long answer = 1;
    for(auto it = factors_n.begin(); it != factors_n.end(); it++)
    {
        long long factor = it->first;
        int extra_exponent = (factors_n[factor] - common_factors[factor]);
        answer *= (1 + extra_exponent);
    }
    
    return answer;
}

int get_exponent(long long n, long long p)
{
    int exponent = 0;
    while(n%p == 0)
    {
        exponent++;
        n /= p;
    }
    
    return exponent;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	sieve();
	
	long long n; 
	int no_of_queries; 
	cin >> n >> no_of_queries;
	
	map <long long, int> factors_n; 
	factorise(n, factors_n);
	
	for(int i = 1; i <= no_of_queries; i++)
	{
	    const int COMMON_DIVISOR = 1, DIVISOR_N_MULTIPLE_K = 2, DIVISOR_N_NON_MULTIPLE_K = 3;
	    int query;
	    long long k;
	    cin >> query >> k; 
	    
	    map <long long, int> common_factors; 
	    for(auto it = factors_n.begin(); it != factors_n.end(); it++)
	    {
	        common_factors[it->first] = min(it->second, get_exponent(k, it->first));
	    }
	    
	    long long answer = 0;
	    switch(query)
	    {
	        case COMMON_DIVISOR: 
	        {
	            answer = no_of_factors(common_factors);
	            break;
	        }
	        
	        case DIVISOR_N_MULTIPLE_K: 
	        {
	            answer = get_divisor_n_multiple_k(n, k, factors_n, common_factors);
	            break;
	        }
	        
	        case DIVISOR_N_NON_MULTIPLE_K: 
	        {
	            long long divisors_n = no_of_factors(factors_n);
	            long long divisors_n_multiple_k = get_divisor_n_multiple_k(n, k, factors_n, common_factors);
	            
	            answer = divisors_n - divisors_n_multiple_k;
	            break;
	        }
	    }
	    
	    cout << answer << "\n";
	}
	
	return 0;
}
